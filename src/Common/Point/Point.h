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
   double distTo(const Point &other) const;

   // ---- Dot product ----
   // Returns the dot product of the current vector with another vector
   // The dot product informs us about the angle between two vectors
   // If the dot product is 1, the vectors are aligned
   double dot(const Point &other) const;

   // ---- Magnitude of the vector ----
   // Returns the magnitude/length of the vector
   double magnitude() const;

   // ---- Normalized vector ----
   // Returns a vector with the same direction as the current vector but with a magnitude of 1
   Point normalized() const;

   // Overloaded operators
   Point operator+(const Point &other) const;
   Point operator-(const Point &other) const;
   Point operator*(double scalar) const;
   Point operator/(double scalar) const;
   bool operator==(const Point &other) const;
   bool operator!=(const Point &other) const;

   // Output stream overload (using friend keyword to access private members of the class)
   friend std::ostream &operator<<(std::ostream &os, const Point &p);
};

#endif /* TRAINEE_CPP_POINT_H */
