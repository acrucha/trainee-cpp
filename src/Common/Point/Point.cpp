#include "Point.h"

Point::Point() : m_x(0), m_y(0) {}

Point::Point(double x, double y) : m_x(x), m_y(y) {}

double Point::x() const { return m_x; }
double Point::y() const { return m_y; }
void Point::setX(double x) { this->m_x = x; }
void Point::setY(double y) { this->m_y = y; }

double Point::distTo(const Point& other) const {
   return std::sqrt(std::pow(this->x() - other.x(), 2) + std::pow(this->y() - other.y(), 2));
}

double Point::dot(const Point& other) const {
   return (this->x() * other.x()) + (this->y() * other.y());
}

double Point::magnitude() const {
   return std::sqrt(std::pow(this->x(), 2) + std::pow(this->y(), 2));
}

Point Point::normalized() const {
   double mag = this->magnitude();
   if (mag == 0) throw std::runtime_error("Division by zero");
   return Point(this->x() / mag, this->y() / mag);
}

Point Point::operator+(const Point& other) const {
   return Point(this->x() + other.x(), this->y() + other.y());
}

Point Point::operator-(const Point& other) const {
   return Point(this->x() - other.x(), this->y() - other.y());
}

Point Point::operator*(double scalar) const {
   return Point(this->x() * scalar, this->y() * scalar);
}

Point Point::operator/(double scalar) const {
   if (scalar == 0) throw std::runtime_error("Division by zero");
   return Point(this->x() / scalar, this->y() / scalar);
}

bool Point::operator==(const Point& other) const {
   return (this->x() == other.x() && this->y() == other.y());
}

bool Point::operator!=(const Point& other) const {
   return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
   os << "(" << p.x() << ", " << p.y() << ")";
   return os;
}
