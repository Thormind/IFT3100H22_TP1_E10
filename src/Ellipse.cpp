#include "Ellipse.h"

namespace tp
{
    Ellipse::Ellipse(int p_outlineBoxWidth, int p_outlineBoxHeight, ofColor p_color, int p_semiMinorAxis, int p_semiMajorAxis)
        : ColorableRectangleOutlineShape(p_outlineBoxWidth, p_outlineBoxHeight, p_color), m_semiMinorAxis(p_semiMinorAxis), m_semiMajorAxis(p_semiMajorAxis) {}

    Ellipse:: ~Ellipse() {}

    void Ellipse::resize(int new_semiMinorAxis, int new_semiMajorAxis)
    {
        m_semiMinorAxis = new_semiMinorAxis;
        m_semiMajorAxis = new_semiMajorAxis;
    }

    int Ellipse::getSemiMinorAxis()
    {
        return m_semiMinorAxis;
    }

    int Ellipse::getSemiMajorAxis()
    {
        return m_semiMajorAxis;
    }
}