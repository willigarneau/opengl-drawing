#pragma once
class Quadrilateral
{
public:
	Quadrilateral();
	void DrawFirstTriangle(float x, float y, bool random, RGBCOLOR color, GLuint program);
	void DrawSecondTriangle(RGBCOLOR color, GLuint program);
	void reDraw(RGBCOLOR color, GLuint program);
	int Size();
	char* Name();
	void Clear();
	bool isFirstClicked();
	bool isSecondClicked();
	bool isThirdClicked();
	void firstClick(float x, float y);
	void secondClick(float x, float y);
	void thirdClick(float x, float y);
	void Process(float x, float y, bool random, RGBCOLOR color, GLuint program);
};

