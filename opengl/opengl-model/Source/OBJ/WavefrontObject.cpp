#include "WavefrontObject.hpp"

WavefrontObjFile::WavefrontObjFile() {}

Result WavefrontObjFile::load(const String& objFileContent)
{
    shapes.clear();
    return parseObjFile(StringArray::fromLines(objFileContent));
}

Result WavefrontObjFile::load(const File& file)
{
    sourceFile = file;
    return load(file.loadFileAsString());
}

// PRIVATE

float WavefrontObjFile::parseFloat(String::CharPointerType& t)
{
    t = t.findEndOfWhitespace();
    return (float)CharacterFunctions::readDoubleValue(t);
}

WavefrontObjFile::Vertex WavefrontObjFile::parseVertex(String::CharPointerType t)
{
    WavefrontObjFile::Vertex v;
    v.x = parseFloat(t);
    v.y = parseFloat(t);
    v.z = parseFloat(t);
    return v;
}

WavefrontObjFile::TextureCoord WavefrontObjFile::parseTextureCoord(String::CharPointerType t)
{
    TextureCoord tc;
    tc.x = parseFloat(t);
    tc.y = parseFloat(t);
    return tc;
}

bool WavefrontObjFile::matchToken(String::CharPointerType& t, const char* token)
{
    auto len = (int)strlen(token);

    if (CharacterFunctions::compareUpTo(CharPointer_ASCII(token), t, len) == 0)
    {
        auto end = t + len;

        if (end.isEmpty() || end.isWhitespace())
        {
            t = end.findEndOfWhitespace();
            return true;
        }
    }

    return false;
}

WavefrontObjFile::Shape* WavefrontObjFile::parseFaceGroup(const Mesh& srcMesh, Array<Face>& faceGroup,
                                                          const Material& material,
                                                          const String& name)
{
    if (faceGroup.size() == 0) return nullptr;

    std::unique_ptr<Shape> shape(new Shape());
    shape->name     = name;
    shape->material = material;

    IndexMap indexMap;

    for (auto& f : faceGroup) f.addIndices(shape->mesh, srcMesh, indexMap);

    return shape.release();
}

Result WavefrontObjFile::parseObjFile(const StringArray& lines)
{
    Mesh mesh;
    Array<Face> faceGroup;

    Array<Material> knownMaterials;
    Material lastMaterial;
    String lastName;

    for (auto lineNum = 0; lineNum < lines.size(); ++lineNum)
    {
        auto l = lines[lineNum].getCharPointer().findEndOfWhitespace();

        if (matchToken(l, "v"))
        {
            mesh.vertices.add(parseVertex(l));
            continue;
        }
        if (matchToken(l, "vn"))
        {
            mesh.normals.add(parseVertex(l));
            continue;
        }
        if (matchToken(l, "vt"))
        {
            mesh.textureCoords.add(parseTextureCoord(l));
            continue;
        }
        if (matchToken(l, "f"))
        {
            faceGroup.add(Face(l));
            continue;
        }

        if (matchToken(l, "usemtl"))
        {
            auto name = String(l).trim();

            for (auto i = knownMaterials.size(); --i >= 0;)
            {
                if (knownMaterials.getReference(i).name == name)
                {
                    lastMaterial = knownMaterials.getReference(i);
                    break;
                }
            }

            continue;
        }

        if (matchToken(l, "mtllib"))
        {
            Result r = parseMaterial(knownMaterials, String(l).trim());
            continue;
        }

        if (matchToken(l, "g") || matchToken(l, "o"))
        {
            if (Shape* shape = parseFaceGroup(mesh, faceGroup, lastMaterial, lastName))
                shapes.add(shape);

            faceGroup.clear();
            lastName = StringArray::fromTokens(l, " \t", "")[0];
            continue;
        }
    }

    if (auto* shape = parseFaceGroup(mesh, faceGroup, lastMaterial, lastName)) shapes.add(shape);

    return Result::ok();
}

Result WavefrontObjFile::parseMaterial(Array<WavefrontObjFile::Material>& materials,
                                       const String& filename)
{
    jassert(sourceFile.exists());
    auto f = sourceFile.getSiblingFile(filename);

    if (!f.exists()) return Result::fail("Cannot open file: " + filename);

    auto lines = StringArray::fromLines(f.loadFileAsString());

    materials.clear();
    WavefrontObjFile::Material material;

    for (auto line : lines)
    {
        auto l = line.getCharPointer().findEndOfWhitespace();

        if (matchToken(l, "newmtl"))
        {
            materials.add(material);
            material.name = String(l).trim();
            continue;
        }

        if (matchToken(l, "Ka"))
        {
            material.ambient = parseVertex(l);
            continue;
        }
        if (matchToken(l, "Kd"))
        {
            material.diffuse = parseVertex(l);
            continue;
        }
        if (matchToken(l, "Ks"))
        {
            material.specular = parseVertex(l);
            continue;
        }
        if (matchToken(l, "Kt"))
        {
            material.transmittance = parseVertex(l);
            continue;
        }
        if (matchToken(l, "Ke"))
        {
            material.emission = parseVertex(l);
            continue;
        }
        if (matchToken(l, "Ni"))
        {
            material.refractiveIndex = parseFloat(l);
            continue;
        }
        if (matchToken(l, "Ns"))
        {
            material.shininess = parseFloat(l);
            continue;
        }

        if (matchToken(l, "map_Ka"))
        {
            material.ambientTextureName = String(l).trim();
            continue;
        }
        if (matchToken(l, "map_Kd"))
        {
            material.diffuseTextureName = String(l).trim();
            continue;
        }
        if (matchToken(l, "map_Ks"))
        {
            material.specularTextureName = String(l).trim();
            continue;
        }
        if (matchToken(l, "map_Ns"))
        {
            material.normalTextureName = String(l).trim();
            continue;
        }

        auto tokens = StringArray::fromTokens(l, " \t", "");

        if (tokens.size() >= 2) material.parameters.set(tokens[0].trim(), tokens[1].trim());
    }

    materials.add(material);
    return Result::ok();
}

WavefrontObjFile::Index WavefrontObjFile::IndexMap::getIndexFor(TripleIndex i, Mesh& newMesh,
                                                                const Mesh& srcMesh)
{
    const std::map<TripleIndex, Index>::iterator it(map.find(i));

    if (it != map.end()) return it->second;

    auto index = (Index)newMesh.vertices.size();

    if (isPositiveAndBelow(i.vertexIndex, srcMesh.vertices.size()))
        newMesh.vertices.add(srcMesh.vertices.getReference(i.vertexIndex));

    if (isPositiveAndBelow(i.normalIndex, srcMesh.normals.size()))
        newMesh.normals.add(srcMesh.normals.getReference(i.normalIndex));

    if (isPositiveAndBelow(i.textureIndex, srcMesh.textureCoords.size()))
        newMesh.textureCoords.add(srcMesh.textureCoords.getReference(i.textureIndex));

    map[i] = index;
    return index;
}