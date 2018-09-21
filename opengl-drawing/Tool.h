#include "Triangle.h"
#include "Line.h"
#include "Point.h"
#pragma once
class Tool
{
public:
	Tool(Point p, Line l, Triangle t);
	char* getSelectedTool();
	void setSelectedTool(int newTool);
};

