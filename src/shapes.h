//
// Created by Lisa Dion on 10/3/18.
//

#ifndef SHAPES_SHAPES_H
#define SHAPES_SHAPES_H

#include <iostream>

struct rgb {
	double red;
	double green;
	double blue;
	rgb(double red, double green, double blue) {
		this->red = red;
		this->green = green;
		this->blue = blue;
	}
	rgb() = default;
};

// =========================== Shape ===========================
class Shape {
protected:
	int x;
	int y;
	rgb fill;
	rgb border;
	
	// helper function to allow << operator to be overridden in derived classes
	virtual std::ostream& doprint(std::ostream&) const = 0;

public:
	Shape();
	int get_x() const;
	int get_y() const;
	rgb get_fill() const;
	rgb get_border() const;

	void set_x(const int& x);
	void set_y(const int& y);
	void set_fill(const rgb &fill);
	void set_border(const rgb &border);

	virtual double get_area() const = 0;
	virtual double get_perimeter() const = 0;
	virtual void draw() const = 0;

	// calls doprint method of derived classes
    friend std::ostream& operator << (std::ostream& os, const Shape& sh);
	// polymorphic delete
	virtual ~Shape() {}
};

// =========================== Circle ===========================

// =========================== Rect =============================

#endif //SHAPES_SHAPES_H