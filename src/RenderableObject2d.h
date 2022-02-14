// filtre: SharedModels

#pragma once

#ifndef RENDERABLE_OBJECT2D_H
#define RENDERABLE_OBJECT2D_H

#include "ofMain.h"
#include "RenderableObject.h"



class RenderableObject2d : public RenderableObject {
public:
	virtual ~RenderableObject2d() {}
	virtual void centerInSquare(glm::vec2 squarePosition, float squareWidth) = 0;
	virtual void resize(float multiplier) = 0;

	const glm::vec2 & getPosition() const;
	void setPosition(const glm::vec2 & position);
	const ofColor & getLineColor() const;
	void setLineColor(const ofColor & lineColor);
	const ofColor & getFillColor() const;
	void setFillColor(const ofColor & fillColor);

protected:
	RenderableObject2d(glm::vec2 position, ofColor lineColor, ofColor fillColor, 
		               RenderableTypeEnum renderableType, int objectInstanceNumber);
	
	glm::vec2 m_position;
	ofColor m_lineColor;
	ofColor m_fillColor;			

private:

};

#endif // #define RENDERABLE_OBJECT2D_H