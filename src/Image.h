#pragma once
#include "ColorableImage.h"
namespace tp
{
    class Image : public ColorableImage
    {
        Image(int p_outlineBoxWidth, int p_outlineBoxHeight, ofColor p_tintColor, string p_filePath, colorSpace ColorSpaceEnum);
    };
}
