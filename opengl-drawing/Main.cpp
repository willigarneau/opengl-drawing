/*
	Travail Pratique 1
	Infographie 2018
	Par William Garneau
*/

#include "openGlHeaders.h"

GLuint program;
int windowWidth = 800, windowHeight = 600;
RGBCOLOR usedColor;
Point point;
Line line;
Triangle triangle;
Quadrilateral quad;
Tool tool(point, line, triangle, quad);
GlutWindow painting;


void displayScene()
{
	glFlush();
}
void handleMenuFunctions(int value)
{
	if (value == 1) { usedColor.red = 1.0f; usedColor.green = 0.0f; usedColor.blue = 0.0f; usedColor.colorName = (char*)"Rouge"; } // red
	if (value == 2) { usedColor.red = 0.0f; usedColor.green = 0.0f; usedColor.blue = 1.0f;  usedColor.colorName = (char*)"Bleu"; } // blue
	if (value == 3) { usedColor.red = 0.0f; usedColor.green = 1.0f; usedColor.blue = 0.0f; usedColor.colorName = (char*)"Vert"; } // green
	if (value == 4) { tool.setSelectedTool(1); painting.ClearWindow(point, line, triangle, quad); }
	if (value == 5) { tool.setSelectedTool(2); painting.ClearWindow(point, line, triangle, quad); }
	if (value == 6) { tool.setSelectedTool(3); painting.ClearWindow(point, line, triangle, quad); }
	if (value == 7) { tool.setSelectedTool(4); painting.ClearWindow(point, line, triangle, quad); }
	if (value == 0) { glutLeaveMainLoop(); }
	if (value == -1) { painting.ClearWindow(point, line, triangle, quad); }

	cout << "La couleur actuellement choisie est : " << usedColor.colorName << endl;
	cout << "L'outil actuellement choisi est : " << tool.getSelectedTool() << endl << endl;
	glutPostRedisplay();
}

void createMouseMenu()
{
	int mainMenu, colorSubMenu, shapesSubMenu;
	colorSubMenu = glutCreateMenu(handleMenuFunctions);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Blue", 2);
	glutAddMenuEntry("Green", 3);

	shapesSubMenu = glutCreateMenu(handleMenuFunctions);
	glutAddMenuEntry("Point", 4);
	glutAddMenuEntry("Line", 5);
	glutAddMenuEntry("Triangle", 6);
	glutAddMenuEntry("Quadrilateral", 7);


	mainMenu = glutCreateMenu(handleMenuFunctions);
	glutAddSubMenu("Colors", colorSubMenu);
	glutAddSubMenu("Shapes", shapesSubMenu);
	glutAddMenuEntry("Erase", -1);
	glutAddMenuEntry("Exit", 0);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void handleMouse(int button, int state, int x, int y)
{
	float Xndc = x * (2.0) / glutGet(GLUT_WINDOW_WIDTH) - 1.0;
	float Yndc = -(y - glutGet(GLUT_WINDOW_HEIGHT)) * (1.0 + 1.0) / glutGet(GLUT_WINDOW_HEIGHT) - 1.0;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && tool.getSelectedTool() == (char*)"Point") { point.Draw(Xndc, Yndc, usedColor, program); }
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && tool.getSelectedTool() == (char*)"Ligne") { line.Process(Xndc, Yndc, usedColor, program); }
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && tool.getSelectedTool() == (char*)"Triangle") { triangle.Process(Xndc, Yndc, usedColor, program); }
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && tool.getSelectedTool() == (char*)"Quadrilateral") { quad.Process(Xndc, Yndc, usedColor, program); }
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) { std::cout << "y : " << y << " Yndc : " << Yndc << std::endl; }
}


//Fonction principale d'exécution
int main(int argc, char **argv)
{
	ShaderLoader shader;

	usedColor.red = 1.0f; usedColor.green = 1.0f; usedColor.blue = 1.0f; usedColor.colorName = (char*)"Blanc";
	tool.setSelectedTool(1);

	// Window Instantiation
	glutInit(&argc, argv);
	painting = GlutWindow(windowWidth, windowHeight, (char*)"Travail Pratique 1");

	//Fonctions de rappel
	glutDisplayFunc(displayScene);
	glutMouseFunc(handleMouse);

	program = shader.CreateProgram((char*)"vertexShader.glsl", (char*)"fragmentShader.glsl");

	createMouseMenu();

	glutMainLoop();
	return 0;

}