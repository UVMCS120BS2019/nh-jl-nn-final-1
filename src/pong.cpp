#include "pong.h"

Pong::Pong() : box({1, 0, 0}, {240, 320}, 200, 50), button(box, "Play Again?") {
	int centerY = height / 2;

	int userPaddleX = paddleXOffset;
	int cpuPaddleX = width - paddleXOffset;
	
	userPaddle = Quad({1,1,1}, {userPaddleX, centerY}, paddleWidth, paddleHeight);
	cpuPaddle =  Quad({1,1,1}, {cpuPaddleX, centerY}, paddleWidth, paddleHeight);
	ball = Circle(width / 2, height / 2, ballRadius);

    box = Quad({1, 0, 0}, {240, 320}, 200, 50);
    button = Button(box, "Play Again?");

	ballVelX = 4;
	ballVelY = 0.5;
}

void Pong::drawStart() {
    drawString("Welcome to Pong!");
}

void Pong::drawGame() {
	userPaddle.draw();
	cpuPaddle.draw();
	ball.draw();
	timestep();
	displayScore();
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

	deflectBall();
	
	ball.setX(ballX + ballVelX);
	ball.setY(ballY + ballVelY);
}



void Pong::deflectBall() {
	if (ball.getRightX() > cpuPaddle.getLeftX()) {
		// double power = 2 * (cpuPaddle.getCenterY() - ball.getCenterY()) / Pong::paddleHeight;
		// double deflectionAngle = power * 90;
		ballVelX *= -1;
		
	} else if (ball.getLeftX() < userPaddle.getRightX()) {
		ballVelX *= -1;
	} else if (ball.getBottomY() > height) {
		ballVelY *= -1;
	} else if (ball.getTopY() < 0) {
		ballVelY *= -1;
	}
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

void Pong::moveDown() {
    userPaddle.move(0, +10);
}
void Pong::moveUp() {
    userPaddle.move(0, -10);
}

void Pong::displayScore() {
    string stringUser = to_string(userScore);
    string stringCpu = to_string(cpuScore);
    drawScore("User Score: ", "  CPU Score: ", stringUser, stringCpu);
}

void Pong::drawScore(string message, string message2, string userScore, string cpuScore) {
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2i(120, 30);
    for (char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, letter);
    }
    for (char &letter : userScore) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, letter);
    }
    for (char &letter : message2) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, letter);
    }
    for (char &letter : cpuScore) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, letter);
    }

    glEnd();
}