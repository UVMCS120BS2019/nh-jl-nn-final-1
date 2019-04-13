#ifndef PONG_H
#define PONG_H

#include "rect.h"
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


public:
	const static int width = 500;
	const static int height = 500;

	int userScore;
	int cpuScore;

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

	void timestep();

	void deflectBall();
	
    void drawString(string label);
};


#endif
