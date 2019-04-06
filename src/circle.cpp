//
// Created by jacel on 4/6/2019.
//

#include "circle.h"
#define _USE_MATH_DEFINES
#include <math.h>

Circle::Circle() : Shape(), radius(0) {}

Circle::Circle(int radius) : Shape() {
	this->radius = radius;
}

Circle::Circle(int x, int y, int radius) {
	this->x = x;
	this->y = y;
	this->radius = radius;
}

int Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(int radius) {
    if (radius >= 0) {
        this->radius = radius;
    }
}

void Circle::draw() const {
    int i;
    int triangleAmount = 30; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * M_PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)),
				   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

std::ostream& Circle::doprint(std::ostream& out) const {
    out << "circle centered at (" << x << "," << y << "); radius: " << radius;
    return out;
}
