
#pragma once

#include "JuceHeader.h"

#include "Vertex.hpp"

// This class just manages the attributes that the shaders use.
struct Attributes
{
    Attributes(OpenGLContext& openGLContext, OpenGLShaderProgram& shaderProgram)
    {
        position.reset(createAttribute(openGLContext, shaderProgram, "position"));
        normal.reset(createAttribute(openGLContext, shaderProgram, "normal"));
        sourceColour.reset(createAttribute(openGLContext, shaderProgram, "sourceColour"));
        textureCoordIn.reset(createAttribute(openGLContext, shaderProgram, "textureCoordIn"));
    }

    void enable(OpenGLContext& context)
    {
        if (position.get() != nullptr)
        {
            context.extensions.glVertexAttribPointer(position->attributeID, 3, GL_FLOAT, GL_FALSE,
                                                     sizeof(Vertex), 0);
            context.extensions.glEnableVertexAttribArray(position->attributeID);
        }

        if (normal.get() != nullptr)
        {
            context.extensions.glVertexAttribPointer(normal->attributeID, 3, GL_FLOAT, GL_FALSE,
                                                     sizeof(Vertex), (GLvoid*)(sizeof(float) * 3));
            context.extensions.glEnableVertexAttribArray(normal->attributeID);
        }

        if (sourceColour.get() != nullptr)
        {
            context.extensions.glVertexAttribPointer(sourceColour->attributeID, 4, GL_FLOAT, GL_FALSE,
                                                     sizeof(Vertex), (GLvoid*)(sizeof(float) * 6));
            context.extensions.glEnableVertexAttribArray(sourceColour->attributeID);
        }

        if (textureCoordIn.get() != nullptr)
        {
            context.extensions.glVertexAttribPointer(textureCoordIn->attributeID, 2, GL_FLOAT,
                                                     GL_FALSE, sizeof(Vertex),
                                                     (GLvoid*)(sizeof(float) * 10));
            context.extensions.glEnableVertexAttribArray(textureCoordIn->attributeID);
        }
    }

    void disable(OpenGLContext& context)
    {
        if (position.get() != nullptr)
            context.extensions.glDisableVertexAttribArray(position->attributeID);
        if (normal.get() != nullptr)
            context.extensions.glDisableVertexAttribArray(normal->attributeID);
        if (sourceColour.get() != nullptr)
            context.extensions.glDisableVertexAttribArray(sourceColour->attributeID);
        if (textureCoordIn.get() != nullptr)
            context.extensions.glDisableVertexAttribArray(textureCoordIn->attributeID);
    }

    std::unique_ptr<OpenGLShaderProgram::Attribute> position, normal, sourceColour, textureCoordIn;

private:
    static OpenGLShaderProgram::Attribute* createAttribute(OpenGLContext& openGLContext,
                                                           OpenGLShaderProgram& shader,
                                                           const String& attributeName)
    {
        if (openGLContext.extensions.glGetAttribLocation(shader.getProgramID(),
                                                         attributeName.toRawUTF8())
            < 0)
            return nullptr;

        return new OpenGLShaderProgram::Attribute(shader, attributeName.toRawUTF8());
    }
};
