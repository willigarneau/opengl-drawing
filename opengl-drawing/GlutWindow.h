#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Quadrilateral.h"
#include "Pencil.h"
#pragma once
class GlutWindow
{
public:
	GlutWindow();
	GlutWindow(int windowWidth, int windowHeight, char* windowName);
	void ClearWindow(Point p, Line l, Triangle t, Quadrilateral q, Pencil pen);
};

