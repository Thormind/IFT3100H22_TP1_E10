#include "Square.h"

const RenderableTypeEnum Square::RENDERABLE_TYPE{ RenderableTypeEnum::SQUARE };
const ofColor Square::DEFAULT_COLOR{ ofColor::white };
const glm::vec2 Square::DEFAULT_POSITION{ glm::vec2(0,0) };
const float Square::DEFAULT_WIDTH{ 1 };
const int Square::DEFAULT_RESOLUTION{ 30 };
int Square::s_numberOfIteration{ 0 };

Square::Square(glm::vec2 position, float width, ofColor lineColor, ofColor fillColor) :
	RenderableObject2d(position, lineColor, fillColor, RENDERABLE_TYPE, s_numberOfIteration++),
	m_width(width), m_resolution(DEFAULT_RESOLUTION) {

	ofRegisterMouseEvents(this); 
}

Square::Square() : Square::Square(DEFAULT_POSITION, DEFAULT_WIDTH, DEFAULT_COLOR, DEFAULT_COLOR){
	
}

Square::~Square() {
	clear();
}

void Square::centerInSquare(glm::vec2 squarePosition, float squareWidth) {
	m_position = glm::vec2(squarePosition.x + m_width, squarePosition.y + m_width);
}

void Square::resize(float multiplier) {
	m_width *= multiplier;
}

const int& Square::getWidth() const {
	return m_width;
}

void Square::setWidth(const int& width) {
	m_width = width;
}

const int& Square::getResolution() const {
	return m_resolution;
}

void Square::mouseMoved(ofMouseEventArgs& args) {}
void Square::mouseDragged(ofMouseEventArgs& args) {}
void Square::mousePressed(ofMouseEventArgs& args) {}

void Square::mouseReleased(ofMouseEventArgs& args) {
	if (isInside(args.x, args.y)) {

		// genere un evenment qui retourne la position de la souris lorsque
		// l'utilisateur clique a l'interieur du square
		glm::vec2 mousePosition = glm::vec2(args.x, args.y);
		ofNotifyEvent(clickedInside, mousePosition, this);
	}
}

void Square::mouseScrolled(ofMouseEventArgs& args) {}
void Square::mouseEntered(ofMouseEventArgs& args) {}
void Square::mouseExited(ofMouseEventArgs& args) {}

void Square::clear() {
	ofUnregisterMouseEvents(this);
}

bool Square::isInside(float x, float y)
{	
	return x > m_position.x 
		   && x < m_position.x + m_width 
		   && y > m_position.y 
		   && y < m_position.y + m_width;
}
