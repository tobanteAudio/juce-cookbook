#include "MainComponent.hpp"
#include "Shader_Source.hpp"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.

    setSize(1600, 900);
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
    // GLEW
    if (glewInit() != GLEW_OK)
    {
        DBG("Error in glew init");
    }

    m_shader.reset(new tobanteAudio::Shader(VERTEX_SHADER_SRC, FRAGMENT_SHADER_SRC));
}

void MainComponent::shutdown()
{
    // Free any GL objects created for rendering here.
}

void MainComponent::render()
{
    // Make sure the context is active
    jassert(OpenGLHelpers::isContextActive());

    // OpenGL modes
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glEnable(GL_POINT_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Set viewport
    const auto desktopScale = (float)openGLContext.getRenderingScale();
    glViewport(0, 0, roundToInt(desktopScale * getWidth()), roundToInt(desktopScale * getHeight()));

    // UPLOAD DATA
    // 3x positions         // 3x colors
    GLfloat vertices[] = {
        0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom left
        0.0f,  0.5f,  0.0f, 0.0f, 0.0f, 1.0f   // top
    };

    // IDs
    GLuint VAO, VBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);
    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    // RENDER
    // This clears the context with a solid background.
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // SHADER
    m_shader->use();

    // CHANGING COLOR
    const auto frames      = getFrameCounter();
    const float greenValue = std::sin(frames * 0.02f);
    const float redValue   = std::sin(frames * 0.01f);
    const float blueValue  = std::sin(frames * 0.005f);
    m_shader->setFloat4("ourColor", greenValue, redValue, blueValue, 1.0f);

    // BIND VERTEX ARRAY
    glBindVertexArray(VAO);

    // FINALLY, DRAW!
    glDrawArrays(GL_TRIANGLES, 0, 3);
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

void MainComponent::resized() {}
