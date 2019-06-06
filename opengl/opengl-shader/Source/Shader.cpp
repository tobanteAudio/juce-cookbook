#include "Shader.hpp"

namespace tobanteAudio
{
Shader::Shader(OpenGLContext& context, const char* vertexSource, const char* fragmentSource)
    : openGLContext(context)
{
    // Vertex
    unsigned int vertex;
    vertex = openGLContext.extensions.glCreateShader(GL_VERTEX_SHADER);
    openGLContext.extensions.glShaderSource(vertex, 1, &vertexSource, nullptr);
    openGLContext.extensions.glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");

    // Fragment
    unsigned int fragment;
    fragment = openGLContext.extensions.glCreateShader(GL_FRAGMENT_SHADER);
    openGLContext.extensions.glShaderSource(fragment, 1, &fragmentSource, nullptr);
    openGLContext.extensions.glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");

    // Program
    m_id = openGLContext.extensions.glCreateProgram();
    openGLContext.extensions.glAttachShader(m_id, vertex);
    openGLContext.extensions.glAttachShader(m_id, fragment);
    openGLContext.extensions.glLinkProgram(m_id);
    checkCompileErrors(m_id, "PROGRAM");

    // Delete the shaders as they're linked into our program now and no
    // longer necessary
    openGLContext.extensions.glDeleteShader(vertex);
    openGLContext.extensions.glDeleteShader(fragment);
}

void Shader::use() { openGLContext.extensions.glUseProgram(m_id); }

unsigned int Shader::getID() { return m_id; }

void Shader::setBool(const std::string& name, bool value) const
{
    openGLContext.extensions.glUniform1i(
        openGLContext.extensions.glGetUniformLocation(m_id, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value) const
{
    openGLContext.extensions.glUniform1i(
        openGLContext.extensions.glGetUniformLocation(m_id, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const
{
    openGLContext.extensions.glUniform1f(
        openGLContext.extensions.glGetUniformLocation(m_id, name.c_str()), value);
}

void Shader::setFloat4(const std::string& name, float r, float g, float b, float a) const
{
    openGLContext.extensions.glUniform4f(
        openGLContext.extensions.glGetUniformLocation(m_id, name.c_str()), r, g, b, a);
}

void Shader::checkCompileErrors(unsigned int shader_id, std::string type)
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        openGLContext.extensions.glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            openGLContext.extensions.glGetShaderInfoLog(shader_id, 1024, nullptr, infoLog);
            std::string err = "ERROR::SHADER_COMPILATION_ERROR of type: ";
            std::cout << err << type << "\n" << infoLog << '\n';
        }
    }
    else
    {
        openGLContext.extensions.glGetProgramiv(shader_id, GL_LINK_STATUS, &success);
        if (!success)
        {
            openGLContext.extensions.glGetProgramInfoLog(shader_id, 1024, nullptr, infoLog);
            std::string err = "ERROR::PROGRAM_LINKING_ERROR of type: ";
            std::cout << err << type << "\n" << infoLog << '\n';
        }
    }
}

}  // namespace tobanteAudio
