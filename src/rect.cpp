//
// Created by jacel on 4/6/2019.
//
#include "graphics.h"
#include "rect.h"
#include <iostream>

Rect::Rect() : Shape(), width(0), height(0) {}

Rect::Rect(double width, double height) : Shape() {
    this->width = width;
    this->height = height;
}

double Rect::getWidth() const {
    return width;
}

double Rect::getHeight() const {
    return height;
}

void Rect::setWidth(const double& width) {
    if (width >= 0) {
        this->width = width;
    }
}

void Rect::setHeight(const double& height) {
    if (height >= 0) {
        this->height = height;
    }
}

void Rect::draw() const {
    struct point{
        double xValue;
        double yValue;
    };

    point cord1, cord2,cord3, cord4;

    cord1.xValue = x;
    cord1.yValue = y;

    cord2.xValue = x;
    cord2.yValue = y + height;

    cord3.xValue = x + width;
    cord3.yValue = y + height;

    cord4.xValue = x + width;
    cord4.yValue = y;

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2i(cord1.xValue, cord1.yValue);
    glVertex2i(cord2.xValue, cord2.yValue);
    glVertex2i(cord3.xValue,cord3.yValue);
    glVertex2i(cord4.xValue,cord4.yValue);
    glEnd();
}

std::ostream& Rect::doprint(std::ostream& out) const {
    out << "rectangle centered at (" << x << "," << y << "); width, length: " << width << ", " << height;
    return out;
}
