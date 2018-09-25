#include "openGlHeaders.h"

GlutWindow::GlutWindow() {}

GlutWindow::GlutWindow(int windowWidth, int windowHeight, char* windowName)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow((char*)windowName);
	glewInit();

	cout << "Bienvenue dans l'outil de dessin" << endl << "Pour commencer, veuillez choisir un outil et une couleur." << endl << endl;
}

void GlutWindow::ClearWindow(Point p, Line l, Triangle t, Quadrilateral q, Pencil pen) {
	p.Clear();
	l.Clear();
	t.Clear();
	q.Clear();
	pen.Clear();
}
