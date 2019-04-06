#include "graphics.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include "shapes.h"
#include "rect.h"
#include "circle.h"

using namespace std;

GLdouble width, height;
int wd;

// 0 for start screen, 1 for game, 2 for end
int programState;

void init() {
	width = 900;
	height = 500;
}

/* Initialize OpenGL Graphics */
void initGL() {
	// Set "clearing" or background color
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);
    
    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);
    
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    /*
     * Draw here
     */
	int x = 500;
	int y = 200;

	Rect rect;

	rect.setWidth(10);
	rect.setLength(20);
	rect.setX(30);
	rect.setY(30);
	rect.draw();

	switch(programState) {
	case 0: {
		glColor3f(1.0, 0.0, 1.0);
		glBegin(GL_QUADS);

		glColor3f(0.7, 0.0, 1.0);
		glVertex2i(10 + 50 + 200, 80 + 50);

		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(10 + 50, 90 + 100);

	

		glColor3f(0.0, 1.0, 0.0);
		glVertex2i(20 + 100 + 200, 80 + 50);

		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(20 + 100, 90 + 100);
	
		glEnd();
		// Circle Test
		glColor3f(1.0, 0.0, 0.3);
		Circle circle(15.0);
		circle.setX(300);
		circle.setY(200);
		circle.draw();

		break;
	}
		
	case 1: {
	
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2i(x, y);
		glVertex2i(x + 100, y + 100);
		glVertex2i(x + 100, y);

		glVertex2i(x + 200, y + 200);
		glVertex2i(x + 200 + 100, y + 100 + 200);
		glVertex2i(x + 200 + 100, y + 200);
		glEnd();

		x = 50;
		y = 250;

		glColor3f(0.5, 0.5, 1.0);
		glBegin(GL_TRIANGLE_STRIP);
		glVertex2i(x, y);
		glVertex2i(x, y + 100);
		glVertex2i(x + 100, y + 100);
		glVertex2i(x + 200, y + 200);
		glVertex2i(x + 150, y + 200);
		glEnd();
		break;
	}
		
	case 2: {
		x = 700;
		y = 10;

		glColor3f(1.0, 0.0, 0.3);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2i(x, y + 100);
		glVertex2i(x, y);
		glVertex2i(x + 100, y + 100);
		glVertex2i(x + 200, y + 200);
		glVertex2i(x + 150, y + 200);
		glEnd();
		break;
	}
	}
	glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    } else if (key == 97) {
		programState = (programState + 1) % 3;
	}

    
	glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
    case GLUT_KEY_DOWN:

        break;
    case GLUT_KEY_LEFT:

        break;
    case GLUT_KEY_RIGHT:

        break;
    case GLUT_KEY_UP:

        break;
}
    
    glutPostRedisplay();
}

void cursor(int x, int y) {
    
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    
    glutPostRedisplay();
}

void timer(int dummy) {
    
    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    
    init();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(-100, 400); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Lots of Fun with Drawing!" /* title */ );
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    
    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // handles timer
    glutTimerFunc(0, timer, 0);

	// Enter the event-processing loop
    glutMainLoop();
    return 0;
}
