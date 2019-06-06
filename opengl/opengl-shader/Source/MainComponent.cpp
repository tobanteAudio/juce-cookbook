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
    // build and compile our shader program
    // ------------------------------------
    m_shader.reset(
        new tobanteAudio::Shader(openGLContext, VERTEX_SHADER_SOURCE, FRAGMENT_SHADER_SOURCE));
}

void MainComponent::shutdown()
{
    // Free any GL objects created for rendering here.
}

void MainComponent::render()
{
    auto& GL = openGLContext.extensions;

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glEnable(GL_POINT_SMOOTH);

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        // positions         // colors
        0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom left
        0.0f,  0.5f,  0.0f, 0.0f, 0.0f, 1.0f   // top
    };

    unsigned int VBO;

    // GL.glGenVertexArrays(1, &m_vertexArrayObject);
    void* glGenVertexArraysPtr = OpenGLHelpers::getExtensionFunction("glGenVertexArrays");
    typedef void (*func_type)(GLsizei n, const GLuint* arrays);
    ((func_type)glGenVertexArraysPtr)(1, &m_vertexArrayObject);

    GL.glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s),
    // and then configure vertex attributes(s).
    // GL.glBindVertexArray(m_vertexArrayObject);
    void* ptr = OpenGLHelpers::getExtensionFunction("glBindVertexArray");
    typedef void (*func_type_2)(GLuint array);
    ((func_type_2)ptr)(m_vertexArrayObject);

    GL.glBindBuffer(GL_ARRAY_BUFFER, VBO);
    GL.glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    GL.glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    GL.glEnableVertexAttribArray(0);
    // color attribute
    GL.glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    GL.glEnableVertexAttribArray(1);

    // RENDER
    // This clears the context with a black background.
    // OpenGLHelpers::clear(Colours::white);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // DBG(seconds);
    // render the triangle
    m_shader->use();
    // const auto millis      = time.currentTimeMillis()/10000000000;
    m_counter += 0.02f;
    const float timeValue  = static_cast<float>(m_counter);
    const float greenValue = sin(timeValue) / 2.0f + 0.5f;
    const float redValue   = sin(timeValue) / 4.0f + 0.25f;
    m_shader->setFloat4("ourColor", greenValue, -redValue, redValue, 1.0f);
    {
        void* ptr3 = OpenGLHelpers::getExtensionFunction("glBindVertexArray");
        typedef void (*func_type_2)(GLuint array);
        ((func_type_2)ptr3)(m_vertexArrayObject);
    }
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

//==============================================================================
void MainComponent::paint(Graphics& g)
{
    ignoreUnused(g);
    // You can add your component specific drawing code here!
    // This will draw over the top of the openGL background.
}

void MainComponent::resized() {}
