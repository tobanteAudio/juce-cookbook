#pragma once

#include "core/common.hpp"
#include "opengl/attributes.hpp"
#include "wavefront_object.hpp"

/**
 * @brief This loads a 3D model #include "../OBJ/WavefrontObject.hpp"
 * from an OBJ file and converts it into some vertex buffers
 * that we can draw.
 */
struct Shape
{
    Shape()
    {
        if (shapeFile.load(String(BinaryData::teapot_obj)).wasOk())
        {
            for (auto* s : shapeFile.shapes)
            {
                vertexBuffers.add(new VertexBuffer(*s));
            }
        }
    }

    void draw(Attributes& glAttributes)
    {
        for (auto* vertexBuffer : vertexBuffers)
        {
            vertexBuffer->bind();

            glAttributes.enable();
            glDrawElements(GL_TRIANGLES, vertexBuffer->numIndices, GL_UNSIGNED_INT, 0);
            glAttributes.disable();
        }
    }

private:
    struct VertexBuffer
    {
        VertexBuffer(WavefrontObjFile::Shape& aShape)
        {
            numIndices = aShape.mesh.indices.size();

            glGenBuffers(1, &vertexBuffer);
            glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

            Array<Vertex> vertices;
            createVertexListFromMesh(aShape.mesh, vertices, Colours::green);

            glBufferData(GL_ARRAY_BUFFER,
                         static_cast<GLsizeiptr>(static_cast<size_t>(vertices.size()) * sizeof(Vertex)),
                         vertices.getRawDataPointer(), GL_STATIC_DRAW);

            glGenBuffers(1, &indexBuffer);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                         static_cast<GLsizeiptr>(static_cast<size_t>(numIndices) * sizeof(juce::uint32)),
                         aShape.mesh.indices.getRawDataPointer(), GL_STATIC_DRAW);
        }

        ~VertexBuffer()
        {
            glDeleteBuffers(1, &vertexBuffer);
            glDeleteBuffers(1, &indexBuffer);
        }

        void bind()
        {
            glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
        }

        GLuint vertexBuffer, indexBuffer;
        int numIndices;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VertexBuffer)
    };

    WavefrontObjFile shapeFile;
    OwnedArray<VertexBuffer> vertexBuffers;

    static void createVertexListFromMesh(const WavefrontObjFile::Mesh& mesh, Array<Vertex>& list, Colour colour)
    {
        auto scale = 0.2f;
        WavefrontObjFile::TextureCoord defaultTexCoord{0.5f, 0.5f};
        WavefrontObjFile::Vertex defaultNormal{0.5f, 0.5f, 0.5f};

        for (auto i = 0; i < mesh.vertices.size(); ++i)
        {
            const auto& v  = mesh.vertices.getReference(i);
            const auto& n  = i < mesh.normals.size() ? mesh.normals.getReference(i) : defaultNormal;
            const auto& tc = i < mesh.textureCoords.size() ? mesh.textureCoords.getReference(i) : defaultTexCoord;

            list.add({{
                          scale * v.x,
                          scale * v.y,
                          scale * v.z,
                      },
                      {
                          scale * n.x,
                          scale * n.y,
                          scale * n.z,
                      },
                      {colour.getFloatRed(), colour.getFloatGreen(), colour.getFloatBlue(), colour.getFloatAlpha()},
                      {tc.x, tc.y}});
        }
    }
};