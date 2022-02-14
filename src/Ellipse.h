#pragma once
#include "ColorableRectangleOutlineShape.h"
namespace tp 
{
    class Ellipse : public ColorableRectangleOutlineShape
    {
        Ellipse (int p_outlineBoxWidth, int p_outlineBoxHeight, ofColor p_color, int semiMinorAxis, int semiMajorAxis);
        virtual ~Ellipse();
        virtual void resize(int new_semiMinorAxis, int new_semiMajorAxis);
        int getSemiMinorAxis();
        int getSemiMajorAxis();
    private:
        int m_semiMinorAxis;
        int m_semiMajorAxis;
    };
}
