#pragma once

#include <map>

#include "../core/common.hpp"


//==============================================================================
/**
    This is a quick-and-dirty parser for the 3D OBJ file format.

    Just call load() and if there aren't any errors, the 'shapes' array should
    be filled with all the shape objects that were loaded from the file.
*/
class WavefrontObjFile
{
public:
    // TYPES
    using Index = juce::uint32;

    struct Vertex
    {
        float x, y, z;
    };
    struct TextureCoord
    {
        float x, y;
    };

    struct Mesh
    {
        Array<Vertex> vertices, normals;
        Array<TextureCoord> textureCoords;
        Array<Index> indices;
    };

    struct Material
    {
        Material() noexcept
        {
            zerostruct(ambient);
            zerostruct(diffuse);
            zerostruct(specular);
            zerostruct(transmittance);
            zerostruct(emission);
        }

        String name;

        Vertex ambient, diffuse, specular, transmittance, emission;
        float shininess = 1.0f, refractiveIndex = 0.0f;

        String ambientTextureName, diffuseTextureName, specularTextureName, normalTextureName;

        StringPairArray parameters;
    };

    struct Shape
    {
        String name;
        Mesh mesh;
        Material material;
    };

public:
    // Functions
    WavefrontObjFile();

    Result load(const String& objFileContent);
    Result load(const File& file);

public:
    // Data
    OwnedArray<Shape> shapes;

private:
    // Data
    File sourceFile;

    struct TripleIndex
    {
        TripleIndex() noexcept {};

        bool operator<(const TripleIndex& other) const noexcept
        {
            if (this == &other) return false;

            if (vertexIndex != other.vertexIndex) return vertexIndex < other.vertexIndex;

            if (textureIndex != other.textureIndex) return textureIndex < other.textureIndex;

            return normalIndex < other.normalIndex;
        }

        int vertexIndex = -1, textureIndex = -1, normalIndex = -1;
    };

    struct IndexMap
    {
        std::map<TripleIndex, Index> map;

        Index getIndexFor(TripleIndex i, Mesh& newMesh, const Mesh& srcMesh);
    };

    static float parseFloat(String::CharPointerType& t);

    static Vertex parseVertex(String::CharPointerType t);

    static TextureCoord parseTextureCoord(String::CharPointerType t);

    static bool matchToken(String::CharPointerType& t, const char* token);

    struct Face
    {
        Face(String::CharPointerType t)
        {
            while (!t.isEmpty()) triples.add(parseTriple(t));
        }

        Array<TripleIndex> triples;

        void addIndices(Mesh& newMesh, const Mesh& srcMesh, IndexMap& indexMap)
        {
            TripleIndex i0(triples[0]), i1, i2(triples[1]);

            for (auto i = 2; i < triples.size(); ++i)
            {
                i1 = i2;
                i2 = triples.getReference(i);

                newMesh.indices.add(indexMap.getIndexFor(i0, newMesh, srcMesh));
                newMesh.indices.add(indexMap.getIndexFor(i1, newMesh, srcMesh));
                newMesh.indices.add(indexMap.getIndexFor(i2, newMesh, srcMesh));
            }
        }

        static TripleIndex parseTriple(String::CharPointerType& t)
        {
            TripleIndex i;

            t             = t.findEndOfWhitespace();
            i.vertexIndex = t.getIntValue32() - 1;
            t             = findEndOfFaceToken(t);

            if (t.isEmpty() || t.getAndAdvance() != '/') return i;

            if (*t == '/')
            {
                ++t;
            }
            else
            {
                i.textureIndex = t.getIntValue32() - 1;
                t              = findEndOfFaceToken(t);

                if (t.isEmpty() || t.getAndAdvance() != '/') return i;
            }

            i.normalIndex = t.getIntValue32() - 1;
            t             = findEndOfFaceToken(t);
            return i;
        }

        static String::CharPointerType findEndOfFaceToken(String::CharPointerType t) noexcept
        {
            return CharacterFunctions::findEndOfToken(t, CharPointer_ASCII("/ \t"), String().getCharPointer());
        }
    };

    static Shape* parseFaceGroup(const Mesh& srcMesh, Array<Face>& faceGroup, const Material& material,
                                 const String& name);

    Result parseObjFile(const StringArray& lines);

    Result parseMaterial(Array<Material>& materials, const String& filename);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WavefrontObjFile)
};