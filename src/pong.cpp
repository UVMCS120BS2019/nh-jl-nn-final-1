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
        Quad box({1, 0, 0}, {260, 100}, 350, 50);
        Button message(box, "You have beat the Computer!");
        message.draw();
    }
    if (userScore < cpuScore) {
        Quad box({1, 0, 0}, {260, 100}, 350, 50);
        Button message(box, "You have lost to the Computer!");
        message.draw();
    }
    if (userScore == cpuScore) {
        Quad box({1, 0, 0}, {260, 100}, 350, 50);
        Button message(box, "You have tied the Computer!");
        message.draw();
    }

    // Play again button
    Quad box2({1, 0, 0}, {260, 320}, 200, 50);
    Button button(box2, "Play Again?");
    button.draw();
    //TODO: set to start sceen
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
