#include "RenderableObject3d.h"

RenderableObject3d::RenderableObject3d(glm::vec3 position, ofColor edgeColor,
									   ofColor faceColor,	
	                                   RenderableTypeEnum renderableType,
	                                   int objectInstanceNumber) 
	: RenderableObject(renderableType, objectInstanceNumber),
	  m_position(position), m_edgeColor(edgeColor), m_faceColor(faceColor), 
	  m_rotationAngles(0, 0, 0), m_scaleMultipliers(0, 0, 0) {
}

void RenderableObject3d::setRotateOnX(const float& angle) {
	m_rotationAngles.x = angle;
}

const float& RenderableObject3d::getRotateOnX() const {
	return m_rotationAngles.x;
}

void RenderableObject3d::setRotateOnY(const float& angle) {
	m_rotationAngles.y = angle;
}

const float& RenderableObject3d::getRotateOnY() const {
	return m_rotationAngles.y;
}

void RenderableObject3d::setRotateOnZ(const float& angle) {
	m_rotationAngles.z = angle;
}

const float& RenderableObject3d::getRotateOnZ() const {
	return m_rotationAngles.z;
}

void RenderableObject3d::setAllRotationAngles(const glm::vec3& angles) {
	setRotateOnX(angles.x);
	setRotateOnY(angles.y);
	setRotateOnZ(angles.z);

}

const glm::vec3& RenderableObject3d::getAllRotationAngles() const {
	return m_rotationAngles;
}

void RenderableObject3d::setPositionOnX(const float& distance) {
	m_position.x = distance;
}

const float& RenderableObject3d::getPositionOnX() const {
	return m_position.x;
}

void RenderableObject3d::setPositionOnY(const float& distance) {
	m_position.y = distance;
}

const float& RenderableObject3d::getPositionOnY() const {
	return m_position.y;
}

void RenderableObject3d::setPositionOnZ(const float& distance) {
	m_position.z = distance;
}

const float& RenderableObject3d::getPositionOnZ() const {
	return m_position.z;
}

void RenderableObject3d::setPosition(const glm::vec3& distances) {
	setPositionOnX(distances.x);
	setPositionOnY(distances.y);
	setPositionOnZ(distances.z);
}

const glm::vec3& RenderableObject3d::getPosition() const {
	return m_position;
}

void RenderableObject3d::setScaleOnX(const float& multiplier) {
	m_scaleMultipliers.x = multiplier;
}

const float& RenderableObject3d::getScaleOnX() const {
	return m_scaleMultipliers.x;
}

void RenderableObject3d::setScaleOnY(const float& multiplier) {
	m_scaleMultipliers.y = multiplier;
}

const float& RenderableObject3d::getScaleOnY() const {
	return m_scaleMultipliers.y;
}

void RenderableObject3d::setScaleOnZ(const float& multiplier) {
	m_scaleMultipliers.z = multiplier;
}

const float& RenderableObject3d::getScaleOnZ() const {
	return m_scaleMultipliers.z;
}

void RenderableObject3d::setAllScaleMultipliers(const glm::vec3& multipliers) {
	setScaleOnX(multipliers.x);
	setScaleOnY(multipliers.y);
	setScaleOnZ(multipliers.z);
}

const glm::vec3& RenderableObject3d::getAllScaleMultipliers() const {
	return m_scaleMultipliers;
}


