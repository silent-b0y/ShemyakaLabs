#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <cmath>
#include <iostream>
#include "base-types.h"

class Shape
{
public:
	virtual double getArea() const = 0;
	virtual struct rectangle_t getFrameRect() const = 0;
	virtual void move(struct point_t) = 0;
	virtual void move(double, double) = 0;
	virtual void scale(double) = 0;
	virtual void scale(double, double, double) = 0;
	virtual std::string getName() const = 0;
	virtual Shape* clone() const = 0;
	virtual ~Shape() = default;
	friend std::ostream& operator<<(std::ostream& out, const Shape& figure)
	{
		rectangle_t frameRect = figure.getFrameRect();
		out << figure.getName() <<
			" Area: " << round((figure.getArea()) * 10) / 10 <<
			" LowerLeftCorner: " << round((frameRect.pos_.x_ - frameRect.width_ / 2.0) * 10) / 10 <<
			" " << round((frameRect.pos_.y_ - frameRect.height_ / 2.0) * 10) / 10 <<
			" UpperRightCorner: " << round((frameRect.pos_.x_ + frameRect.width_ / 2.0) * 10) / 10 <<
			" " << round((frameRect.pos_.y_ + frameRect.height_ / 2.0) * 10) / 10;
		return out;
	}
	bool operator<(const Shape& figure) const
	{
		return this->getArea() < figure.getArea();
	}
};

#endif
