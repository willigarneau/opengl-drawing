#include "openGlHeaders.h"

vector<GLfloat> pencilGrid;
vector<GLfloat> pencilColorGrid;
int penIndex = 0;

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
	GLfloat cpyVertex[8] = {
		pencilGrid[penIndex], pencilGrid[penIndex + 1], pencilGrid[penIndex + 2], pencilGrid[penIndex + 3],
		pencilGrid[penIndex + 4], pencilGrid[penIndex + 5], pencilGrid[penIndex + 6], pencilGrid[penIndex + 7],
	};
	GLfloat cpyVertexColor[8] = {
		pencilColorGrid[penIndex], pencilColorGrid[penIndex + 1], pencilColorGrid[penIndex + 2], pencilColorGrid[penIndex + 3],
		pencilColorGrid[penIndex + 4], pencilColorGrid[penIndex + 5], pencilColorGrid[penIndex + 6], pencilColorGrid[penIndex + 7],
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
	glLineWidth(3);
	glDrawArrays(GL_LINE_STRIP, 0, 2);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glutPostRedisplay();
	penIndex += 4;
}

void Pencil::reDraw(GLuint program)
{
	if (Size() > 0) {
		GLuint vertexBuffer, colorBuffer;
		for (int i = 0; i < Size() - 4; i += 4) {
			GLfloat cpyVertex[8] = {
				pencilGrid[i], pencilGrid[i + 1], pencilGrid[i + 2], pencilGrid[i + 3],
				pencilGrid[i + 4], pencilGrid[i + 5], pencilGrid[i + 6], pencilGrid[i + 7],
			};
			GLfloat cpyVertexColor[8] = {
				pencilColorGrid[i], pencilColorGrid[i + 1], pencilColorGrid[i + 2], pencilColorGrid[i + 3],
				pencilColorGrid[i + 4], pencilColorGrid[i + 5], pencilColorGrid[i + 6], pencilColorGrid[i + 7],
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
			glPointSize(3);
			glDrawArrays(GL_LINE_STRIP, 0, 2);

			glDisableVertexAttribArray(0);
			glDisableVertexAttribArray(1);

			glutPostRedisplay();
		}
	}
}

char * Pencil::Name()
{
	return (char*)"Pencil";
}

void Pencil::Clear()
{
	pencilGrid.clear();
	pencilColorGrid.clear();
	penIndex = 0;
}

void Pencil::Process(float x, float y, bool random, RGBCOLOR color, GLuint program)
{
	if (Size() == 0) {
		// add float items to vertex grid
		pencilGrid.push_back(x);
		pencilGrid.push_back(y);
		pencilGrid.push_back(1.0f);
		pencilGrid.push_back(1.0f);
		// add float items to color grid
		pencilColorGrid.push_back(color.red);
		pencilColorGrid.push_back(color.green);
		pencilColorGrid.push_back(color.blue);
		pencilColorGrid.push_back(1.0f);
	}
	else {
		Draw(x, y, random, color, program);
	}
}

int Pencil::Size()
{
	return pencilGrid.size();
}
