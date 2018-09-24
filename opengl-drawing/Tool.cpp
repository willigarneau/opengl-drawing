#include "openGlHeaders.h"

Point toolPoint;
Line toolLine;
Triangle toolTriangle;
Quadrilateral toolQuad;
int selectedTool;

Tool::Tool(Point point, Line line, Triangle triangle, Quadrilateral quad) { 
	toolPoint = point;
	toolLine = line;
	toolTriangle = triangle;
	toolQuad = quad;
}

void Tool::reDraw(Point p, Line l, Triangle t, Quadrilateral q, RGBCOLOR color, GLuint program)
{
	glClear(GL_COLOR_BUFFER_BIT);
	p.reDraw(program);
	l.reDraw(program);
	q.reDraw(color, program);
	// need to add other shapes
}

char* Tool::getSelectedTool()
{
	if (selectedTool == 1) { return (char*)toolPoint.Name(); }
	if (selectedTool == 2) { return (char*)toolLine.Name(); }
	if (selectedTool == 3) { return (char*)toolTriangle.Name(); }
	if (selectedTool == 4) { return (char*)toolQuad.Name(); }
}

void Tool::setSelectedTool(int newTool)
{
	selectedTool = newTool;
}
