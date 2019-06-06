#pragma once

#include "JuceHeader.h"

#include "GL/Attributes.hpp"
#include "GL/Uniforms.hpp"
#include "GL/Vertex.hpp"

#include "OBJ/Shape.hpp"
#include "OBJ/WavefrontObject.hpp"

/*
 * @brief This component lives inside our window, and this is where you should put all
 * your controls and content.
 */
class MainComponent : public OpenGLAppComponent
{
public:
    MainComponent();
    ~MainComponent();

    void initialise() override;
    void shutdown() override;
    void render() override;

    void paint(Graphics& g) override;
    void resized() override;

    Matrix3D<float> getProjectionMatrix() const;
    Matrix3D<float> getViewMatrix() const;
    void createShaders();

private:
    std::unique_ptr<OpenGLShaderProgram> m_shader;
    std::unique_ptr<Shape> m_shape;
    std::unique_ptr<Attributes> m_attributes;
    std::unique_ptr<Uniforms> m_uniforms;

    Slider m_XPosition;
    Slider m_YPosition;
    Slider m_ZPosition;
    Slider m_zoomView;
    Slider m_XRotation;
    Slider m_YRotation;
    Slider m_ZRotation;

    Label m_XPositionLabel;
    Label m_YPositionLabel;
    Label m_ZPositionLabel;
    Label m_zoomLabel;
    Label m_XRotationLabel;
    Label m_YRotationLabel;
    Label m_ZRotationLabel;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
