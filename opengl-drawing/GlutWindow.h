#include "Point.h"
#include "Line.h"
#pragma once
class GlutWindow
{
public:
	GlutWindow();
	GlutWindow(int windowWidth, int windowHeight, char* windowName);
	void ClearWindow(Point p, Line l);
};

