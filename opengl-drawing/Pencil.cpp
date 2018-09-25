#include "openGlHeaders.h"

vector<GLfloat> pencilGrid;
vector<GLfloat> pencilColorGrid;

Pencil::Pencil() { }

void Pencil::Draw(float x, float y, bool random, RGBCOLOR color, GLuint program)
{
	if (random) {
		color.red = (rand() % 255) / 255.0;
		color.green = (rand() % 255) / 255.0;
		color.blue = (rand() % 255) / 255.0;
	}
	GLfloat vertex[4] = {
		x, y, 1.0f, 1.0f
	};
	GLfloat vertexColor[4] = {
		color.red, color.green, color.blue, 1.0f
	};
	// add float items to vertex grid
	pencilGrid.push_back(vertex[0]);
	pencilGrid.push_back(vertex[1]);
	pencilGrid.push_back(vertex[2]);
	pencilGrid.push_back(vertex[3]);
	// add float items to color grid
	pencilColorGrid.push_back(vertexColor[0]);
	pencilColorGrid.push_back(vertexColor[1]);
	pencilColorGrid.push_back(vertexColor[2]);
	pencilColorGrid.push_back(vertexColor[3]);
	GLuint vertexBuffer, colorBuffer;
	for (int i = 0; i < Size(); i += 4) {
		GLfloat cpyVertex[4] = {
			pencilGrid[i], pencilGrid[i + 1], pencilGrid[i + 2], pencilGrid[i + 3]
		};
		GLfloat cpyVertexColor[4] = {
			pencilColorGrid[i], pencilColorGrid[i + 1], pencilColorGrid[i + 2], pencilColorGrid[i + 3]
		};
		// put the vertex buffer on gpu
		glGenBuffers(0, &vertexBuffer); // generate opengl buffer
		glEnableVertexAttribArray(0); // allocate address 0 to link our vbo
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); // link vbo to vertex buffer attribute
		int test = sizeof(cpyVertex);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertex), cpyVertex, GL_STATIC_DRAW); // insert data to buffer
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
		// put the color buffer on gpu
		glGenBuffers(1, &colorBuffer);
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertexColor), cpyVertexColor, GL_STATIC_DRAW);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
		// draw
		glUseProgram(program);
		glPointSize(5);
		glDrawArrays(GL_POINTS, 0, 1);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glutPostRedisplay();
	}
}

void Pencil::reDraw(GLuint program)
{
}

int Pencil::Size()
{
	return pencilGrid.size();
}

char * Pencil::Name()
{
	return (char*)"Pencil";
}

void Pencil::Clear()
{
	pencilGrid.clear();
	pencilColorGrid.clear();
}