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
 File names:    	  			SquareRenderer.h
								SquareRenderer.cpp
 Date created: 				    2022-02-10
 *******************************************************
 Change history
 *******************************************************
 2022-02-10	Initial version (et1)
********************************************************/

#pragma once

#ifndef SQUARE_RENDERER_H
#define SQUARE_RENDERER_H

#include "ofMain.h"
#include "Square.h"

/**
 * Class that renderer Square
 * @author Stephane Boulanger
 * @version 1.0
 * @since 1.0
 */
class Square;

class SquareRenderer {
public:
	static void draw(const Square& square);

};

#endif // #define SQUARE_RENDERER_H	