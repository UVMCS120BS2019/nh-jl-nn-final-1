#include "pong.h"

Pong::Pong() {
	int centerY = height / 2;

	int userPaddleX = paddleXOffset;
	int cpuPaddleX = width - paddleXOffset;
	int paddleY = centerY - paddleHeight / 2;
	
	userPaddle = Rect(userPaddleX, paddleY, paddleWidth, paddleHeight);
	cpuPaddle =  Rect(cpuPaddleX, paddleY, paddleWidth, paddleHeight);
}

void Pong::drawStart() {
	
}

void Pong::drawGame() {
	
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

}
