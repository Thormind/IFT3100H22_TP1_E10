#include "ColorableRectangleOutlineShape.h"

namespace tp
{

    ColorableRectangleOutlineShape::ColorableRectangleOutlineShape(int p_outlineBoxWidth, int p_outlineBoxHeight, ofColor p_color) :
        RectangleOutline2dObject(p_outlineBoxWidth, p_outlineBoxHeight), m_color(p_color) {};
    
    ColorableRectangleOutlineShape :: ~ColorableRectangleOutlineShape() {};
    
    ofColor ColorableRectangleOutlineShape::getColor()
    {
        return m_color;
    }
    
    void ColorableRectangleOutlineShape::setColor(ofColor p_color)
    {
        m_color = p_color;
    }
}