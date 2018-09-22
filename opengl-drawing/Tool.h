#include "Triangle.h"
#include "Line.h"
#include "Point.h"
#include "Quadrilateral.h"
#pragma once
class Tool
{
public:
	Tool(Point p, Line l, Triangle t, Quadrilateral q);
	char* getSelectedTool();
	void setSelectedTool(int newTool);
};

