#include "openGlHeaders.h"

Point toolPoint;
Line toolLine;
int selectedTool;

Tool::Tool(Point point, Line line) { 
	toolPoint = point;
	toolLine = line;
}

char* Tool::getSelectedTool()
{
	if (selectedTool == 1) { return (char*)toolPoint.Name(); }
	if (selectedTool == 2) { return (char*)toolLine.Name(); }
}

void Tool::setSelectedTool(int newTool)
{
	selectedTool = newTool;
}
