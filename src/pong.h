#ifndef PONG_H
#define PONG_H

#include "circle.h"
#include "graphics.h"
#include "shapes.h"
#include "shapes.h"
#include "Button.h"
using namespace std;

class Pong {
private:
	const static int paddleXOffset = 20;
	const static int paddleHeight = 50;
	const static int paddleWidth = 10;
	const static int ballRadius = 8;

    Quad box;
    Button button;
	Quad userPaddle;
	Quad cpuPaddle;
	Circle ball;
	double ballVelX;
	double ballVelY;

	bool shouldRestartRound;
	bool userScoredLast;
    int userScore;
    int cpuScore;

public:
	const static int width = 500;
	const static int height = 500;

	Pong();

	//////// These functions below are used to make play again button work
    void setButton(const Button &button);
    const Button &getButton() const;
    void buttonHover();
    void buttonRelease();
    void buttonPressDown();
    void buttonClick();
    /**************************************/

    void drawStart();
	void drawGame();
	void drawEnd();

	void moveDown();
	void moveUp();

	void timestep();
    void displayScore();
    void drawScore(string message, string message2, string userScore, string cpuScore);

	void deflectBall();
	
    void drawString(string label);

	bool roundIsOver();
	void playRound();

};


#endif
