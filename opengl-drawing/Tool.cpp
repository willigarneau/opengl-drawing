#include "openGlHeaders.h"

Point toolPoint;
Line toolLine;
Triangle toolTriangle;
int selectedTool;

Tool::Tool(Point point, Line line, Triangle triangle) { 
	toolPoint = point;
	toolLine = line;
	toolTriangle = triangle;
}

char* Tool::getSelectedTool()
{
	if (selectedTool == 1) { return (char*)toolPoint.Name(); }
	if (selectedTool == 2) { return (char*)toolLine.Name(); }
	if (selectedTool == 3) { return (char*)toolTriangle.Name(); }
}

void Tool::setSelectedTool(int newTool)
{
	selectedTool = newTool;
}
