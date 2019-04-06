#ifndef PONG_H
#define PONG_H

#include "rect.h"
#include "circle.h"
#include "graphics.h"
#include "shapes.h"

class Pong {
private:
	const static int paddleXOffset = 20;
	const static int paddleHeight = 50;
	const static int paddleWidth = 10;
	const static int ballRadius = 8;
	
	
	Rect userPaddle;
	Rect cpuPaddle;
	Circle ball;
	double ballVelX;
	double ballVelY;


public:
	const static int width = 500;
	const static int height = 500;

	
	
	int userScore;
	int cpuScore;

	Pong();
	
	void drawStart();
	void drawGame();
	void drawEnd();

	void timestep();

};


#endif
