#include "Robot.h"

Robot::Robot(int id,
         float angle,
         float angularVelocity,
         const Point& position,
         const Point& velocity,
         const Point& acceleration) :
   m_id(id),
   m_angle(angle),
   m_angularVelocity(angularVelocity),
   Entity(position, velocity, acceleration) {
}


Robot::Robot(int id, float angle, float angularVelocity, const Entity& entity) :
   Robot(id, angle, angularVelocity, entity.position(), entity.velocity(), entity.acceleration()) {
}