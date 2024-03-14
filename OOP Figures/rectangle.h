#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
#include "base-types.h"

class Rectangle : public Shape
{
public:
	Rectangle(double x1, double y1, double x2, double y2):
		lowerLeftCorner_(point_t{ x1, y1 }),
		upperRightCorner_(point_t{ x2, y2 }),
		frameRect_(rectangle_t{ x2 - x1, y2 - y1, point_t { (x1 + x2) / 2.0, (y1 + y2) / 2.0}})
	{
		if (x2 <= x1 || y2 <= y1)
			throw std::invalid_argument("Wrong figure");
	}
	Rectangle(const Rectangle& rect):
		lowerLeftCorner_(rect.lowerLeftCorner_),
		upperRightCorner_(rect.upperRightCorner_),
		frameRect_(rect.frameRect_)
	{}
	double getArea() const override;
	struct rectangle_t getFrameRect() const override;
	void move(struct point_t) override;
	void move(double, double) override;
	void scale(double) override;
	void scale(double, double, double) override;
	std::string getName() const override;
	Shape* clone() const override;
private:
	point_t lowerLeftCorner_;
	point_t upperRightCorner_;
	rectangle_t frameRect_;
};

#endif
