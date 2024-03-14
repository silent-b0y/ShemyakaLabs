#include "compositeShape.h"

double CompositeShape::getArea() const
{
    double sum = 0;
    for (int i = 0; i < realN_; ++i)
        sum += figures_[i]->getArea();
    return sum;
}

rectangle_t CompositeShape::getFrameRect() const
{
    double maxX = 0;
    double maxY = 0;
    double minX = 0;
    double minY = 0;
    if (realN_ != 0)
    {
        rectangle_t firstRect = figures_[0]->getFrameRect();
        maxX = firstRect.pos_.x_ + firstRect.width_ / 2.0;
        maxY = firstRect.pos_.y_ + firstRect.height_ / 2.0;
        minX = firstRect.pos_.x_ - firstRect.width_ / 2.0;
        minY = firstRect.pos_.y_ - firstRect.height_ / 2.0;
        for (int i = 1; i < realN_; ++i)
        {
            rectangle_t rect = figures_[i]->getFrameRect();
            if (rect.pos_.x_ + rect.width_ / 2.0 > maxX)
                maxX = rect.pos_.x_ + rect.width_ / 2.0;
            if (rect.pos_.y_ + rect.height_ / 2.0 > maxY)
                maxY = rect.pos_.y_ + rect.height_ / 2.0;
            if (rect.pos_.x_ - rect.width_ / 2.0 < minX)
                minX = rect.pos_.x_ - rect.width_ / 2.0;
            if (rect.pos_.y_ - rect.height_ / 2.0 < minY)
                minY = rect.pos_.y_ - rect.height_ / 2.0;
        }
    }
    return rectangle_t{ maxX - minX, maxY - minY, point_t{ (maxX + minX) / 2.0, (maxY + minY) / 2.0 } };
}

void CompositeShape::move(point_t center)
{
    rectangle_t frameRect = this->getFrameRect();
    double deltaX = center.x_ - frameRect.pos_.x_;
    double deltaY = center.y_ - frameRect.pos_.y_;
    for (int i = 0; i < realN_; ++i)
        figures_[i]->move(deltaX, deltaY);
}

void CompositeShape::move(double x, double y)
{
    for (int i = 0; i < realN_; ++i)
        figures_[i]->move(x , y);
}

void CompositeShape::scale(double coefficient)
{
    for (int i = 0; i < realN_; ++i)
        figures_[i]->scale(coefficient);
}

void CompositeShape::scale(double x, double y, double coefficient)
{
    for (int i = 0; i < realN_; ++i)
        figures_[i]->scale(x , y, coefficient);
}

std::string CompositeShape::getName() const
{
    return "COMPOSITESHAPE";
}

Shape* CompositeShape::clone() const
{
    CompositeShape* copy = new CompositeShape(maxN_);
    for (int i = 0; i < realN_; ++i)
        copy->addNew(figures_[i]->clone());
    return copy;
}

void CompositeShape::addNew(Shape* figure)
{
    if (realN_ < maxN_)
    {
        figures_[realN_] = figure;
        ++realN_;
    }
}

int CompositeShape::getReal() const
{
    return realN_;
}

CompositeShape& CompositeShape::operator=(const CompositeShape& figure)
{
    if (this != &figure)
    {
        for (int i = 0; i < realN_; i++)
            delete figures_[i];
        maxN_ = figure.maxN_;
        realN_ = figure.realN_;
        for (int i = 0; i < realN_; i++)
            figures_[i] = figure.figures_[i]->clone();
    }
    return *this;
}

CompositeShape& CompositeShape::operator=(CompositeShape&& figure) noexcept
{
    if (this != &figure)
    {
        for (int i = 0; i < realN_; i++)
            delete figures_[i];
        realN_ = figure.realN_;
        maxN_ = figure.maxN_;
        for (int i = 0; i < realN_; i++)
            figures_[i] = figure.figures_[i];
        figure.figures_ = nullptr;
        figure.realN_ = 0;
        figure.maxN_ = 0;
    }
    return *this;
}
