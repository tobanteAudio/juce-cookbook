#pragma once

#include "core/common.hpp"

// This class just manages the uniform values that the demo shaders use.
struct Uniforms
{
    Uniforms(OpenGLShaderProgram& shaderProgram)
    {
        projectionMatrix.reset(createUniform(shaderProgram, "projectionMatrix"));
        viewMatrix.reset(createUniform(shaderProgram, "viewMatrix"));
    }

    std::unique_ptr<OpenGLShaderProgram::Uniform> projectionMatrix, viewMatrix;

private:
    static OpenGLShaderProgram::Uniform* createUniform(OpenGLShaderProgram& shaderProgram, const String& uniformName)
    {
        if (glGetUniformLocation(shaderProgram.getProgramID(), uniformName.toRawUTF8()) < 0) return nullptr;

        return new OpenGLShaderProgram::Uniform(shaderProgram, uniformName.toRawUTF8());
    }
};
