 <h1 align="center">OpenGL Basic Drawing</h1> 
  <p align="center">
  <img src="https://img.shields.io/badge/License-MIT-blue.svg"><br>
  Made with FreeGlut, Glew and OpenGL in C++
  </p>

 > 👨‍🎨 Practical Work 1 in Infography at Cegep Lévis-Lauzon. Put our knowledge of OpenGL into practice to create a basic drawing program.  🎨  🖌 

#### Part 1 : Draw Points

Each item that will be displayed in my monitor will have to be stored in a vector, in order to be able to add some while being able to see our previous input.
With this approach, it will be possible to change the color easily, while allowing each item to have a different color.

Here's an example :

```c++
for (int i = 0; i < Size(); i+=4) {
		GLfloat cpyVertex[4] = {
		pointGrid[i], pointGrid[i+1], pointGrid[i+2], pointGrid[i+3],
		};
		GLfloat cpyVertexColor[4] = {
			pointColorGrid[i], pointColorGrid[i+1], pointColorGrid[i+2], pointColorGrid[i+3],
		};
		// put the vertex buffer on gpu
		glGenBuffers(1, &vertexBuffer); // generate opengl buffer
		glEnableVertexAttribArray(0); // allocate address 0 to link our vbo
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); // link vbo to vertex buffer attribute
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertex), &cpyVertex, GL_STREAM_DRAW); // insert data to buffer
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
		// put the color buffer on gpu
		glGenBuffers(1, &colorBuffer);
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cpyVertexColor), &cpyVertexColor, GL_STREAM_DRAW);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
		// draw
		glUseProgram(program);
		glPointSize(15);
		glDrawArrays(GL_POINTS, 0, Size() / 4);
		glDisableVertexAttribArray(0);
	}
```

Every tool we draw will be stored in a class and will have its own properties. In the case of the dot, we will be able 
to get the total amount of dots and the name of the tool easily :
```c++
int Point::Size()
{
	return pointGrid.size();
}

char* Point::Name() {
	return (char*)"Point";
}
```
<p align="center">
  <img src="https://user-images.githubusercontent.com/33030290/45921223-772a4280-be66-11e8-9e26-565291587747.png"><br>
  </p>

#### Part 2 : Draw lines

As for the structure of the object, the rest of the program will be pretty much like what I did with the point. 
The only remarkable difference with a tool like the line is that I will have to receive two coordinates, 
since I will have to delimit both ends of the line.

We will therefore drop the values of our first coordinate into a temporary array, which we will reuse later in our drawing method.
To do so, we will need another method that will handle which function will have to be called according to the number of clicks that have been made by the user.

```c++
void Line::Process(float x, float y, RGBCOLOR color, GLuint program)
{
	if (!isClicked()) {
		Init(x, y);
	}
	else {
		Draw(x, y, color, program);
	}
}
```

<p align="center">
  <img src="https://user-images.githubusercontent.com/33030290/45921227-83ae9b00-be66-11e8-86ba-b3d5bbfe33e6.png"><br>
  </p>

The same procedure will follow for triangles and quadrilaterals, by simply adding more temporary tables and managing
how the execution of functions will be called with our `Process()` method.

#### Part 3 : Colors

For the color part, it will be easier to handle them if we use a structure that will manage the hue of red, green and blue. Let's call it `RGBCOLOR`.

```c++
struct RGBCOLOR {
	float red;
	float green;
	float blue;
	char* colorName;
};
```

With that made, we will be able to manage the color used and apply it to all our objects when a user will choose one.

```c++
if (value == 1) {
  usedColor.red = 1.0f; 
  usedColor.green = 0.0f;
  usedColor.blue = 0.0f; 
  usedColor.colorName = (char*)"Rouge"; 
} // red
```


<p align="center">
  <img src="https://user-images.githubusercontent.com/33030290/45921242-c3758280-be66-11e8-83b5-351267c0b518.png"><br>
  </p>

#### Part 4 : UX

To be able to properly match the operation of our application with the functions that are attached to it, it would be useful to create a way to interact with the user. 
That's why we're going to use `FreeGlut`. For more information on this great library that looks like Windows 95, click [here](http://freeglut.sourceforge.net/).

I created a very simplistic user menu with few commands, which will be perfect to perform our few different manipulations of tools and colors.
Here is an example of what your code might look like for your user interface :

```c++
void createMouseMenu()
{
	int mainMenu, colorSubMenu, shapesSubMenu;
	colorSubMenu = glutCreateMenu(handleMenuFunctions);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Blue", 2);
	glutAddMenuEntry("Green", 3);
	glutAddMenuEntry("Yellow", 8);

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
```
It does not require more than that to allow your user to interact with the functions of your program !

> This project has been made by William Garneau. 

#### This project is currently under development. If you have good ideas, do not hesitate to contribute! 😊
