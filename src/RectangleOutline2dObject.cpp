#include "RectangleOutline2dObject.h"


#pragma once

namespace tp
{	
	RectangleOutline2dObject::RectangleOutline2dObject(int p_outlineBoxWidth, int p_outlineBoxHeight) : m_outlineBoxWidth(p_outlineBoxWidth), m_outlineBoxHeight(p_outlineBoxHeight) {}
    
	RectangleOutline2dObject:: ~RectangleOutline2dObject()
	{}
		
	int RectangleOutline2dObject:: getOutlineBoxWidth()
	{
		return m_outlineBoxWidth;
	}

	void RectangleOutline2dObject::setOutlineBoxWidth(int p_outlineBoxWidth)
	{
		m_outlineBoxWidth = p_outlineBoxWidth;
	}

	int RectangleOutline2dObject::getOutlineBoxHeight()
	{
		return m_outlineBoxHeight;
	}

	void RectangleOutline2dObject::setOutlineBoxHeight(int p_outlineBoxHeight)
	{
		m_outlineBoxHeight = p_outlineBoxHeight;
	}
}
