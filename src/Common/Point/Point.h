#ifndef TRAINEE_CPP_POINT_H
#define TRAINEE_CPP_POINT_H

#include "../../Libraries/Libs.h"

class Point {
private:
    double m_x, m_y;

public:
    // Constructors
    Point();
    Point(double x, double y);

    // Getters and Setters
    double x() const;
    double y() const;
    void setX(double x);
    void setY(double y);

    // Distance between two points
    double distance(const Point& other) const;

    // Dot product
    double dot(const Point& other) const;

    // Overloaded operators
    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;
    Point operator*(double scalar) const;
    Point operator/(double scalar) const;
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
    
    // Output stream overload
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

#endif /* TRAINEE_CPP_POINT_H */
