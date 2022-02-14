// filtre: SharedModels

#include "RenderableObject2d.h"

RenderableObject2d::RenderableObject2d(glm::vec2 position, ofColor lineColor, ofColor fillColor,
	                                   RenderableTypeEnum renderableType, int objectInstanceNumber)
	: RenderableObject(renderableType, objectInstanceNumber), m_position(position), 
	  m_lineColor(lineColor), m_fillColor(fillColor) {
}

const glm::vec2 & RenderableObject2d::getPosition() const {
	return m_position;
}

void RenderableObject2d::setPosition(const glm::vec2 & position) {
	m_position = position;
}

const ofColor & RenderableObject2d::getLineColor() const {
	return m_lineColor;
}

void RenderableObject2d::setLineColor(const ofColor & lineColor) {
	m_lineColor = lineColor;
}

const ofColor & RenderableObject2d::getFillColor() const {
	return m_fillColor;
}

void RenderableObject2d::setFillColor(const ofColor & fillColor) {
	m_fillColor = fillColor;
}



