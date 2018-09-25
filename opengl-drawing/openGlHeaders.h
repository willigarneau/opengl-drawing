// This is the regroupment of every needed dependency in the project

// --- STRUCTURES
struct RGBCOLOR {
	float red;
	float green;
	float blue;
	char* colorName;
};

// -- MODULES
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <iostream>
#include "ShaderLoader.h"
#include "GlutWindow.h"
#include "Point.h"
#include "Tool.h"
#include "GlutWindow.h"
#include "Triangle.h"
#include "Quadrilateral.h"
#include "Line.h"
#include "Pencil.h"
#include <vector>
#include <cstdlib>

// - NAMESPACES
using namespace std;