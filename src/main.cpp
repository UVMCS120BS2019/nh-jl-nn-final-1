#include "graphics.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include "shapes.h"
#include "circle.h"
#include "pong.h"
#include "Button.h"
using namespace std;

GLdouble width, height;
int wd;
int lastTick;
int gameDelay;

Pong pong(&gameDelay, &lastTick);

// keep track of whether each key is pressed down
bool keyState[256] = {false};

// 0 for start screen, 1 for game, 2 for end
enum state {start, game, end};
state programState;

void setProgramStateStart() {
	programState = state::start;
	pong.restartGame();
}

void setProgramStateGame() {
	programState = state::game;
}

void init() {
	width = Pong::width;
	height = Pong::height;
	lastTick = 0;
}

/* Initialize OpenGL Graphics */
void initGL() {
	// Set "clearing" or background color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
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
    
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with current clearing color
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    switch(programState) {
        case state::start: {
            pong.drawStart();
            break;
        }
        case state::game: {
            pong.drawGame();
            // if we reach max score, go to end screen
            if (pong.isOver()) {
                programState = state::end;
            }
            break;
        }
        case state::end: {
            pong.drawEnd();
            break;
        }
    }
	glFlush();  // Render now
	timer(0);
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    } else if (key == 97) {
		if (programState == state::start) {
			programState = state::game;			
		} else if (programState == state::game) {
			programState = state::end;
		} else {
			programState = state::start;
		}
	}
	glutPostRedisplay();
}

// https://cboard.cprogramming.com/game-programming/80515-glut-keyboard-reaction-help.html
void keySpecialDownFunc(int key, int x, int y) {
	keyState[key] = true;
	glutPostRedisplay();
}

void keySpecialUpFunc(int key, int x, int y) {
	keyState[key] = false;
	glutPostRedisplay();
}

// For play again button
void cursor(int x, int y) {
    if (pong.getButton().isOverlapping(x, y)) {
        pong.buttonHover();
    } else {
        pong.buttonRelease();
    }

    if (pong.getButton2().isOverlapping(x, y)) {
        pong.buttonHover2();
    } else {
        pong.buttonRelease2();
    }
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
////////////// For play again button /////////////////////////
void mouse(int button, int state, int x, int y) {
	if (programState == state::end) {
		if (state == GLUT_DOWN &&
			button == GLUT_LEFT_BUTTON &&
			pong.getButton().isOverlapping(x, y)) {
			pong.buttonPressDown();
		} else {
			pong.buttonRelease();
		}

		if (state == GLUT_UP &&
			button == GLUT_LEFT_BUTTON &&
			pong.getButton().isOverlapping(x, y)) {
			pong.buttonClick();
		}
	}

	if (programState == state::start) {

		if (state == GLUT_DOWN &&
			button == GLUT_LEFT_BUTTON &&
			pong.getButton2().isOverlapping(x, y)) {
			pong.buttonPressDown2();
		} else {
			pong.buttonRelease2();
		}

		if (state == GLUT_UP &&
			button == GLUT_LEFT_BUTTON &&
			pong.getButton2().isOverlapping(x, y)) {
			pong.buttonClick2();
		}
	}
	glutPostRedisplay();
}

void timer(int dummy) {
	int tick = glutGet(GLUT_ELAPSED_TIME);
	if (tick < lastTick) {
		return;
	}
	while (tick > lastTick) {
		
		if (programState == state::game) {
			// move up and down
			if (keyState[GLUT_KEY_UP]) {
				pong.moveUp();
			}
			if (keyState[GLUT_KEY_DOWN]) {
				pong.moveDown();
			}
			if (tick > gameDelay) {
				pong.timestep();
			}
		}

		lastTick += 1000 / 45;
		
	}
	glutPostRedisplay();
}

void callDisplay(int dummy) {
	display();
	glutPostRedisplay();
	glutTimerFunc(0, callDisplay, 0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    
    init();
    
    glutInit(&argc, argv); // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(-100, 400); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Game of Pong" /* title */ );
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

	// register pressing down keys and releasing
	glutSpecialFunc(keySpecialDownFunc);
	glutSpecialUpFunc(keySpecialUpFunc);

	// don't repeat key presses
	glutIgnoreKeyRepeat(true);

	// register special event: function keys, arrows, etc.

    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // handles timer
    glutTimerFunc(0, callDisplay, 0);

	// Enter the event-processing loop
    glutMainLoop();
    return 0;
}
