#include "main_component.hpp"

#include "opengl/shader_source.hpp"

MainComponent::MainComponent()
    : m_XPosition(Slider::LinearHorizontal, Slider::TextBoxBelow)
    , m_YPosition(Slider::LinearHorizontal, Slider::TextBoxBelow)
    , m_ZPosition(Slider::LinearHorizontal, Slider::TextBoxBelow)
    , m_zoomView(Slider::LinearHorizontal, Slider::TextBoxBelow)
    , m_XRotation(Slider::LinearHorizontal, Slider::TextBoxBelow)
    , m_YRotation(Slider::LinearHorizontal, Slider::TextBoxBelow)
    , m_ZRotation(Slider::LinearHorizontal, Slider::TextBoxBelow)
    , m_XPositionLabel("position_x", "Position: X")
    , m_YPositionLabel("position_y", "Position: Y")
    , m_ZPositionLabel("position_z", "Position: Z")
    , m_zoomLabel("zoom", "Zoom:")
    , m_XRotationLabel("rotation_x", "Rotation: X")
    , m_YRotationLabel("rotation_y", "Rotation: Y")
    , m_ZRotationLabel("rotation_z", "Rotation: Z")
{
    setSize(1600, 900);
    openGLContext.setContinuousRepainting(true);

    // Sliders
    m_XPosition.setRange(-10.0, 10.0, 0.2);
    m_XPosition.setValue(0.0, dontSendNotification);
    addAndMakeVisible(m_XPosition);

    m_YPosition.setRange(-10.0, 10.0, 0.2);
    m_YPosition.setValue(0.0, dontSendNotification);
    addAndMakeVisible(m_YPosition);

    m_ZPosition.setRange(-20.0, 10.0, 0.2);
    m_ZPosition.setValue(-10.0, dontSendNotification);
    addAndMakeVisible(m_ZPosition);

    m_zoomView.setRange(-10.0, 50.0, 0.2);
    m_zoomView.setValue(4.0, dontSendNotification);
    addAndMakeVisible(m_zoomView);

    m_XRotation.setRange(-5.0, 5.0, 0.1);
    m_XRotation.setValue(0.0, dontSendNotification);
    addAndMakeVisible(m_XRotation);

    m_YRotation.setRange(-5.0, 5.0, 0.1);
    m_YRotation.setValue(0.0, dontSendNotification);
    addAndMakeVisible(m_YRotation);

    m_ZRotation.setRange(-5.0, 5.0, 0.1);
    m_ZRotation.setValue(0.0, dontSendNotification);
    addAndMakeVisible(m_ZRotation);

    // Labels
    addAndMakeVisible(m_XPositionLabel);
    addAndMakeVisible(m_YPositionLabel);
    addAndMakeVisible(m_ZPositionLabel);
    addAndMakeVisible(m_zoomLabel);
    addAndMakeVisible(m_XRotationLabel);
    addAndMakeVisible(m_YRotationLabel);
    addAndMakeVisible(m_ZRotationLabel);
}

MainComponent::~MainComponent() { shutdownOpenGL(); }

void MainComponent::initialise()
{
    // Glew
    if (glewInit() != GLEW_OK)
    {
        DBG("Error in glew init");
    }

    // Shaders
    createShaders();
}

void MainComponent::shutdown()
{
    m_shader.reset();
    m_shape.reset();
    m_attributes.reset();
    m_uniforms.reset();
}

void MainComponent::render()
{
    jassert(OpenGLHelpers::isContextActive());

    auto desktopScale = static_cast<float>(openGLContext.getRenderingScale());
    OpenGLHelpers::clear(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glViewport(0, 0, roundToInt(desktopScale * getWidth() - getWidth() / 5), roundToInt(desktopScale * getHeight()));

    m_shader->use();

    if (m_uniforms->projectionMatrix.get() != nullptr)
    {
        m_uniforms->projectionMatrix->setMatrix4(getProjectionMatrix().mat, 1, false);
    }

    if (m_uniforms->viewMatrix.get() != nullptr)
    {
        m_uniforms->viewMatrix->setMatrix4(getViewMatrix().mat, 1, false);
    }

    m_shape->draw(*m_attributes);

    // Reset the element buffers so child Components draw correctly
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

//==============================================================================
void MainComponent::paint(Graphics& g)
{
    // Draw the current GLSL version
    auto str = "GLSL: v" + String(OpenGLShaderProgram::getLanguageVersion(), 2);
    g.setColour(getLookAndFeel().findColour(Label::textColourId));
    g.setFont(20);
    g.drawText(str, 25, 20, 300, 30, Justification::left);
}

void MainComponent::resized()
{
    auto area       = getLocalBounds();
    auto sliderArea = area.removeFromRight(area.getWidth() / 5);

    int sliderHeight = 75;

    // Position X
    {
        auto subArea         = sliderArea.removeFromTop(sliderHeight);
        const auto labelArea = subArea.removeFromLeft(subArea.getWidth() / 3);
        m_XPositionLabel.setBounds(labelArea);
        m_XPosition.setBounds(subArea);
    }

    // Position Y
    {
        auto subArea         = sliderArea.removeFromTop(sliderHeight);
        const auto labelArea = subArea.removeFromLeft(subArea.getWidth() / 3);
        m_YPositionLabel.setBounds(labelArea);
        m_YPosition.setBounds(subArea);
    }

    // Position Z
    {
        auto subArea         = sliderArea.removeFromTop(sliderHeight);
        const auto labelArea = subArea.removeFromLeft(subArea.getWidth() / 3);
        m_ZPositionLabel.setBounds(labelArea);
        m_ZPosition.setBounds(subArea);
    }

    // Zoom
    {
        auto subArea         = sliderArea.removeFromTop(sliderHeight);
        const auto labelArea = subArea.removeFromLeft(subArea.getWidth() / 3);
        m_zoomLabel.setBounds(labelArea);
        m_zoomView.setBounds(subArea);
    }

    // Rotation X
    {
        auto subArea         = sliderArea.removeFromTop(sliderHeight);
        const auto labelArea = subArea.removeFromLeft(subArea.getWidth() / 3);
        m_XRotationLabel.setBounds(labelArea);
        m_XRotation.setBounds(subArea);
    }

    // Rotation Y
    {
        auto subArea         = sliderArea.removeFromTop(sliderHeight);
        const auto labelArea = subArea.removeFromLeft(subArea.getWidth() / 3);
        m_YRotationLabel.setBounds(labelArea);
        m_YRotation.setBounds(subArea);
    }

    // Rotation Z
    {
        auto subArea         = sliderArea.removeFromTop(sliderHeight);
        const auto labelArea = subArea.removeFromLeft(subArea.getWidth() / 3);
        m_ZRotationLabel.setBounds(labelArea);
        m_ZRotation.setBounds(subArea);
    }
}

Matrix3D<float> MainComponent::getProjectionMatrix() const
{
    auto w = 1.0f / (0.5f + 0.1f);
    auto h = w * getLocalBounds().toFloat().getAspectRatio(false);

    const auto near = static_cast<float>(m_zoomView.getValue());
    return Matrix3D<float>::fromFrustum(-w, w, -h, h, near, 90.0);
}

Matrix3D<float> MainComponent::getViewMatrix() const
{
    const auto positionX = static_cast<float>(m_XPosition.getValue());
    const auto positionY = static_cast<float>(m_YPosition.getValue());
    const auto positionZ = static_cast<float>(m_ZPosition.getValue());

    Matrix3D<float> viewMatrix({positionX, positionY, positionZ});

    const auto rotationX = static_cast<float>(m_XRotation.getValue());
    const auto rotationY = static_cast<float>(m_YRotation.getValue());
    const auto rotationZ = static_cast<float>(m_ZRotation.getValue());
    // 5.0f * std::sin(getFrameCounter() * 0.01f)
    Matrix3D<float> rotationMatrix = viewMatrix.rotation({rotationX, rotationY, rotationZ});

    return rotationMatrix * viewMatrix;
}

void MainComponent::createShaders()
{
    std::unique_ptr<OpenGLShaderProgram> newShader(new OpenGLShaderProgram(openGLContext));
    String statusText;

    if (newShader->addVertexShader(VERTEX_SHADER) && newShader->addFragmentShader(FRAGMENT_SHADER) && newShader->link())
    {
        m_shape.reset();
        m_attributes.reset();
        m_uniforms.reset();

        m_shader.reset(newShader.release());
        m_shader->use();

        m_shape.reset(new Shape());
        m_attributes.reset(new Attributes(*m_shader));
        m_uniforms.reset(new Uniforms(*m_shader));

        statusText = "GLSL: v" + String(OpenGLShaderProgram::getLanguageVersion(), 2);
    }
    else
    {
        statusText = newShader->getLastError();
    }
}