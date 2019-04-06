#include "pong.h"


Pong::Pong() {
	int centerY = height / 2;

	int userPaddleX = paddleXOffset;
	int cpuPaddleX = width - paddleXOffset;
	int paddleY = centerY - paddleHeight / 2;
	
	userPaddle = Rect(userPaddleX, paddleY, paddleWidth, paddleHeight);
	cpuPaddle =  Rect(cpuPaddleX, paddleY, paddleWidth, paddleHeight);
	ball = Circle(width / 2, height / 2, ballRadius);

	ballVelX = 4;
	ballVelY = 0.5;
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
	userPaddle.draw();
	cpuPaddle.draw();
	ball.draw();
	timestep();
}

void Pong::drawEnd() {
    if (userScore > cpuScore) {

    }
    if (userScore < cpuScore) {

    }
    if (userScore == cpuScore) {

    }
}

void Pong::timestep() {
	int ballX = ball.getX();
	int ballY = ball.getY();
	if (ballX + ball.getRadius() <= userPaddle.getX() ||
		ballX + ball.getRadius() >= cpuPaddle.getX()) {
		ballVelX *= -1;
		
	}
	ball.setX(ballX + ballVelX);
	ball.setY(ballY + ballVelY);

}
