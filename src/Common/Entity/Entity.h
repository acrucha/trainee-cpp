#ifndef TRAINEE_CPP_ENTITY_H
#define TRAINEE_CPP_ENTITY_H

#include "../../Libraries/Libs.h"

template <class PT>
class Entity {
protected:
    int m_id;
    float m_angle;
    PT m_position;
    PT m_velocity;
    PT m_acceleration;

public:
    constexpr explicit Entity(const PT& position, const PT& velocity, const PT& acceleration)
        : m_position(position), m_velocity(velocity), m_acceleration(acceleration) {}

    constexpr const PT& position() const {
        return m_position;
    }

    constexpr operator const PT&() const { 
        return position();
    }

    constexpr auto distTo(const PT& other) const {
        return m_position.distTo(other);
    }

    constexpr bool operator==(const Entity& other) const {
        return m_position == other.m_position;
    }

    constexpr const PT& velocity() const {
        return m_velocity;
    }

    constexpr const PT& acceleration() const {
        return m_acceleration;
    }

};

#endif /* TRAINEE_CPP_ENTITY_H */
