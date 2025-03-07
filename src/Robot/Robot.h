#ifndef TRAINEE_CPP_ROBOT_H
#define TRAINEE_CPP_ROBOT_H

#include "../Libraries/Libs.h"
#include "../Common/Common.h"

class Robot : public Entity<Point> {

public:
      Robot(int id,
            float angle,
            float angularVelocity,
            const Point& position,
            const Point& velocity,
            const Point& acceleration);
      
      Robot(int id,
            float angle,
            float angularVelocity,
            const Entity<Point>& entity);

      [[nodiscard]] inline float angularVelocity() const {
            return m_angularVelocity;
      }

      constexpr int id() const {
            return m_id;
      }

      constexpr float angle() const {
            return m_angle;
      }

private:
      int m_id;
      float m_angle;
      float m_angularVelocity;
};

#endif /* TRAINEE_CPP_ROBOT_H */
