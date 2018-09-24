#include "openGlHeaders.h"

vector<GLfloat> pointGrid;
vector<GLfloat> pointColorGrid;

Point::Point() {}

void Point::Draw(float x, float y, RGBCOLOR color, GLuint program)
{
	GLfloat vertex[4] = {
		x, y, 0.0f, 1.0f,
	};
	GLfloat vertexColor[4] = {
		color.red, color.green, color.blue, 1.0f,
	};
	// add float items to vertex grid
	pointGrid.push_back(vertex[0]);
	pointGrid.push_back(vertex[1]);
	pointGrid.push_back(vertex[2]);
	pointGrid.push_back(vertex[3]);
	// add float items to color grid
	pointColorGrid.push_back(vertexColor[0]);
	pointColorGrid.push_back(vertexColor[1]);
	pointColorGrid.push_back(vertexColor[2]);
	pointColorGrid.push_back(vertexColor[3]);

	GLuint vertexBuffer, colorBuffer;
	for (int i = 0; i < Size(); i+=4) {
		GLfloat cpyVertex[4] = {
		pointGrid[i], pointGrid[i+1], pointGrid[i+2], pointGrid[i+3],
		};
		GLfloat cpyVertexColor[4] = {
			pointColorGrid[i], pointColorGrid[i+1], pointColorGrid[i+2], pointColorGrid[i+3],
		};
		// put the vertex buffer on gpu
		glGenBuffers(0, &vertexBuffer); // generate opengl buffer
		glEnableVertexAttribArray(0); // allocate address 0 to link our vbo
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); // link vbo to vertex buffer attribute
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertex), &cpyVertex, GL_STREAM_DRAW); // insert data to buffer
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
		// put the color buffer on gpu
		glGenBuffers(1, &colorBuffer);
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertexColor), &cpyVertexColor, GL_STREAM_DRAW);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
		// draw
		glUseProgram(program);
		glPointSize(15);
		glDrawArrays(GL_POINTS, 0, Size() / 4);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
	}
}

void Point::reDraw(GLuint program)
{
	GLuint vertexBuffer, colorBuffer;
	for (int i = 0; i < Size(); i += 4) {
		GLfloat cpyVertex[4] = {
			pointGrid[i], pointGrid[i + 1], pointGrid[i + 2], pointGrid[i + 3],
		};
		GLfloat cpyVertexColor[4] = {
			pointColorGrid[i], pointColorGrid[i + 1], pointColorGrid[i + 2], pointColorGrid[i + 3],
		};
		// put the vertex buffer on gpu
		glGenBuffers(1, &vertexBuffer); // generate opengl buffer
		glEnableVertexAttribArray(0); // allocate address 0 to link our vbo
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); // link vbo to vertex buffer attribute
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertex), &cpyVertex, GL_STREAM_DRAW); // insert data to buffer
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
		// put the color buffer on gpu
		glGenBuffers(1, &colorBuffer);
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertexColor), &cpyVertexColor, GL_STREAM_DRAW);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
		// draw
		glUseProgram(program);
		glPointSize(15);
		glDrawArrays(GL_POINTS, 0, Size() / 4);
		glDisableVertexAttribArray(0);
	}
}

int Point::Size()
{
	return pointGrid.size();
}

char* Point::Name() {
	return (char*)"Point";
}

void Point::Clear() {
	pointGrid.clear();
	pointColorGrid.clear();
	glClear(GL_COLOR_BUFFER_BIT);
}
