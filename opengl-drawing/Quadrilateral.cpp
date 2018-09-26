#include "openGlHeaders.h"

vector<GLfloat> quadGrid;
vector<GLfloat> quadColorGrid;
float firstTempClick[2];
float secondTempClick[2];
float thirdTempClick[2];
bool firstClicked, secondClicked, thirdClicked;
int quadIndex = 0;

Quadrilateral::Quadrilateral() {}

void Quadrilateral::DrawFirstTriangle(float x, float y, bool random, RGBCOLOR color, GLuint program)
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
	random ? quadColorGrid.push_back((rand() % 255) / 255.0) : quadColorGrid.push_back(vertexColor[0]);
	random ? quadColorGrid.push_back((rand() % 255) / 255.0) : quadColorGrid.push_back(vertexColor[1]);
	random ? quadColorGrid.push_back((rand() % 255) / 255.0) : quadColorGrid.push_back(vertexColor[2]);
	quadColorGrid.push_back(vertexColor[3]);
	random ? quadColorGrid.push_back((rand() % 255) / 255.0) : quadColorGrid.push_back(vertexColor[0]);
	random ? quadColorGrid.push_back((rand() % 255) / 255.0) : quadColorGrid.push_back(vertexColor[1]);
	random ? quadColorGrid.push_back((rand() % 255) / 255.0) : quadColorGrid.push_back(vertexColor[2]);
	quadColorGrid.push_back(vertexColor[3]);
	random ? quadColorGrid.push_back((rand() % 255) / 255.0) : quadColorGrid.push_back(vertexColor[0]);
	random ? quadColorGrid.push_back((rand() % 255) / 255.0) : quadColorGrid.push_back(vertexColor[1]);
	random ? quadColorGrid.push_back((rand() % 255) / 255.0) : quadColorGrid.push_back(vertexColor[2]);
	quadColorGrid.push_back(vertexColor[3]);
	random ? quadColorGrid.push_back((rand() % 255) / 255.0) : quadColorGrid.push_back(vertexColor[0]);
	random ? quadColorGrid.push_back((rand() % 255) / 255.0) : quadColorGrid.push_back(vertexColor[1]);
	random ? quadColorGrid.push_back((rand() % 255) / 255.0) : quadColorGrid.push_back(vertexColor[2]);
	quadColorGrid.push_back(vertexColor[3]);
#pragma endregion

	GLuint vertexBuffer, colorBuffer;
	GLfloat cpyVertex[16] = {
		quadGrid[quadIndex], quadGrid[quadIndex + 1], quadGrid[quadIndex + 2], quadGrid[quadIndex + 3],
		quadGrid[quadIndex + 4], quadGrid[quadIndex + 5], quadGrid[quadIndex + 6], quadGrid[quadIndex + 7],
		quadGrid[quadIndex + 8], quadGrid[quadIndex + 9], quadGrid[quadIndex + 10], quadGrid[quadIndex + 11],
	};
	// put the vertex buffer on gpu
	glGenBuffers(1, &vertexBuffer); // generate opengl buffer
	glEnableVertexAttribArray(0); // allocate address 0 to link our vbo
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); // link vbo to vertex buffer attribute
	glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertex), &cpyVertex, GL_STREAM_DRAW); // insert data to buffer
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	GLfloat cpyVertexColor[16] = {
		quadColorGrid[quadIndex], quadColorGrid[quadIndex + 1], quadColorGrid[quadIndex + 2], quadColorGrid[quadIndex + 3],
		quadColorGrid[quadIndex + 4], quadColorGrid[quadIndex + 5], quadColorGrid[quadIndex + 6], quadColorGrid[quadIndex + 7],
		quadColorGrid[quadIndex + 8], quadColorGrid[quadIndex + 9], quadColorGrid[quadIndex + 10], quadColorGrid[quadIndex + 11],
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
	DrawSecondTriangle(color, program);
	firstClicked = false;
	secondClicked = false;
	thirdClicked = false;
	quadIndex += 16;
}

void Quadrilateral::DrawSecondTriangle(RGBCOLOR color, GLuint program)
{
	GLuint vertexBuffer, colorBuffer;
	GLfloat cpyVertex[16] = {
		quadGrid[quadIndex + 4], quadGrid[quadIndex + 5], quadGrid[quadIndex + 6], quadGrid[quadIndex + 7],
		quadGrid[quadIndex + 8], quadGrid[quadIndex + 9], quadGrid[quadIndex + 10], quadGrid[quadIndex + 11],
		quadGrid[quadIndex + 12], quadGrid[quadIndex + 13], quadGrid[quadIndex + 14], quadGrid[quadIndex + 15],
	};
	// put the vertex buffer on gpu
	glGenBuffers(1, &vertexBuffer); // generate opengl buffer
	glEnableVertexAttribArray(0); // allocate address 0 to link our vbo
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); // link vbo to vertex buffer attribute
	glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertex), &cpyVertex, GL_STREAM_DRAW); // insert data to buffer
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	GLfloat cpyVertexColor[16] = {
		quadColorGrid[quadIndex + 4], quadColorGrid[quadIndex + 5], quadColorGrid[quadIndex + 6], quadColorGrid[quadIndex + 7],
		quadColorGrid[quadIndex + 8], quadColorGrid[quadIndex + 9], quadColorGrid[quadIndex + 10], quadColorGrid[quadIndex + 11],
		quadColorGrid[quadIndex + 12], quadColorGrid[quadIndex + 13], quadColorGrid[quadIndex + 14], quadColorGrid[quadIndex + 15],
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

void Quadrilateral::reDraw(RGBCOLOR color, GLuint program)
{
	int tempIndex = quadIndex;
	quadIndex = 0;
	GLuint vertexBuffer, colorBuffer;
	for (int i = 0; i < Size(); i += 16) {
		GLfloat cpyVertex[16] = {
			quadGrid[quadIndex], quadGrid[quadIndex + 1], quadGrid[quadIndex + 2], quadGrid[quadIndex + 3],
			quadGrid[quadIndex + 4], quadGrid[quadIndex + 5], quadGrid[quadIndex + 6], quadGrid[quadIndex + 7],
			quadGrid[quadIndex + 8], quadGrid[quadIndex + 9], quadGrid[quadIndex + 10], quadGrid[quadIndex + 11],
		};
		// put the vertex buffer on gpu
		glGenBuffers(1, &vertexBuffer); // generate opengl buffer
		glEnableVertexAttribArray(0); // allocate address 0 to link our vbo
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); // link vbo to vertex buffer attribute
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertex), &cpyVertex, GL_STREAM_DRAW); // insert data to buffer
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

		GLfloat cpyVertexColor[16] = {
			quadColorGrid[quadIndex], quadColorGrid[quadIndex + 1], quadColorGrid[quadIndex + 2], quadColorGrid[quadIndex + 3],
			quadColorGrid[quadIndex], quadColorGrid[quadIndex + 1], quadColorGrid[quadIndex + 2], quadColorGrid[quadIndex + 3],
			quadColorGrid[quadIndex], quadColorGrid[quadIndex + 1], quadColorGrid[quadIndex + 2], quadColorGrid[quadIndex + 3],
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
		DrawSecondTriangle(color, program);
		quadIndex += 16;
	}
	firstClicked = false;
	secondClicked = false;
	thirdClicked = false;
	quadIndex = tempIndex;
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
	quadIndex = 0;
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

void Quadrilateral::Process(float x, float y, bool random, RGBCOLOR color, GLuint program)
{
	if (!isFirstClicked() && !isSecondClicked() && !isThirdClicked()) { firstClick(x, y); return; }
	if (isFirstClicked() && !isSecondClicked() && !isThirdClicked()) { secondClick(x, y); return; }
	if (isFirstClicked() && isSecondClicked() && !isThirdClicked()) { thirdClick(x, y); return; }
	if (isFirstClicked() && isSecondClicked() && isThirdClicked()) { DrawFirstTriangle(x, y, random, color, program); return; }
}
