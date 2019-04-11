#include "pong.h"
#include "shapes.h"
#include "rect.h"
#include "circle.h"
#include "Button.h"

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
        drawString("You have beat the Computer!");
    }
    if (userScore < cpuScore) {
        drawString("You have lost to the Computer!");
    }
    if (userScore == cpuScore) {
        drawString("You have tied the Computer!");
    }

    // Play again button
    Quad box2({1, 0, 0}, {240, 320}, 200, 50);
    Button button(box2, "Play Again?");
    button.draw();
    //TODO: set to start screen and get button to work
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

void Pong::drawString(string label) {
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2i(120, 150);
    for (char &letter : label)  {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, letter);
    }
    glEnd();
}
