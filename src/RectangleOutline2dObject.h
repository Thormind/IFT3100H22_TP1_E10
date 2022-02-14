#pragma once
#include <types/ofColor.h>
using namespace std;

namespace tp 
{
	class RectangleOutline2dObject
	{
	public:
		RectangleOutline2dObject(int p_outlineBoxWidth, int p_outlineBoxHeight);
		virtual ~RectangleOutline2dObject();
		int getOutlineBoxWidth();
		void setOutlineBoxWidth(int p_outlineBoxWidth);
		int getOutlineBoxHeight();
		void setOutlineBoxHeight(int p_outlineBoxHeight);
	private:
		int m_outlineBoxWidth;
		int m_outlineBoxHeight;
	};
}
