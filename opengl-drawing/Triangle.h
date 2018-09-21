#pragma once
class Triangle
{
public:
	Triangle();
	void Draw(float x, float y, RGBCOLOR color, GLuint program);
	int Size();
	char* Name();
	void Clear();
	bool isFirstClicked();
	bool isSecondClicked();
	void firstClick(float x, float y);
	void secondClick(float x, float y);
	void Process(float x, float y, RGBCOLOR color, GLuint program);
};

