#pragma once
class Triangle
{
public:
	Triangle();
	void Draw(float x, float y, bool random, RGBCOLOR color, GLuint program);
	void reDraw(GLuint program);
	int Size();
	char* Name();
	void Clear();
	bool isFirstClicked();
	bool isSecondClicked();
	void firstClick(float x, float y);
	void secondClick(float x, float y);
	void Process(float x, float y, bool random, RGBCOLOR color, GLuint program);
};

