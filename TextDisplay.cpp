#include "TextDisplay.h"
#include "lodepng.h"

TextDisplay::TextDisplay()
{
    std::vector<unsigned char> raw_image;
    unsigned img_width = 107, img_height = 17;
    unsigned error = lodepng::decode(raw_image, img_width, img_height, "./Numbers_mono.png");
    if(error != 0)
    {
        std::cout << "error " << error << ": " << lodepng_error_text(error) << std::endl;
    }

	GLuint texture_id;
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img_width, img_height, 0, GL_RGB, GL_UNSIGNED_BYTE, &raw_image[0]);


	const char* vertexSource =
		"#version 400\n"
		"in vec3 vp;"
		"layout (location=1) in vec2 vt; // per-vertex texture co-ords"
		"out vec2 texture_coordinates; "
		"void main () {"
		"  gl_Position = vec4 (vp, 1.0);"
		"  texture_coordinates = vt; "
		"}";
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	checkShader(vertexShader);


	const char* fragmentSource =
		"#version 400\n"
		"in vec2 texture_coordinates;"
		"uniform sampler2D basic_texture;"
		"out vec4 frag_colour;"
		"void main () {"
		"vec4 texel = texture(basic_texture, texture_coordinates);"
		"frag_colour = texel; "
		"}";
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	checkShader(fragmentShader);


	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

}
//	~TextDisplay();
void TextDisplay::drawText(double x, double y, const char* text)
{
	float x2 = x;
	float y2 = -y;
	float w = img_width / 10;
	float h = img_height;

	GLfloat box[4][4] = {
			{ x, y, 0, 0 },
			{ x + w, y, .1, 0 },
			{ x, y+h, 0, .1 },
			{ x + w, y+h, .1, .1 },
	};

	glUseProgram(shaderProgram);
	glBufferData(GL_ARRAY_BUFFER, sizeof box, box, GL_DYNAMIC_DRAW);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}
	//GLuint shaderProgram, vertexShader, fragmentShader, posAttrib, uniTrans, vbo, vao;
//};
