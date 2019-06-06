#include "MainComponent.hpp"
#include "GL/ShaderSource.hpp"
MainComponent::MainComponent()
{
    setSize(1280, 720);
    openGLContext.setOpenGLVersionRequired(juce::OpenGLContext::openGL3_2);
    openGLContext.setContinuousRepainting(true);
}

MainComponent::~MainComponent() { shutdownOpenGL(); }

void MainComponent::initialise() { createShaders(); }

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

    glViewport(0, 0, roundToInt(desktopScale * getWidth()), roundToInt(desktopScale * getHeight()));

    m_shader->use();

    if (m_uniforms->projectionMatrix.get() != nullptr)
    {
        m_uniforms->projectionMatrix->setMatrix4(getProjectionMatrix().mat, 1, false);
    }

    if (m_uniforms->viewMatrix.get() != nullptr)
    {
        m_uniforms->viewMatrix->setMatrix4(getViewMatrix().mat, 1, false);
    }

    m_shape->draw(openGLContext, *m_attributes);

    // Reset the element buffers so child Components draw correctly
    openGLContext.extensions.glBindBuffer(GL_ARRAY_BUFFER, 0);
    openGLContext.extensions.glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
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
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

Matrix3D<float> MainComponent::getProjectionMatrix() const
{
    auto w = 1.0f / (0.5f + 0.1f);
    auto h = w * getLocalBounds().toFloat().getAspectRatio(false);

    return Matrix3D<float>::fromFrustum(-w, w, -h, h, 4.0f, 30.0f);
}

Matrix3D<float> MainComponent::getViewMatrix() const
{
    Matrix3D<float> viewMatrix({0.0f, 0.0f, -10.0f});
    Matrix3D<float> rotationMatrix = viewMatrix.rotation({-0.3f, 5.0f * std::sin(getFrameCounter() * 0.01f), 0.0f});

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

        m_shape.reset(new Shape(openGLContext));
        m_attributes.reset(new Attributes(openGLContext, *m_shader));
        m_uniforms.reset(new Uniforms(openGLContext, *m_shader));

        statusText = "GLSL: v" + String(OpenGLShaderProgram::getLanguageVersion(), 2);
    }
    else
    {
        statusText = newShader->getLastError();
    }
}