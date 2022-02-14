#pragma once
#include "RectangleOutline2dObject.h"
namespace tp
{
    class ColorableImage :
        public RectangleOutline2dObject
    {
        ColorableImage(int p_outlineBoxWidth, int p_outlineBoxHeight, ofColor p_tintColor);
        virtual ~ColorableImage();
        ofColor getTintColor();
        void setTintColor(ofColor p_tintColor);
    private :
        ofColor m_tintColor;
    };
}
