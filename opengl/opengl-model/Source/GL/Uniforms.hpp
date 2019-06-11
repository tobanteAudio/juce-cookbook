#pragma once

#include "core/common.hpp"

// This class just manages the uniform values that the demo shaders use.
struct Uniforms
{
    Uniforms(OpenGLContext& openGLContext, OpenGLShaderProgram& shaderProgram)
    {
        projectionMatrix.reset(createUniform(openGLContext, shaderProgram, "projectionMatrix"));
        viewMatrix.reset(createUniform(openGLContext, shaderProgram, "viewMatrix"));
    }

    std::unique_ptr<OpenGLShaderProgram::Uniform> projectionMatrix, viewMatrix;

private:
    static OpenGLShaderProgram::Uniform* createUniform(OpenGLContext& openGLContext, OpenGLShaderProgram& shaderProgram,
                                                       const String& uniformName)
    {
        if (openGLContext.extensions.glGetUniformLocation(shaderProgram.getProgramID(), uniformName.toRawUTF8()) < 0)
            return nullptr;

        return new OpenGLShaderProgram::Uniform(shaderProgram, uniformName.toRawUTF8());
    }
};
