#include "SquareRenderer.h"

void SquareRenderer::draw(const Square& square) {
	
	ofFill();
	ofSetColor(square.getFillColor());
	ofDrawRectangle(square.getPosition().x, square.getPosition().y, square.getWidth(), square.getWidth());

	ofNoFill();
	ofSetColor(square.getLineColor());
	ofDrawRectangle(square.getPosition().x, square.getPosition().y, square.getWidth(), square.getWidth());
}
