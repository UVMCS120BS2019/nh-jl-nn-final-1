#include "pong.h"

Pong::Pong() : box({1, 0, 0}, {240, 320}, 200, 50), button(box, "Play Again?") {
	int centerY = height / 2;

	int userPaddleX = paddleXOffset;
	int cpuPaddleX = width - paddleXOffset;
	int paddleY = centerY - paddleHeight / 2;
	
	userPaddle = Rect(userPaddleX, paddleY, paddleWidth, paddleHeight);
	cpuPaddle =  Rect(cpuPaddleX, paddleY, paddleWidth, paddleHeight);
	ball = Circle(width / 2, height / 2, ballRadius);

    box = Quad({1, 0, 0}, {240, 320}, 200, 50);
    button = Button(box, "Play Again?");

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
    button.draw();
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

// Function to draw strings
void Pong::drawString(string label) {
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2i(120, 150);
    for (char &letter : label)  {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, letter);
    }
    glEnd();
}

////////// Functions to make Play Again button work ///////////////////////
void Pong::setButton(const Button &button) {
    Pong::button = button;
}

const Button &Pong::getButton() const {
    return button;
}

void Pong::buttonHover() {
    button.hover();
}

void Pong::buttonRelease() {
    button.release();
}

void Pong::buttonPressDown() {
    button.pressDown();
}

void Pong::buttonClick() {
    button.click(setProgramState);
}

void Pong::moveDown(){
    userPaddle;
}
void Pong::moveUp() {
    userPaddle;
}