#include "Rectangle.h"

namespace tp
{
    Rectangle::Rectangle(int p_outlineBoxWidth, int p_outlineBoxHeight, ofColor p_color, int p_width, int p_height)
        : ColorableRectangleOutlineShape(p_outlineBoxWidth, p_outlineBoxHeight, p_color), m_width(p_width), m_height(p_height) {}

    Rectangle:: ~Rectangle() {}

    void Rectangle::resize(int new_width, int new_height)
    {
        m_width = new_width;
        m_height = new_height;
    }

    int Rectangle::getWidth()
    {
        return m_width;
    }

    int Rectangle::getHeight()
    {
        return m_height;
    }
}