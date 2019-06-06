#pragma once

// BASIC
constexpr char* VERTEX_SHADER_SOURCE = R"(
    #version 430 core

    layout (location = 0) in vec3 aPos;

    void main()
    {
        gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    }
)";

constexpr char* FRAGMENT_SHADER_SOURCE = R"(
    #version 430 core

    out vec4 FragColor;

    uniform vec4 ourColor;

    void main()
    {
        FragColor = ourColor;
    }
)";