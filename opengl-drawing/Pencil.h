#pragma once
class Pencil
{
public:
	Pencil();
	void Draw(float x, float y, bool random, RGBCOLOR color, GLuint program);
	void reDraw(GLuint program);
	int Size();
	char* Name();
	void Clear();
	void Process(float x, float y, bool random, RGBCOLOR color, GLuint program);
};

