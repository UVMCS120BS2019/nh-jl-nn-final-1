//
// Created by Lisa Dion on 10/3/18.
//

#include "shapes.h"

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