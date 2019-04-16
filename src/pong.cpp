#include "pong.h"
#include <math.h>

Pong::Pong(int* gameDelay, int* lastTick) : box({1, 0, 0}, {240, 320}, 200, 50), button(box, "Play Again?") {
	int centerY = height / 2;

	int userPaddleX = paddleXOffset;
	int cpuPaddleX = width - paddleXOffset;
	
	userPaddle = Quad({1,1,1}, {userPaddleX, centerY}, paddleWidth, paddleHeight);
	cpuPaddle =  Quad({1,1,1}, {cpuPaddleX, centerY}, paddleWidth, paddleHeight);
	ball = Circle(width / 2, height / 2, ballRadius);

    box = Quad({1, 0, 0}, {240, 320}, 200, 50);
    button = Button(box, "Play Again?");
	shouldRestartRound = true;

	this->gameDelay = gameDelay;
	this->lastTick = lastTick;
}

void Pong::drawStart() {
    drawString("Welcome to Pong!");
}

void Pong::drawGame() {

	userPaddle.draw();
	cpuPaddle.draw();
	ball.draw();
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

	if (shouldRestartRound) {
		startRound();
	}
	
	int ballX = ball.getX();
	int ballY = ball.getY();

	deflectBall();

	// move cpu

	double heightDifference = ball.getY() - cpuPaddle.getCenterY();
	if (heightDifference < 0) {
		cpuPaddle.move(0, max(heightDifference, -1.0 * Pong::MAX_CPU_VELOCITY));
	} else {
		cpuPaddle.move(0, min(heightDifference, 1.0 * Pong::MAX_CPU_VELOCITY));
	}


	ball.setX(ballX + ballVelocity.getX());
	ball.setY(ballY + ballVelocity.getY());

	if (ball.getLeftX() < 0) {
		++cpuScore;
		userScoredLast = false;
		shouldRestartRound = true;
	} else if (ball.getRightX() > width) {
		++userScore;
		userScoredLast = true;
		shouldRestartRound = true;
	}
	

}



void Pong::deflectBall() {
	double power = 0;
	double MAX_ANGLE = M_PI / 3;
	double angle = 0;

	if (ball.getRightX() > cpuPaddle.getLeftX() && cpuPaddle.getTopY() < ball.getTopY() && cpuPaddle.getBottomY() > ball.getBottomY()) {
		
		power = 2.0 * (cpuPaddle.getCenterY() - ball.getCenterY()) / Pong::paddleHeight;
		angle = power * MAX_ANGLE;
		ballVelocity.setAngle(M_PI + angle);
		ballVelocity.multiplyMagnitude(1.05);

	} else if (ball.getLeftX() < userPaddle.getRightX() && userPaddle.getTopY() < ball.getBottomY() && userPaddle.getBottomY() > ball.getTopY() ) {

		power = 2.0 * (userPaddle.getCenterY() - ball.getCenterY()) / Pong::paddleHeight;
		angle = power * MAX_ANGLE;
		ballVelocity.setAngle(angle);
		ballVelocity.multiplyMagnitude(1.05);
		
	} else if (ball.getBottomY() > height && ballVelocity.getY() > 0) {
		ballVelocity *= Vec2d({1, -1});
	} else if (ball.getTopY() < 0 && ballVelocity.getY() < 0) {
		ballVelocity *= Vec2d({1, -1});
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

const Button& Pong::getButton() const {
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
    if(userPaddle.getBottomY() < height) {
        userPaddle.move(0, +10);
    }
}

void Pong::moveUp() {
    if(userPaddle.getTopY() > 0) {
        userPaddle.move(0, -10);
    }
}

void Pong::displayScore() {
    string stringUser = to_string(userScore);
    string stringCpu = to_string(cpuScore);
    drawScore("User Score: ", "  CPU Score: ", stringUser, stringCpu);
}

void Pong::startRound() {
	shouldRestartRound = false;
	ball.setX(width / 2);
	ball.setY(height / 2);
	
	// serve the ball to whoever didn't last score
	if (userScoredLast) {
		ballVelocity.set(Vec2d({4, rand() % 2 + 3}));	
	} else {
		ballVelocity.set(Vec2d({-4, rand() % 2 + 3}));
	}
	*gameDelay = *lastTick + 3000;
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

bool Pong::isOver() {
	return userScore >= Pong::WINNING_SCORE || cpuScore >= Pong::WINNING_SCORE;
}
