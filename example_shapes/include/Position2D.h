#pragma once

template <typename T>
class Position2D
{
public:
    Position2D(const T& x, const T& y)
        : m_x(x)
        , m_y(y)
    {
    }
    Position2D()
        : Position2D(0, 0)
    {
    }

    Position2D& operator+=(const Position2D& v)
    {
        m_x += v.x();
        m_y += v.y();
        return *this;
    }

    const T& x() const { return m_x; }

    const T& y() const { return m_y; }

protected:
    T m_x, m_y;
};
