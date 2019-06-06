#pragma once

constexpr char* VERTEX_SHADER = R"(
    attribute vec4 position;
    attribute vec4 sourceColour;
    attribute vec2 textureCoordIn;

    uniform mat4 projectionMatrix;
    uniform mat4 viewMatrix;

    varying vec4 destinationColour;
    varying vec2 textureCoordOut;

    void main()
    {
        destinationColour = sourceColour;
        textureCoordOut = textureCoordIn;
        gl_Position = projectionMatrix * viewMatrix * position;
    }
)";

constexpr char* FRAGMENT_SHADER = R"(
	varying vec4 destinationColour;
	varying vec2 textureCoordOut;

	void main()
	{
		vec4 colour = vec4(0.95, 0.57, 0.03, 0.7);
		gl_FragColor = colour;
	}
)";