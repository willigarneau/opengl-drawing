#pragma once
class Point
{
public:
	Point();
	void Draw(float x, float y, bool random, RGBCOLOR color, GLuint program);
	void reDraw(GLuint program);
	int Size();
	char* Name();
	void Clear();
};

