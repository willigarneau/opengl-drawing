#pragma once
class Pencil
{
public:
	Pencil();
	void Draw(float x, float y, RGBCOLOR color, GLuint program);
	int Size();
	char* Name();
	void Clear();
	bool isClicked();
	void Init(float x, float y);
	void Process(float x, float y, RGBCOLOR color, GLuint program);
};

