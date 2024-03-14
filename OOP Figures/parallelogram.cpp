#include "parallelogram.h"

double Parallelogram::getArea() const
{
    double area = 0.0;
    if (point1_.y_ == point2_.y_)
        area = frameRect_.height_ * abs(point1_.x_ - point2_.x_);
    else
        area = frameRect_.height_ * abs(point3_.x_ - point2_.x_);
    return area;
}

rectangle_t Parallelogram::getFrameRect() const
{
    return frameRect_;
}

void Parallelogram::move(point_t center)
{
    double deltaX = center.x_ - frameRect_.pos_.x_;
    double deltaY = center.y_ - frameRect_.pos_.y_;
    frameRect_.pos_.x_ += deltaX;
    frameRect_.pos_.y_ += deltaY;
    point1_.x_ += deltaX;
    point1_.y_ += deltaY;
    point2_.x_ += deltaX;
    point2_.y_ += deltaY;
    point3_.x_ += deltaX;
    point3_.y_ += deltaY;
}

void Parallelogram::move(double x, double y)
{
    point1_.x_ += x;
    point1_.y_ += y;
    point2_.x_ += x;
    point2_.y_ += y;
    point3_.x_ += x;
    point3_.y_ += y;
    frameRect_.pos_.x_ += x;
    frameRect_.pos_.y_ += y;
}

void Parallelogram::scale(double coefficient)
{
    frameRect_.height_ *= coefficient;
    frameRect_.width_ *= coefficient;
    double deltaX = point1_.x_ - frameRect_.pos_.x_;
    double deltaY = point1_.y_ - frameRect_.pos_.y_;
    deltaX *= coefficient;
    deltaY *= coefficient;
    point1_.x_ = frameRect_.pos_.x_ + deltaX;
    point1_.y_ = frameRect_.pos_.y_ + deltaY;
    deltaX = point2_.x_ - frameRect_.pos_.x_;
    deltaY = point2_.y_ - frameRect_.pos_.y_;
    deltaX *= coefficient;
    deltaY *= coefficient;
    point2_.x_ = frameRect_.pos_.x_ + deltaX;
    point2_.y_ = frameRect_.pos_.y_ + deltaY;
    deltaX = point3_.x_ - frameRect_.pos_.x_;
    deltaY = point3_.y_ - frameRect_.pos_.y_;
    deltaX *= coefficient;
    deltaY *= coefficient;
    point3_.x_ = frameRect_.pos_.x_ + deltaX;
    point3_.y_ = frameRect_.pos_.y_ + deltaY;
}

void Parallelogram::scale(double x, double y, double coefficient)
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

std::string Parallelogram::getName() const
{
    return "PARALLELOGRAM";
}

Shape* Parallelogram::clone() const
{
    return new Parallelogram(*this);
}
