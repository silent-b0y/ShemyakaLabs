#pragma once
#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include "shape.h"

class Parallelogram : public Shape
{
public:
	Parallelogram(double x1, double y1, double x2, double y2, double x3, double y3) :
		point1_({ x1, y1 }),
		point2_({ x2, y2 }),
		point3_({ x3, y3 })
	{
		double a = std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		double b = std::sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
		double c = std::sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
		if ((y1 != y2) && (y3 != y2) || (a + b <= c) || (b + c <= a) || (c + a <= b))
			throw std::invalid_argument("Wrong figure");
		double xMax = 0;
		double xMin = 0;
		double yMax = 0;
		double height = 0;
		if (y1 == y2)
		{
			if (x2 > x1)
			{
				if (x3 >= x2)
				{
					xMax = x3;
					xMin = x1;
				}
				else
				{
					xMax = x2;
					xMin = x3 - (x2 - x1);
				}
			}
			else if (x1 > x2)
			{
				if (x3 <= x2)
				{
					xMax = x1;
					xMin = x3;
				}
				else
				{
					xMax = x3 + (x1 - x2);
					xMin = x2;
				}
			}
		}
		else if (y2 == y3)
		{
			if (x2 > x3)
			{
				if (x1 >= x2)
				{
					xMax = x1;
					xMin = x3;
				}
				else
				{
					xMax = x2;
					xMin = x1 - (x2 - x3);
				}
			}
			else if (x3 > x2)
			{
				if (x1 <= x2)
				{
					xMax = x3;
					xMin = x1;
				}
				else
				{
					xMax = x1 + (x3 - x2);
					xMin = x2;
				}
			}
		}
		if (y1 > y3)
			yMax = y1;
		else
			yMax = y3;
		height = abs(y3 - y1);
		frameRect_ = rectangle_t{ xMax - xMin, height, point_t{ (xMax + xMin) / 2.0, (yMax + (yMax - height)) / 2.0}};
	}
	Parallelogram(const Parallelogram& parall):
		point1_(parall.point1_),
		point2_(parall.point2_),
		point3_(parall.point3_),
		frameRect_(parall.frameRect_)
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
	point_t point1_;
	point_t point2_;
	point_t point3_;
	rectangle_t frameRect_;
};

#endif