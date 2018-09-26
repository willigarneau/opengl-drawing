/*
	Travail Pratique 1
	Infographie 2018
	Par William Garneau
*/

#include "openGlHeaders.h"

GLuint program;
int windowWidth = 800, windowHeight = 600;
RGBCOLOR usedColor, backgroundColor;
Point point;
Line line;
Triangle triangle;
Quadrilateral quad;
Pencil pencil;
Tool tool(point, line, triangle, quad, pencil);
bool random;
GlutWindow painting;


void displayScene()
{
	glFlush();
}
void handleMenuFunctions(int value)
{
	if (value == 1) { usedColor.red = 1.0f; usedColor.green = 0.0f; usedColor.blue = 0.0f; usedColor.colorName = (char*)"Rouge"; random = false; } // red
	if (value == 2) { usedColor.red = 0.0f; usedColor.green = 0.0f; usedColor.blue = 1.0f;  usedColor.colorName = (char*)"Bleu"; random = false; } // blue
	if (value == 3) { usedColor.red = 0.0f; usedColor.green = 1.0f; usedColor.blue = 0.0f; usedColor.colorName = (char*)"Vert"; random = false; } // green
	if (value == 8) { usedColor.red = 1.0f; usedColor.green = 1.0f; usedColor.blue = 0.0f; usedColor.colorName = (char*)"Jaune"; random = false; } // Yellow
	if (value == 15) { usedColor.red = 0.0f; usedColor.green = 0.0f; usedColor.blue = 0.0f; usedColor.colorName = (char*)"Random"; random = true; } // Random
	if (value == 9) { backgroundColor.red = 1.0f; backgroundColor.green = 0.0f; backgroundColor.blue = 0.0f; backgroundColor.colorName = (char*)"Rouge"; 
		glClearColor(backgroundColor.red, backgroundColor.green, backgroundColor.blue, 0); tool.reDraw(point, line, triangle, quad, pencil, usedColor, program); } // Red Background
	if (value == 10) { backgroundColor.red = 0.0f; backgroundColor.green = 0.0f; backgroundColor.blue = 1.0f;  backgroundColor.colorName = (char*)"Bleu"; 
		glClearColor(backgroundColor.red, backgroundColor.green, backgroundColor.blue, 0); tool.reDraw(point, line, triangle, quad, pencil, usedColor, program); } // Blue Background
	if (value == 11) { backgroundColor.red = 0.0f; backgroundColor.green = 1.0f; backgroundColor.blue = 0.0f; backgroundColor.colorName = (char*)"Vert"; 
		glClearColor(backgroundColor.red, backgroundColor.green, backgroundColor.blue, 0); tool.reDraw(point, line, triangle, quad, pencil, usedColor, program); } // Green Background
	if (value == 12) { backgroundColor.red = 1.0f; backgroundColor.green = 1.0f; backgroundColor.blue = 0.0f; backgroundColor.colorName = (char*)"Jaune";
		glClearColor(backgroundColor.red, backgroundColor.green, backgroundColor.blue, 0); tool.reDraw(point, line, triangle, quad, pencil, usedColor, program); } // Yellow Background
	if (value == 13) { backgroundColor.red = 0.0f; backgroundColor.green = 0.0f; backgroundColor.blue = 0.0f; backgroundColor.colorName = (char*)"Noir"; 
		glClearColor(backgroundColor.red, backgroundColor.green, backgroundColor.blue, 0); tool.reDraw(point, line, triangle, quad, pencil, usedColor, program); } // Black Background
	if (value == 14) { backgroundColor.red = 1.0f; backgroundColor.green = 1.0f; backgroundColor.blue = 1.0f; backgroundColor.colorName = (char*)"Blanc"; 
		glClearColor(backgroundColor.red, backgroundColor.green, backgroundColor.blue, 0); tool.reDraw(point, line, triangle, quad, pencil, usedColor, program); } // White Background
	if (value == 16) { backgroundColor.red = rand() % 255 / 255.0; backgroundColor.green = (rand() % 255) / 255.0; backgroundColor.blue = (rand() % 255) / 255.0;
		backgroundColor.colorName = (char*)"Random";
		glClearColor(backgroundColor.red, backgroundColor.green, backgroundColor.blue, 0); tool.reDraw(point, line, triangle, quad, pencil, usedColor, program); } // Random Background
	if (value == 4) { tool.setSelectedTool(1); /*painting.ClearWindow(point, line, triangle, quad, pencil); */} // Point tool
	if (value == 5) { tool.setSelectedTool(2);/* painting.ClearWindow(point, line, triangle, quad, pencil);*/ } // Line tool
	if (value == 6) { tool.setSelectedTool(3); /*painting.ClearWindow(point, line, triangle, quad, pencil); */} // Triangle tool
	if (value == 7) { tool.setSelectedTool(4); /*painting.ClearWindow(point, line, triangle, quad, pencil); */} // Quadrilateral tool
	if (value == 17) { tool.setSelectedTool(5); /*painting.ClearWindow(point, line, triangle, quad, pencil);*/ } // Pencil tool
	if (value == 0) { painting.ClearWindow(point, line, triangle, quad, pencil); glDeleteProgram(program); glutLeaveMainLoop(); } // Exit
	if (value == -1) { painting.ClearWindow(point, line, triangle, quad, pencil); } // Erase

	cout << "La couleur actuellement choisie est : " << usedColor.colorName << endl;
	cout << "L'outil actuellement choisi est : " << tool.getSelectedTool() << endl << endl;
	glutPostRedisplay();
}

void createMouseMenu()
{
	int mainMenu, toolColorSubMenu, backgroundColorSubMenu, shapesSubMenu;
	toolColorSubMenu = glutCreateMenu(handleMenuFunctions);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Blue", 2);
	glutAddMenuEntry("Green", 3);
	glutAddMenuEntry("Yellow", 8);
	glutAddMenuEntry("Aléatoire", 15);

	backgroundColorSubMenu = glutCreateMenu(handleMenuFunctions);
	glutAddMenuEntry("Red", 9);
	glutAddMenuEntry("Blue", 10);
	glutAddMenuEntry("Green", 11);
	glutAddMenuEntry("Yellow", 12);
	glutAddMenuEntry("Black", 13);
	glutAddMenuEntry("White", 14);
	glutAddMenuEntry("Random", 16);

	shapesSubMenu = glutCreateMenu(handleMenuFunctions);
	glutAddMenuEntry("Point", 4);
	glutAddMenuEntry("Line", 5);
	glutAddMenuEntry("Triangle", 6);
	glutAddMenuEntry("Quadrilateral", 7);
	glutAddMenuEntry("Pencil", 17);


	mainMenu = glutCreateMenu(handleMenuFunctions);
	glutAddSubMenu("Color", toolColorSubMenu);
	glutAddSubMenu("Background", backgroundColorSubMenu);
	glutAddSubMenu("Shapes", shapesSubMenu);
	glutAddMenuEntry("Erase", -1);
	glutAddMenuEntry("Exit", 0);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void handleMouse(int button, int state, int x, int y)
{
	float Xndc = x * (2.0) / glutGet(GLUT_WINDOW_WIDTH) - 1.0;
	float Yndc = -(y - glutGet(GLUT_WINDOW_HEIGHT)) * (1.0 + 1.0) / glutGet(GLUT_WINDOW_HEIGHT) - 1.0;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && tool.getSelectedTool() == (char*)"Point") { point.Draw(Xndc, Yndc, random, usedColor, program); }
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && tool.getSelectedTool() == (char*)"Ligne") { line.Process(Xndc, Yndc, random, usedColor, program); }
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && tool.getSelectedTool() == (char*)"Triangle") { triangle.Process(Xndc, Yndc, random, usedColor, program); }
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && tool.getSelectedTool() == (char*)"Quadrilateral") { quad.Process(Xndc, Yndc, random, usedColor, program); }
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && tool.getSelectedTool() == (char*)"Pencil") { pencil.Process(Xndc, Yndc, random, usedColor, program); }
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) { std::cout << "y : " << y << " Yndc : " << Yndc << std::endl; }
}

void handleMouseMove(int x, int y)
{
	float Xndc = x * (2.0) / glutGet(GLUT_WINDOW_WIDTH) - 1.0;
	float Yndc = -(y - glutGet(GLUT_WINDOW_HEIGHT)) * (1.0 + 1.0) / glutGet(GLUT_WINDOW_HEIGHT) - 1.0;
	if (tool.getSelectedTool() == (char*)"Pencil") { pencil.Process(Xndc, Yndc, random, usedColor, program); }
}



//Fonction principale d'exécution
int main(int argc, char **argv)
{
	ShaderLoader shader;
	// Set initial values
	usedColor.red = 0.0f; usedColor.green = 1.0f; usedColor.blue = 0.0f; usedColor.colorName = (char*)"Vert";
	backgroundColor.red = 1.0f; backgroundColor.green = 1.0f; backgroundColor.blue = 1.0f; backgroundColor.colorName = (char*)"Blanc";
	tool.setSelectedTool(1);

	// Window Instantiation
	glutInit(&argc, argv);
	painting = GlutWindow(windowWidth, windowHeight, (char*)"Travail Pratique 1");
	glClearColor(backgroundColor.red, backgroundColor.green, backgroundColor.blue, 0); tool.reDraw(point, line, triangle, quad, pencil, usedColor, program);

	//Fonctions de rappel
	glutDisplayFunc(displayScene);
	glutMouseFunc(handleMouse);
	glutMotionFunc(handleMouseMove);

	program = shader.CreateProgram((char*)"vertexShader.glsl", (char*)"fragmentShader.glsl");

	createMouseMenu();

	glutMainLoop();
	return 0;
}