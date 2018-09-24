#include "openGlHeaders.h"

vector<GLfloat> lineGrid;
vector<GLfloat> lineColorGrid;
float tempClick[2];
bool clicked = false;

Line::Line() {}

void Line::Draw(float x, float y, RGBCOLOR color, GLuint program)
{
	GLfloat vertex[8] = {
		tempClick[0], tempClick[1], 0.0f, 1.0f,
		x, y, 0.0f, 1.0f,
	};
	GLfloat vertexColor[4] = {
		color.red, color.green, color.blue, 1.0f,
	};

	#pragma region Update items grid
	// add float items to vertex grid
	lineGrid.push_back(vertex[0]);
	lineGrid.push_back(vertex[1]);
	lineGrid.push_back(vertex[2]);
	lineGrid.push_back(vertex[3]);
	lineGrid.push_back(vertex[4]);
	lineGrid.push_back(vertex[5]);
	lineGrid.push_back(vertex[6]);
	lineGrid.push_back(vertex[7]);
	// add float items to color grid
	lineColorGrid.push_back(vertexColor[0]);
	lineColorGrid.push_back(vertexColor[1]);
	lineColorGrid.push_back(vertexColor[2]);
	lineColorGrid.push_back(vertexColor[3]);
	lineColorGrid.push_back(vertexColor[0]);
	lineColorGrid.push_back(vertexColor[1]);
	lineColorGrid.push_back(vertexColor[2]);
	lineColorGrid.push_back(vertexColor[3]);
	#pragma endregion

	GLuint vertexBuffer, colorBuffer;
	bool setColor = true;
	for (int i = 0; i < Size(); i += 8) {

		GLfloat cpyVertex[8] = {
		lineGrid[i], lineGrid[i + 1], lineGrid[i + 2], lineGrid[i + 3],
		lineGrid[i + 4], lineGrid[i + 5], lineGrid[1 + 6], lineGrid[i + 7]
		};
		// put the vertex buffer on gpu
		glGenBuffers(1, &vertexBuffer); // generate opengl buffer
		glEnableVertexAttribArray(0); // allocate address 0 to link our vbo
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); // link vbo to vertex buffer attribute
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertex), &cpyVertex, GL_STREAM_DRAW); // insert data to buffer
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

		GLfloat cpyVertexColor[8] = {
			lineColorGrid[i], lineColorGrid[i + 1], lineColorGrid[i + 2], lineColorGrid[i + 3],
			lineColorGrid[i], lineColorGrid[i + 1], lineColorGrid[i + 2], lineColorGrid[i + 3],
		};
		// put the color buffer on gpu
		glGenBuffers(1, &colorBuffer);
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertexColor), &cpyVertexColor, GL_STREAM_DRAW);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
		setColor = false;
		// draw
		glUseProgram(program);
		glLineWidth(3);
		glDrawArrays(GL_LINES, 0, Size() / 4);
		glDisableVertexAttribArray(0);
		clicked = false;
	}
}

void Line::reDraw(GLuint program)
{
	GLuint vertexBuffer, colorBuffer;
	for (int i = 0; i < Size(); i += 8) {

		GLfloat cpyVertex[8] = {
			lineGrid[i], lineGrid[i + 1], lineGrid[i + 2], lineGrid[i + 3],
			lineGrid[i + 4], lineGrid[i + 5], lineGrid[1 + 6], lineGrid[i + 7]
		};
		// put the vertex buffer on gpu
		glGenBuffers(1, &vertexBuffer); // generate opengl buffer
		glEnableVertexAttribArray(0); // allocate address 0 to link our vbo
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); // link vbo to vertex buffer attribute
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertex), &cpyVertex, GL_STREAM_DRAW); // insert data to buffer
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

		GLfloat cpyVertexColor[8] = {
			lineColorGrid[i], lineColorGrid[i + 1], lineColorGrid[i + 2], lineColorGrid[i + 3],
			lineColorGrid[i], lineColorGrid[i + 1], lineColorGrid[i + 2], lineColorGrid[i + 3],
		};
		// put the color buffer on gpu
		glGenBuffers(1, &colorBuffer);
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertexColor), &cpyVertexColor, GL_STREAM_DRAW);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
		// draw
		glUseProgram(program);
		glLineWidth(3);
		glDrawArrays(GL_LINES, 0, Size() / 4);
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
	}
}

int Line::Size()
{
	return lineGrid.size();
}

char * Line::Name()
{
	return (char*)"Ligne";
}

void Line::Clear()
{
	lineGrid.clear();
	lineColorGrid.clear();
	clicked = false;
}

bool Line::isClicked() {
	return clicked;
}

void Line::Init(float x, float y) {
	clicked = true;
	tempClick[0] = x;
	tempClick[1] = y;
}

void Line::Process(float x, float y, RGBCOLOR color, GLuint program)
{
	if (!isClicked()) {
		Init(x, y);
	}
	else {
		Draw(x, y, color, program);
	}
}


