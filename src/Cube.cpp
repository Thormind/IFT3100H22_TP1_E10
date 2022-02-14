#include "Cube.h"

const RenderableTypeEnum Cube::RENDERABLE_TYPE{ RenderableTypeEnum::CUBE };
const glm::vec3 Cube::DEFAULT_POSITION{ glm::vec3(0, 0, 0) };
const float Cube::DEFAUT_WIDTH{ 1 };
const ofColor Cube::DEFAULT_COLOR{ ofColor::white };


int Cube::s_numberOfIteration{ 0 };

Cube::Cube(glm::vec3 position, float width, ofColor edgeColor, ofColor faceColor) 
	: RenderableObject3d(position, edgeColor, faceColor, RENDERABLE_TYPE, s_numberOfIteration++),
      m_width(width) {
}

Cube::Cube(glm::vec3 position, float width, ofColor color) 
	: Cube(position, width, color, color) {
}

Cube::Cube(glm::vec3 position, float width)
	: Cube(position, width, DEFAULT_COLOR, DEFAULT_COLOR) {
}

Cube::Cube(glm::vec3 position)
	: Cube(position, DEFAUT_WIDTH, DEFAULT_COLOR, DEFAULT_COLOR) {

}

Cube::Cube() 
	: Cube(DEFAULT_POSITION, DEFAUT_WIDTH, DEFAULT_COLOR, DEFAULT_COLOR) {

}
