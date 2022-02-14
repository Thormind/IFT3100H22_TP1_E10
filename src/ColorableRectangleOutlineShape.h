#pragma once
#include "RectangleOutline2dObject.h"

namespace tp 
{
    class ColorableRectangleOutlineShape : public RectangleOutline2dObject
    {
        ColorableRectangleOutlineShape(int p_outlineBoxWidth, int p_outlineBoxHeight, ofColor p_color);
        virtual ~ColorableRectangleOutlineShape();
        ofColor getColor();
        void setColor(ofColor p_color);
    private:
        ofColor m_color;
    };
}
