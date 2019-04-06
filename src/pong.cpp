#include "pong.h"
#include "shapes.h"

Pong::Pong() {
	int centerY = height / 2;

	int userPaddleX = paddleXOffset;
	int cpuPaddleX = width - paddleXOffset;
	int paddleY = centerY - paddleHeight / 2;
	
	userPaddle = Rect(userPaddleX, paddleY, paddleWidth, paddleHeight);
	cpuPaddle =  Rect(cpuPaddleX, paddleY, paddleWidth, paddleHeight);
}

void Pong::drawStart() {
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2i(10,80);
    glVertex2i(10,150);
    glVertex2i(20,150);
    glVertex2i(20,80);
    glEnd();
}

void Pong::drawGame() {
	
}

void Pong::drawEnd() {
	
}


void Pong::timestep() {

}
