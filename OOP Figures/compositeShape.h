#pragma once
#ifndef COMPOSITESHAPE_H
#define COMPOSITESHAPE_H
#include "shape.h"

class CompositeShape : public Shape
{
public:
	CompositeShape(int maxN):
		maxN_(maxN),
		realN_(0)
	{
		if (maxN <= 0)
			throw std::invalid_argument("Wrong figure");
		figures_ = new Shape * [maxN_];
	}
	CompositeShape(const CompositeShape& figure):
		maxN_(figure.maxN_),
		realN_(figure.realN_)
	{
		figures_ = new Shape * [maxN_];
		for (int i = 0; i < realN_; ++i)
			figures_[i] = figure.figures_[i]->clone();
	}
	CompositeShape(CompositeShape&& obj) noexcept :
		maxN_(0),
		realN_(0)
	{
		maxN_ = obj.maxN_;
		realN_ = obj.realN_;
		figures_ = obj.figures_;
		obj.maxN_ = 0;
		obj.realN_ = 0;
		obj.figures_ = nullptr;
	}
	~CompositeShape()
	{
		for (int i = 0; i < realN_; ++i)
			delete[] figures_[i];
		delete[] figures_;
	}
	double getArea() const override;
	rectangle_t getFrameRect() const override;
	void move(point_t) override;
	void move(double, double) override;
	void scale(double) override;
	void scale(double, double, double) override;
	std::string getName() const override;
	Shape* clone() const override;
	void addNew(Shape* figure);
	int getReal() const;
	CompositeShape& operator=(const CompositeShape&);
	CompositeShape& operator=(CompositeShape&&) noexcept;
private:
	int maxN_;
	int realN_;
	Shape** figures_;
};

#endif // !COMPOSITESHAPE_H
