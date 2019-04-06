#ifndef PONG_H
#define PONG_H

#include "rect.h"
#include "circle.h"
#include "graphics.h"

class Pong {
	Rect userPaddle;
	Rect cpuPaddle;
	Circle ball;
	int userScore;
	int cpuScore;

	void drawStart();
	void drawGame();
	void drawEnd();

	void timestep();

	
	
};


#endif
