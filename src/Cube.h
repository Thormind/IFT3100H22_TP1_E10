// filtre: SharedModels

#pragma once

#ifndef CUBE_H
#define CUBE_H

#include "RenderableObject3d.h"

class Cube : public RenderableObject3d {
public:
	Cube(glm::vec3 position, float width, ofColor edgeColor, ofColor faceColor);
	Cube(glm::vec3 position, float width, ofColor color);
	Cube(glm::vec3 position, float width);
	Cube(glm::vec3 position);
	Cube();
	virtual ~Cube() {}

private:
	static const RenderableTypeEnum RENDERABLE_TYPE;
	static const glm::vec3 DEFAULT_POSITION;
	static const float DEFAUT_WIDTH;
	static const ofColor DEFAULT_COLOR;

	
	static int s_numberOfIteration;

	float m_width;
};

#endif // #define CUBE_H