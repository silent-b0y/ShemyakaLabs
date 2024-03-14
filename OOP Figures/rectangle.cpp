#include "rectangle.h"

double Rectangle::getArea() const
{
	return (upperRightCorner_.x_ - lowerLeftCorner_.x_) * (upperRightCorner_.y_ - lowerLeftCorner_.y_);
}

struct rectangle_t Rectangle::getFrameRect() const
{
	return frameRect_;
}

void Rectangle::move(struct point_t center)
{
	double deltaX = center.x_ - frameRect_.pos_.x_;
	double deltaY = center.y_ - frameRect_.pos_.y_;
	lowerLeftCorner_.x_ += deltaX;
	upperRightCorner_.x_ += deltaX;
	lowerLeftCorner_.y_ += deltaY;
	upperRightCorner_.y_ += deltaY;
	frameRect_.pos_.x_ = center.x_;
	frameRect_.pos_.y_ = center.y_;
}

void Rectangle::move(double x, double y)
{
	lowerLeftCorner_.x_ += x;
	upperRightCorner_.x_ += x;
	lowerLeftCorner_.y_ += y;
	upperRightCorner_.y_ += y;
	frameRect_.pos_.x_ += x;
	frameRect_.pos_.y_ += y;
}

void Rectangle::scale(double coefficient)
{
	frameRect_.width_ *= coefficient;
	frameRect_.height_ *= coefficient;
	double scaleX = (upperRightCorner_.x_ - lowerLeftCorner_.x_) * coefficient / 2.0;
	double scaleY = (upperRightCorner_.y_ - lowerLeftCorner_.y_) * coefficient / 2.0;
	lowerLeftCorner_.x_ = frameRect_.pos_.x_ - scaleX;
	upperRightCorner_.x_ = frameRect_.pos_.x_ + scaleX;
	lowerLeftCorner_.y_ = frameRect_.pos_.y_ - scaleY;
	upperRightCorner_.y_ = frameRect_.pos_.y_ + scaleY;
}

void Rectangle::scale(double x, double y, double coefficient)
{
	rectangle_t frameRect1 = this->getFrameRect();
	point_t point1{ frameRect1.pos_.x_ - frameRect1.width_ / 2.0, frameRect1.pos_.y_ - frameRect1.height_ / 2.0 };
	this->move({ x, y });
	rectangle_t frameRect2 = this->getFrameRect();
	point_t point2{ frameRect2.pos_.x_ - frameRect2.width_ / 2.0, frameRect2.pos_.y_ - frameRect2.height_ / 2.0 };
	double deltaX = point1.x_ - point2.x_;
	double deltaY = point1.y_ - point2.y_;
	this->scale(coefficient);
	deltaX *= coefficient;
	deltaY *= coefficient;
	this->move(deltaX, deltaY);
}

std::string Rectangle::getName() const
{
	return "RECTANGLE";
}

Shape* Rectangle::clone() const
{
	return new Rectangle(*this);
}

