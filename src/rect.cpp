//
// Created by jacel on 4/6/2019.
//

#include "rect.h"
#include <iostream>

Rect::Rect() : Shape(), width(0), length(0) {}

Rect::Rect(double width, double length) : Shape() {
    this->width = width;
    this->length = length;
}

double Rect::get_width() const {
    return width;
}

double Rect::get_length() const {
    return length;
}

void Rect::set_width(const double& width) {
    if (width >= 0) {
        this->width = width;
    }
}

void Rect::set_length(const double& length) {
    if (length >= 0) {
        this->length = length;
    }
}

double Rect::get_area() const {
    return length * width;
}

double Rect::get_perimeter() const {
    return 2 * length + 2 * width;
}

void Rect::draw() const {

}

std::ostream& Rect::doprint(std::ostream& out) const {
    out << "rectangle centered at (" << x << "," << y << "); width, length: " << width << ", " << length;
    return out;
}
