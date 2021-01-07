//
//  point.cpp
//  PROJETMEDEV
//
//  Created by Hugo ALLEMAND on 11/12/2020.
//  Copyright © 2020 Hugo ALLEMAND. All rights reserved.
//

#include "point.hpp"

Point::Point() : m_x(0), m_y(0)
{}

Point::Point(float x, float y) : m_x(x), m_y(y)
{}

float Point::getX() const
{
    return m_x;
}

float Point::getY() const
{
    return m_y;
}

bool operator==(Point const& a, Point const& b)
{
    return ((a.getX() == b.getX()) && (a.getY() == b.getY()));
}
