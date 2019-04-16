#ifndef PONG_H
#define PONG_H

#define _USE_MATH_DEFINES
#include <math.h>
#include "circle.h"
#include "graphics.h"
#include "shapes.h"
#include "Quad.h"
#include "Button.h"
#include "vec2d.h"
using namespace std;




class Pong {
private:
	const static int paddleXOffset = 20;
	const static int paddleHeight = 70;
	const static int paddleWidth = 10;
	const static int ballRadius = 8;

	const static int MAX_CPU_VELOCITY = 5;
	const static int WINNING_SCORE = 5;
	
	int* gameDelay;
	int* lastTick;
	
	Quad box;
	Button button;
	Quad userPaddle;
	Quad cpuPaddle;
	Circle ball;
	Vec2d ballVelocity;

	bool shouldRestartRound;
	bool userScoredLast;
	int userScore;
	int cpuScore;

public:
	const static int width = 500;
	const static int height = 500;

	Pong(int* gameDelay, int* lastTick);

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

	void startRound();

	// whether the game is over or not
	bool isOver();
};


#endif
