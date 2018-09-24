#include "openGlHeaders.h"

vector<GLfloat> quadGrid;
vector<GLfloat> quadColorGrid;
float firstTempClick[2];
float secondTempClick[2];
float thirdTempClick[2];
bool firstClicked, secondClicked, thirdClicked;

Quadrilateral::Quadrilateral() {}

void Quadrilateral::DrawFirstTriangle(float x, float y, RGBCOLOR color, GLuint program)
{
	GLfloat vertex[16] = {
		firstTempClick[0], firstTempClick[1], 0.0f, 1.0f,
		secondTempClick[0], secondTempClick[1], 0.0f, 1.0f,
		thirdTempClick[0], thirdTempClick[1], 0.0f, 1.0f,
		x, y, 0.0f, 1.0f,
	};
	GLfloat vertexColor[4] = {
		color.red, color.green, color.blue, 1.0f,
	};

	#pragma region Update items grid
	// add float items to vertex grid
	quadGrid.push_back(vertex[0]);
	quadGrid.push_back(vertex[1]);
	quadGrid.push_back(vertex[2]);
	quadGrid.push_back(vertex[3]);
	quadGrid.push_back(vertex[4]);
	quadGrid.push_back(vertex[5]);
	quadGrid.push_back(vertex[6]);
	quadGrid.push_back(vertex[7]);
	quadGrid.push_back(vertex[8]);
	quadGrid.push_back(vertex[9]);
	quadGrid.push_back(vertex[10]);
	quadGrid.push_back(vertex[11]);
	quadGrid.push_back(vertex[12]);
	quadGrid.push_back(vertex[13]);
	quadGrid.push_back(vertex[14]);
	quadGrid.push_back(vertex[15]);
	// add float items to color grid
	quadColorGrid.push_back(vertexColor[0]);
	quadColorGrid.push_back(vertexColor[1]);
	quadColorGrid.push_back(vertexColor[2]);
	quadColorGrid.push_back(vertexColor[3]);
	quadColorGrid.push_back(vertexColor[0]);
	quadColorGrid.push_back(vertexColor[1]);
	quadColorGrid.push_back(vertexColor[2]);
	quadColorGrid.push_back(vertexColor[3]);
	quadColorGrid.push_back(vertexColor[0]);
	quadColorGrid.push_back(vertexColor[1]);
	quadColorGrid.push_back(vertexColor[2]);
	quadColorGrid.push_back(vertexColor[3]);
	quadColorGrid.push_back(vertexColor[0]);
	quadColorGrid.push_back(vertexColor[1]);
	quadColorGrid.push_back(vertexColor[2]);
	quadColorGrid.push_back(vertexColor[3]);
#pragma endregion

	GLuint vertexBuffer, colorBuffer;
	for (int i = 0; i < Size(); i += 16) {
		GLfloat cpyVertex[16] = {
			quadGrid[i], quadGrid[i + 1], quadGrid[i + 2], quadGrid[i + 3],
			quadGrid[i + 4], quadGrid[i + 5], quadGrid[1 + 6], quadGrid[i + 7],
			quadGrid[i + 8], quadGrid[i + 9], quadGrid[i + 10], quadGrid[i + 11],
		};
		// put the vertex buffer on gpu
		glGenBuffers(1, &vertexBuffer); // generate opengl buffer
		glEnableVertexAttribArray(0); // allocate address 0 to link our vbo
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); // link vbo to vertex buffer attribute
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertex), &cpyVertex, GL_STREAM_DRAW); // insert data to buffer
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

		GLfloat cpyVertexColor[16] = {
			quadColorGrid[i], quadColorGrid[i + 1], quadColorGrid[i + 2], quadColorGrid[i + 3],
			quadColorGrid[i], quadColorGrid[i + 1], quadColorGrid[i + 2], quadColorGrid[i + 3],
			quadColorGrid[i], quadColorGrid[i + 1], quadColorGrid[i + 2], quadColorGrid[i + 3],
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
		glDrawArrays(GL_TRIANGLES, 0, Size() / 4);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		DrawSecondTriangle(i, color, program);
		firstClicked = false;
		secondClicked = false;
		thirdClicked = false;
	}
}

void Quadrilateral::DrawSecondTriangle(int indice, RGBCOLOR color, GLuint program)
{
	GLuint vertexBuffer, colorBuffer;
	for (int i = indice; i < Size(); i += 16) {
		GLfloat cpyVertex[16] = {
			quadGrid[i + 4], quadGrid[i + 5], quadGrid[1 + 6], quadGrid[i + 7],
			quadGrid[i + 8], quadGrid[i + 9], quadGrid[i + 10], quadGrid[i + 11],
			quadGrid[i + 12], quadGrid[i + 13], quadGrid[i + 14], quadGrid[i + 15],
		};
		// put the vertex buffer on gpu
		glGenBuffers(1, &vertexBuffer); // generate opengl buffer
		glEnableVertexAttribArray(0); // allocate address 0 to link our vbo
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); // link vbo to vertex buffer attribute
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertex), &cpyVertex, GL_STREAM_DRAW); // insert data to buffer
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

		GLfloat cpyVertexColor[16] = {
			quadColorGrid[i], quadColorGrid[i + 1], quadColorGrid[i + 2], quadColorGrid[i + 3],
			quadColorGrid[i], quadColorGrid[i + 1], quadColorGrid[i + 2], quadColorGrid[i + 3],
			quadColorGrid[i], quadColorGrid[i + 1], quadColorGrid[i + 2], quadColorGrid[i + 3],
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
		glDrawArrays(GL_TRIANGLES, 0, Size() / 4);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
	}
}

void Quadrilateral::reDraw(RGBCOLOR color, GLuint program)
{
	GLuint vertexBuffer, colorBuffer;
	for (int i = 0; i < Size(); i += 16) {
		GLfloat cpyVertex[16] = {
			quadGrid[i], quadGrid[i + 1], quadGrid[i + 2], quadGrid[i + 3],
			quadGrid[i + 4], quadGrid[i + 5], quadGrid[1 + 6], quadGrid[i + 7],
			quadGrid[i + 8], quadGrid[i + 9], quadGrid[i + 10], quadGrid[i + 11],
		};
		// put the vertex buffer on gpu
		glGenBuffers(1, &vertexBuffer); // generate opengl buffer
		glEnableVertexAttribArray(0); // allocate address 0 to link our vbo
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); // link vbo to vertex buffer attribute
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertex), &cpyVertex, GL_STREAM_DRAW); // insert data to buffer
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

		GLfloat cpyVertexColor[16] = {
			quadColorGrid[i], quadColorGrid[i + 1], quadColorGrid[i + 2], quadColorGrid[i + 3],
			quadColorGrid[i], quadColorGrid[i + 1], quadColorGrid[i + 2], quadColorGrid[i + 3],
			quadColorGrid[i], quadColorGrid[i + 1], quadColorGrid[i + 2], quadColorGrid[i + 3],
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
		glDrawArrays(GL_TRIANGLES, 0, Size() / 4);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		DrawSecondTriangle(i, color, program);
	}
}

int Quadrilateral::Size()
{
	return quadGrid.size();
}

char * Quadrilateral::Name()
{
	return (char*)"Quadrilateral";
}

void Quadrilateral::Clear()
{
	quadGrid.clear();
	quadColorGrid.clear();
	firstClicked = false;
	secondClicked = false;
	thirdClicked = false;
}

bool Quadrilateral::isFirstClicked()
{
	return firstClicked;
}

bool Quadrilateral::isSecondClicked()
{
	return secondClicked;
}

bool Quadrilateral::isThirdClicked()
{
	return thirdClicked;
}

void Quadrilateral::firstClick(float x, float y)
{
	firstClicked = true;
	firstTempClick[0] = x;
	firstTempClick[1] = y;
}

void Quadrilateral::secondClick(float x, float y)
{
	secondClicked = true;
	secondTempClick[0] = x;
	secondTempClick[1] = y;
}

void Quadrilateral::thirdClick(float x, float y)
{
	thirdClicked = true;
	thirdTempClick[0] = x;
	thirdTempClick[1] = y;
}

void Quadrilateral::Process(float x, float y, RGBCOLOR color, GLuint program)
{
	if (!isFirstClicked() && !isSecondClicked() && !isThirdClicked()) { firstClick(x, y); return; }
	if (isFirstClicked() && !isSecondClicked() && !isThirdClicked()) { secondClick(x, y); return; }
	if (isFirstClicked() && isSecondClicked() && !isThirdClicked()) { thirdClick(x, y); return; }
	if (isFirstClicked() && isSecondClicked() && isThirdClicked()) { DrawFirstTriangle(x, y, color, program); return; }
}
