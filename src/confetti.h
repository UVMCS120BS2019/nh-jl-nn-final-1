#ifndef CONFETTI_H
#define CONFETTI_H

#include "quad.h"
#include "shapes.h"
#include <vector>
#include <memory>

class Confetti {
private:
	const int quadSize = 6;
	const int radius = 10;
	std::vector<std::unique_ptr<Shape>> confetti;

public:
	Confetti();
	void draw();
	void spawnConfetti();
	void timestep();
};


#endif
