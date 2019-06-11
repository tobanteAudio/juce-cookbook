
#pragma once

#include "core/common.hpp"

#include "Vertex.hpp"

// This class just manages the attributes that the shaders use.
struct Attributes
{
    Attributes(OpenGLShaderProgram& shaderProgram)
    {
        position.reset(createAttribute(shaderProgram, "position"));
        normal.reset(createAttribute(shaderProgram, "normal"));
        sourceColour.reset(createAttribute(shaderProgram, "sourceColour"));
        textureCoordIn.reset(createAttribute(shaderProgram, "textureCoordIn"));
    }

    void enable()
    {
        if (position.get() != nullptr)
        {
            glVertexAttribPointer(position->attributeID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
            glEnableVertexAttribArray(position->attributeID);
        }

        if (normal.get() != nullptr)
        {
            glVertexAttribPointer(normal->attributeID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                  (GLvoid*)(sizeof(float) * 3));
            glEnableVertexAttribArray(normal->attributeID);
        }

        if (sourceColour.get() != nullptr)
        {
            glVertexAttribPointer(sourceColour->attributeID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                  (GLvoid*)(sizeof(float) * 6));
            glEnableVertexAttribArray(sourceColour->attributeID);
        }

        if (textureCoordIn.get() != nullptr)
        {
            glVertexAttribPointer(textureCoordIn->attributeID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                  (GLvoid*)(sizeof(float) * 10));
            glEnableVertexAttribArray(textureCoordIn->attributeID);
        }
    }

    void disable()
    {
        if (position.get() != nullptr) glDisableVertexAttribArray(position->attributeID);
        if (normal.get() != nullptr) glDisableVertexAttribArray(normal->attributeID);
        if (sourceColour.get() != nullptr) glDisableVertexAttribArray(sourceColour->attributeID);
        if (textureCoordIn.get() != nullptr) glDisableVertexAttribArray(textureCoordIn->attributeID);
    }

    std::unique_ptr<OpenGLShaderProgram::Attribute> position, normal, sourceColour, textureCoordIn;

private:
    static OpenGLShaderProgram::Attribute* createAttribute(OpenGLShaderProgram& shader, const String& attributeName)
    {
        if (glGetAttribLocation(shader.getProgramID(), attributeName.toRawUTF8()) < 0) return nullptr;

        return new OpenGLShaderProgram::Attribute(shader, attributeName.toRawUTF8());
    }
};
