#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

namespace tobanteAudio
{
/**
 * @brief Represents an OpenGL program (vertex & fragment shader)
 */
class Shader
{
private:
    unsigned int m_id;

public:
    /**
     * @brief Constructor
     *
     * Takes sources for a vertex & fragment shader
     */
    Shader(OpenGLContext& context, const char* vertexSource, const char* fragmentSource);

    /**
     * @brief Activates the shader
     */
    void use();

    /**
     * @brief Returns the id
     */
    unsigned int getID();

    /**
     * @brief Sets a uniform bool
     */
    void setBool(const std::string& name, bool value) const;

    /**
     * @brief Sets a uniform int
     */
    void setInt(const std::string& name, int value) const;

    /**
     * @brief Sets a uniform float
     */
    void setFloat(const std::string& name, float value) const;

    /**
     * @brief Sets a uniform float vector4
     */
    void setFloat4(const std::string& name, float v1, float v2, float v3, float v4) const;

private:
    void checkCompileErrors(unsigned int shader_id, std::string type);

private:
    OpenGLContext& openGLContext;
};

}  // namespace tobanteAudio