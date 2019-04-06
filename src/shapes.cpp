//
// Created by Lisa Dion on 10/3/18.
//

#include "shapes.h"

// get PI constant
#define _USE_MATH_DEFINES
#include <math.h>

// =========================== Shape ===========================

Shape::Shape() {
	x = 0;
	y = 0;
	fill = rgb(1,1,1);
	border = rgb(1,1,1);
}

int Shape::get_x() const {
	return x;	
}

int Shape::get_y() const {
	return y;
}

rgb Shape::get_fill() const {
	return fill;
}

rgb Shape::get_border() const {
	return border;
}

void Shape::set_x(const int &x) {
	this->x = x;
}

void Shape::set_y(const int &y) {
	this->y = y;
}

void Shape::set_fill(const rgb &fill) {
	this->fill = fill;
}

void Shape::set_border(const rgb &border) {
	this->border = border;
}

std::ostream& operator << (std::ostream& os, const Shape& sh) {
	return sh.doprint(os); // polymorphic print via reference
}

// =========================== Circle ===========================

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
	
}

std::ostream& Circle::doprint(std::ostream& out) const {
	out << "circle centered at (" << x << "," << y << "); radius: " << radius;
	return out;
}

// =========================== Rect ===========================
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
