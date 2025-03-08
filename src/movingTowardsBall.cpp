#include "Robot/Robot.h"
#include <random>

#define MAX_VEL 2.0f
#define MAX_POS 10
#define MIN_POS -10
#define MAX_ANGLE 360
#define TOLERANCE 0.8

float randomFloat(float min, float max) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_real_distribution<float> dis(min, max);
  return dis(gen);
}

int main() {
   Robots robots;
   int numRobots = 11;

   for (int i = 1; i <= numRobots; ++i) {
      auto robot = Robot(
         i, 
         randomFloat(0, MAX_ANGLE), 
         0,
         Point(randomFloat(MIN_POS, MAX_POS), randomFloat(MIN_POS, MAX_POS)),
         Point(randomFloat(0, MAX_VEL), randomFloat(0, MAX_VEL)), 
         Point(0, 0));
      robots.emplace_back(robot);
   }

   Point ball(randomFloat(MIN_POS, MAX_POS), randomFloat(MIN_POS, MAX_POS));

   std::cout << "Ball position: " << ball << std::endl;
   for (const auto& robot : robots) {
      Point robotToBall = Point(ball.x() - robot.position().x(), ball.y() - robot.position().y());
      robotToBall = robotToBall.normalized();

      Point velocityNormalized = robot.velocity().normalized();

      double dotProduct = robotToBall.dot(velocityNormalized);

      // If the dot product is close to 1, the robot is moving towards the ball.
      // The angle between the robot's velocity (moving direction) and the vector from the robot to the ball is close to 0.
      if (dotProduct > TOLERANCE) {
         std::cout << "Robot " << robot.id() << " is moving towards the ball." << std::endl;
      } else {
         std::cout << "Robot " << robot.id() << " is NOT moving towards the ball." << std::endl;
      }
   }

  return 0;
}
