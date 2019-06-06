#include "MainComponent.hpp"
#include "Shader_Source.hpp"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
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
    // Build and compile our shader program
    m_shader.reset(new tobanteAudio::Shader(openGLContext, VERTEX_SHADER_SRC, FRAGMENT_SHADER_SRC));
}

void MainComponent::shutdown()
{
    // Free any GL objects created for rendering here.
}

void MainComponent::render()
{
    // Reference to keep the source lines shorter,
    // since we are using openGLContext.extensions a lot.
    const auto& GL = openGLContext.extensions;

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
    GLfloat vertices[] = {
        // positions         // colors
        0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom left
        0.0f,  0.5f,  0.0f, 0.0f, 0.0f, 1.0f   // top
    };


    {
        void* glGenVertexArraysPtr = OpenGLHelpers::getExtensionFunction("glGenVertexArrays");
        typedef void (*func_type)(GLsizei n, const GLuint* arrays);
        ((func_type)glGenVertexArraysPtr)(1, &m_vertexArrayObject);
    }

    unsigned int VBO;
    GL.glGenBuffers(1, &VBO);
    {
        // Bind the Vertex Array Object first, then bind and set vertex buffer(s),
        // and then configure vertex attributes(s).
        void* ptr = OpenGLHelpers::getExtensionFunction("glBindVertexArray");
        typedef void (*func_type)(GLuint array);
        ((func_type)ptr)(m_vertexArrayObject);
    }

    GL.glBindBuffer(GL_ARRAY_BUFFER, VBO);
    GL.glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    GL.glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
    GL.glEnableVertexAttribArray(0);
    // Color attribute
    GL.glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
                             (void*)(3 * sizeof(GLfloat)));
    GL.glEnableVertexAttribArray(1);

    // RENDER
    // This clears the context with a solid background.
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // SHADER
    m_shader->use();

    // CHANGING COLOR
    m_counter += 0.02f;
    const float timeValue  = static_cast<float>(m_counter);
    const float greenValue = sin(timeValue) / 2.0f + 0.5f;
    const float redValue   = sin(timeValue) / 4.0f + 0.25f;
    m_shader->setFloat4("ourColor", greenValue, -redValue, redValue, 1.0f);

    // BIND VERTEX ARRAY
    {
        void* ptr3 = OpenGLHelpers::getExtensionFunction("glBindVertexArray");
        typedef void (*func_type_2)(GLuint array);
        ((func_type_2)ptr3)(m_vertexArrayObject);
    }

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
