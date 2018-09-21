#pragma once
class Tool
{
public:
	Tool(Point p, Line l);
	char* getSelectedTool();
	void setSelectedTool(int newTool);
};

