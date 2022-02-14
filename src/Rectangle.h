#pragma once
#include "ColorableRectangleOutlineShape.h"

namespace tp 
{
    class Rectangle : public ColorableRectangleOutlineShape
    {
        Rectangle(int p_outlineBoxWidth, int p_outlineBoxHeight, ofColor p_color, int p_width, int p_height);
        virtual ~Rectangle();
        virtual void resize(int new_width, int new_height);
        int getWidth();
        int getHeight();
    private:
        int m_width;
        int m_height;
    };
}
