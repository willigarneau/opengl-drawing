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
