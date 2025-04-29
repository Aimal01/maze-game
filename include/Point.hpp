// Point.hpp
#pragma once

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    bool operator==(const Point& other) const { 
        return x == other.x && y == other.y; 
    }
    
    bool operator!=(const Point& other) const { 
        return !(*this == other); 
    }
    
    Point operator+(const Point& other) const { 
        return Point(x + other.x, y + other.y); 
    }
};