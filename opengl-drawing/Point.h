#pragma once
class Point
{
public:
	Point();
	void Draw(float x, float y, RGBCOLOR color, GLuint program);
	void reDraw(GLuint program);
	int Size();
	char* Name();
	void Clear();
};

