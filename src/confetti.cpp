#include "confetti.h"
#include "pong.h"
#include "quad.h"
#include "memory"
#include "shapes.h"

Confetti::Confetti() {
	spawnConfetti();
}

void Confetti::draw() {
	for (const auto& p: confetti) {
		p->draw();
	}
	timestep();
}

void Confetti::spawnConfetti() {
	for (int i = 0; i < 50; ++i) {
		if (i % 5 == 0) {
			Circle circle(rand() % Pong::width, rand() % Pong::height, radius);
			circle.setFill({rand() % 10 / 10.0, rand() % 10 / 10.0, rand() % 10 / 10.0});
			confetti.push_back(make_unique<Circle>(circle));
		} else {

			// color c({rand() % 10 / 15.0, 0, rand() % 10 / 15.0});
			// point p({rand() % Pong::width, rand() % Pong::height});
			Quad quad({rand() % 10 / 10.0, rand() % 10 / 10.0, rand() % 10 / 10.0},
					  {rand() % Pong::width, rand() % Pong::height}, quadSize, quadSize);
			confetti.push_back(make_unique<Quad>(quad));

		}
	}
}

void Confetti::timestep() {
	for (auto &p : confetti) {
		int deltaY = 1;
		int deltaX = (rand() % (int) 3) * pow(-1, rand() % 20);
		p->setX(p->getX() + deltaX);
		p->setY(p->getY() + deltaY);
		if (p->getY() > Pong::height) {
			p->setY(0);
		}
	}
}
