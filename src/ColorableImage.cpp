#include "ColorableImage.h"

namespace tp
{

    ColorableImage::ColorableImage(int p_outlineBoxWidth, int p_outlineBoxHeight, ofColor p_tintColor) : RectangleOutline2dObject(p_outlineBoxWidth, p_outlineBoxHeight), m_tintColor(p_tintColor) {}
    ColorableImage:: ~ColorableImage() {};
    ofColor ColorableImage::getTintColor()
    {
        return m_tintColor;
    }
    void ColorableImage::setTintColor(ofColor p_tintColor)
    {
        m_tintColor = p_tintColor;
    }
}