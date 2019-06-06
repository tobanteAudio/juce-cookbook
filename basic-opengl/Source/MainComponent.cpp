#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setName("tobanteAudio: Basic OpenGL");
    setSize(1280, 720);
    openGLContext.setOpenGLVersionRequired(juce::OpenGLContext::openGL3_2);
    openGLContext.setContinuousRepainting(true);
}

MainComponent::~MainComponent()
{
    // This shuts down the GL system and stops the rendering calls.
    shutdownOpenGL();
}

//==============================================================================
void MainComponent::initialise()
{
    // Initialise GL objects for rendering here.
}

void MainComponent::shutdown()
{
    // Free any GL objects created for rendering here.
}

void MainComponent::render()
{
    // This clears the context with a black background.
    OpenGLHelpers::clear(Colours::green);

    // Points in 3D space
    GLfloat verts[]{-1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f};

    // An ID for your buffer
    GLuint bufferID;

    // Get the ID
    openGLContext.extensions.glGenBuffers(1, &bufferID);

    // Configure the buffer
    openGLContext.extensions.glBindBuffer(GL_ARRAY_BUFFER, bufferID);

    // Let GL know about our veritices
    openGLContext.extensions.glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts,
                                          GL_STATIC_DRAW);

    openGLContext.extensions.glEnableVertexAttribArray(0);

    openGLContext.extensions.glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0,
                                                   nullptr);
    // openGLContext.extensions.

    // Draw three verticies
    glDrawArrays(GL_TRIANGLES, 0, 3);

    openGLContext.extensions.glDisableVertexAttribArray(0);

    // Add your rendering code here...
}

//==============================================================================
void MainComponent::paint(Graphics& g)
{
    // You can add your component specific drawing code here!
    // This will draw over the top of the openGL background.
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
