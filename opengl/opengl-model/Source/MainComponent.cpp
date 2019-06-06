#include "MainComponent.hpp"

MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize(800, 600);
}

MainComponent::~MainComponent() { shutdownOpenGL(); }

void MainComponent::initialise() { createShaders(); }

void MainComponent::shutdown()
{
    shader.reset();
    shape.reset();
    attributes.reset();
    uniforms.reset();
}

void MainComponent::render()
{
    jassert(OpenGLHelpers::isContextActive());

    auto desktopScale = (float)openGLContext.getRenderingScale();
    OpenGLHelpers::clear(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glViewport(0, 0, roundToInt(desktopScale * getWidth()), roundToInt(desktopScale * getHeight()));

    shader->use();

    if (uniforms->projectionMatrix.get() != nullptr)
        uniforms->projectionMatrix->setMatrix4(getProjectionMatrix().mat, 1, false);

    if (uniforms->viewMatrix.get() != nullptr)
        uniforms->viewMatrix->setMatrix4(getViewMatrix().mat, 1, false);

    shape->draw(openGLContext, *attributes);

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
