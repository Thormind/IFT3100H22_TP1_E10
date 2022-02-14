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
 File names:    	  			IconSquareSelectAction.h
								IconSquareSelectAction.cpp
 Date created: 				    2022-02-10
 *******************************************************
 Change history
 *******************************************************
 2022-02-10	Initial version (et1)
********************************************************/

#pragma once

#ifndef ICON_SQUARE_SELECT_ACTION_H
#define ICON_SQUARE_SELECT_ACTION_H

#include "ofMain.h"
#include "Action.h"

/**
 * Class that manage the icon selection action 
 * @author Stephane Boulanger
 * @version 1.0
 * @since 1.0
 */
class IconSquareSelectAction : public Action {
public:
	virtual void execute() override;
	void onClickInSquare(glm::vec2& clickPosition);
	const glm::vec2& getClickPosition() const;

private:
	glm::vec2 m_clickPosition;
};


#endif // #define ICON_SQUARE_SELECT_ACTION_H
