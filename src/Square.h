/******************************************************
 Class:   			  			IFT-2008
 Session: 						H2022
 Project:						TP-1: engin 3d


 Students:

 Donald-Simon Hache
 Frederic Belanger
 Jonathan Bedard
 Kristofer Nolan
 Stephane Boulanger
 William Dussault


 Teacher:	 					Philippe Voyer
 File names:    	  			Square.h
								Square.cpp
 Date created: 				    2022-02-10
 *******************************************************
 Change history
 *******************************************************
 2022-02-10	Initial version (et1)
********************************************************/

#pragma once

#ifndef SQUARE_H
#define SQUARE_H

#include "ofMain.h"
#include "RenderableObject2d.h"

/**
 * Class that manage Square 
 * @author Stephane Boulanger
 * @version 1.0
 * @since 1.0
 */
class Square : public RenderableObject2d {
public:
	Square(glm::vec2 position, float width, ofColor lineColor, ofColor fillColor);
	
	Square();
	virtual ~Square();

	virtual void centerInSquare(glm::vec2 squarePosition, float squareWidth) override;
	virtual void resize(float multiplier) override;

	const int & getWidth() const; 
	void setWidth(const int& width);

	const int& getResolution() const;

	ofEvent<glm::vec2> clickedInside; // retourne une position et l'id du square dans lequel on a clique

	void mouseMoved(ofMouseEventArgs& args);
	void mouseDragged(ofMouseEventArgs& args);
	void mousePressed(ofMouseEventArgs& args);
	void mouseReleased(ofMouseEventArgs& args);
	void mouseScrolled(ofMouseEventArgs& args);
	void mouseEntered(ofMouseEventArgs& args);
	void mouseExited(ofMouseEventArgs& args);

private:
	void clear();
	bool isInside(float x, float y);

	static const glm::vec2 DEFAULT_POSITION;
	static const float DEFAULT_WIDTH;
	static const ofColor DEFAULT_COLOR;
	static const int DEFAULT_RESOLUTION;
	static const RenderableTypeEnum RENDERABLE_TYPE;
	static int s_numberOfIteration;
	
	float m_width; 
	int m_resolution;
};


#endif // !SQUARE_H
