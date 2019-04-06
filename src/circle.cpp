//
// Created by jacel on 4/6/2019.
//

#include "circle.h"
#define _USE_MATH_DEFINES
#include <math.h>

Circle::Circle() : Shape(), radius(0) {}

Circle::Circle(double radius) : Shape() {
    this->radius = radius;
}

int Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(int radius) {
    if (radius >= 0) {
        this->radius = radius;
    }
}

double Circle::get_area() const {
    return M_PI * pow(radius, 2);
}

double Circle::get_perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::draw() const {
    //TODO:

}

std::ostream& Circle::doprint(std::ostream& out) const {
    out << "circle centered at (" << x << "," << y << "); radius: " << radius;
    return out;
}
