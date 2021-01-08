//
//  point.hpp
//  PROJETMEDEV
//
//  Created by Hugo ALLEMAND on 11/12/2020.
//  Copyright © 2020 Hugo ALLEMAND. All rights reserved.
//

#ifndef point_hpp
#define point_hpp

/**
 * @brief Represents a pair x, y of coordinates
 */
class Point
{
public:
    Point();
    Point(float x, float y);
    float getX() const;
    float getY() const;
private:
    float m_x,m_y;
};

bool operator==(Point const& a, Point const& b);

#endif /* point_hpp */
