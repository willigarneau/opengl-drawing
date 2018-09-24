#include "openGlHeaders.h"

vector<GLfloat> triangleGrid;
vector<GLfloat> triangleColorGrid;
float triFirstTempClick[2];
float triSecondTempClick[2];
bool triFirstClicked = false, triSecondClicked = false;

Triangle::Triangle() {}

void Triangle::Draw(float x, float y, RGBCOLOR color, GLuint program)
{
	GLfloat vertex[12] = {
		triFirstTempClick[0], triFirstTempClick[1], 0.0f, 1.0f,
		triSecondTempClick[0], triSecondTempClick[1], 0.0f, 1.0f,
		x, y, 0.0f, 1.0f,
	};
	GLfloat vertexColor[4] = {
		color.red, color.green, color.blue, 1.0f,
	};

	#pragma region Update items grid
	// add float items to vertex grid
	triangleGrid.push_back(vertex[0]);
	triangleGrid.push_back(vertex[1]);
	triangleGrid.push_back(vertex[2]);
	triangleGrid.push_back(vertex[3]);
	triangleGrid.push_back(vertex[4]);
	triangleGrid.push_back(vertex[5]);
	triangleGrid.push_back(vertex[6]);
	triangleGrid.push_back(vertex[7]);
	triangleGrid.push_back(vertex[8]);
	triangleGrid.push_back(vertex[9]);
	triangleGrid.push_back(vertex[10]);
	triangleGrid.push_back(vertex[11]);
	// add float items to color grid
	triangleColorGrid.push_back(vertexColor[0]);
	triangleColorGrid.push_back(vertexColor[1]);
	triangleColorGrid.push_back(vertexColor[2]);
	triangleColorGrid.push_back(vertexColor[3]);
	triangleColorGrid.push_back(vertexColor[0]);
	triangleColorGrid.push_back(vertexColor[1]);
	triangleColorGrid.push_back(vertexColor[2]);
	triangleColorGrid.push_back(vertexColor[3]);
	triangleColorGrid.push_back(vertexColor[0]);
	triangleColorGrid.push_back(vertexColor[1]);
	triangleColorGrid.push_back(vertexColor[2]);
	triangleColorGrid.push_back(vertexColor[3]);
	#pragma endregion

	GLuint vertexBuffer, colorBuffer;
	for (int i = 0; i < Size(); i += 12) {

		GLfloat cpyVertex[12] = {
			triangleGrid[i], triangleGrid[i + 1], triangleGrid[i + 2], triangleGrid[i + 3],
			triangleGrid[i + 4], triangleGrid[i + 5], triangleGrid[1 + 6], triangleGrid[i + 7],
			triangleGrid[i + 8], triangleGrid[i + 9], triangleGrid[i + 10], triangleGrid[i + 11],
		};
		// put the vertex buffer on gpu
		glGenBuffers(1, &vertexBuffer); // generate opengl buffer
		glEnableVertexAttribArray(0); // allocate address 0 to link our vbo
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); // link vbo to vertex buffer attribute
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertex), &cpyVertex, GL_STREAM_DRAW); // insert data to buffer
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

		GLfloat cpyVertexColor[12] = {
			triangleColorGrid[i], triangleColorGrid[i + 1], triangleColorGrid[i + 2], triangleColorGrid[i + 3],
			triangleColorGrid[i], triangleColorGrid[i + 1], triangleColorGrid[i + 2], triangleColorGrid[i + 3],
			triangleColorGrid[i], triangleColorGrid[i + 1], triangleColorGrid[i + 2], triangleColorGrid[i + 3],
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
		triFirstClicked = false;
		triSecondClicked = false;
	}
}

void Triangle::reDraw(GLuint program)
{
	GLuint vertexBuffer, colorBuffer;
	for (int i = 0; i < Size(); i += 12) {

		GLfloat cpyVertex[12] = {
			triangleGrid[i], triangleGrid[i + 1], triangleGrid[i + 2], triangleGrid[i + 3],
			triangleGrid[i + 4], triangleGrid[i + 5], triangleGrid[1 + 6], triangleGrid[i + 7],
			triangleGrid[i + 8], triangleGrid[i + 9], triangleGrid[i + 10], triangleGrid[i + 11],
		};
		// put the vertex buffer on gpu
		glGenBuffers(1, &vertexBuffer); // generate opengl buffer
		glEnableVertexAttribArray(0); // allocate address 0 to link our vbo
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); // link vbo to vertex buffer attribute
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertex), &cpyVertex, GL_STREAM_DRAW); // insert data to buffer
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

		GLfloat cpyVertexColor[12] = {
			triangleColorGrid[i], triangleColorGrid[i + 1], triangleColorGrid[i + 2], triangleColorGrid[i + 3],
			triangleColorGrid[i], triangleColorGrid[i + 1], triangleColorGrid[i + 2], triangleColorGrid[i + 3],
			triangleColorGrid[i], triangleColorGrid[i + 1], triangleColorGrid[i + 2], triangleColorGrid[i + 3],
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

int Triangle::Size()
{
	return triangleGrid.size();
}

char * Triangle::Name()
{
	return (char*)"Triangle";
}

void Triangle::Clear()
{
	triangleGrid.clear();
	triangleColorGrid.clear();
	triFirstClicked = false;
	triSecondClicked = false;
}

bool Triangle::isFirstClicked()
{
	return triFirstClicked;
}

bool Triangle::isSecondClicked()
{
	return triSecondClicked;
}

void Triangle::firstClick(float x, float y)
{
	triFirstClicked = true;
	triFirstTempClick[0] = x;
	triFirstTempClick[1] = y;
}
void Triangle::secondClick(float x, float y)
{
	triSecondClicked = true;
	triSecondTempClick[0] = x;
	triSecondTempClick[1] = y;
}

void Triangle::Process(float x, float y, RGBCOLOR color, GLuint program)
{
	if (!isFirstClicked() && !isSecondClicked()) { firstClick(x, y); return; }
	if (isFirstClicked() && !isSecondClicked()) { secondClick(x, y); return; }
	if (isFirstClicked() && isSecondClicked()) { Draw(x, y, color, program); return; }
}
