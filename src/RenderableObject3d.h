// filtre: SharedModels

#pragma once

#ifndef RENDERABLE_OBJECT3D_H
#define RENDERABLE_OBJECT3D_H

#include "ofMain.h"
#include "RenderableObject.h"

class RenderableObject3d : RenderableObject {
public:	
	virtual ~RenderableObject3d() {}

	void setRotateOnX(const float& angle);
	const float & getRotateOnX() const;
	void setRotateOnY(const float& angle);
	const float & getRotateOnY() const;
	void setRotateOnZ(const float& angle);
	const float & getRotateOnZ() const;
	void setAllRotationAngles(const glm::vec3 & angles);
	const glm::vec3 & getAllRotationAngles() const;

	void setPositionOnX(const float & distance);
	const float & getPositionOnX() const;
	void setPositionOnY(const float & distance);
	const float & getPositionOnY() const;
	void setPositionOnZ(const float & distance);
	const float & getPositionOnZ() const;
	void setPosition(const glm::vec3& distances);
	const glm::vec3& getPosition() const;

	void setScaleOnX(const float & multiplier);
	const float & getScaleOnX() const;
	void setScaleOnY(const float & multiplier);
	const float & getScaleOnY() const;
	void setScaleOnZ(const float & multiplier);
	const float & getScaleOnZ() const;
	void setAllScaleMultipliers(const glm::vec3& multipliers);
	const glm::vec3& getAllScaleMultipliers() const;

protected:
	RenderableObject3d(glm::vec3 position, ofColor edgeColor, ofColor fillColor, 
		               RenderableTypeEnum renderableType, int objectInstanceNumber);
	glm::vec3 m_position;
	glm::vec3 m_rotationAngles;
	glm::vec3 m_scaleMultipliers;
	ofColor m_edgeColor;
	ofColor m_faceColor;
};

#endif // #define RENDERABLE_OBJECT3D_H