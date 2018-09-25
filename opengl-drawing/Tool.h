#include "Triangle.h"
#include "Line.h"
#include "Point.h"
#include "Pencil.h"
#include "Quadrilateral.h"
#pragma once
class Tool
{
public:
	Tool(Point p, Line l, Triangle t, Quadrilateral q, Pencil pen);
	void reDraw(Point p, Line l, Triangle t, Quadrilateral q, Pencil pen, RGBCOLOR color, GLuint program);
	char* getSelectedTool();
	void setSelectedTool(int newTool);
};

