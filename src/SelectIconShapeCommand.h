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
 File names:    	  			SelectIconShapeCommand.h
								SelectIconShapeCommand.cpp
 Date created: 				    2022-02-10
 *******************************************************
 Change history
 *******************************************************
 2022-02-10	Initial version (et1)
********************************************************/

#pragma once

#ifndef SELECTION_ICON_SHAPE_COMMAND_H
#define SELECTION_ICON_SHAPE_COMMAND_H

#include "Command.h"
#include "ofMain.h"
#include "Square.h";
#include "MainEditor.h"

/**
 * Class that command select icon shape 
 * @author Stephane Boulanger
 * @version 1.0
 * @since 1.0
 */
class SelectIconShapeCommand : public Command {
public:
	SelectIconShapeCommand(glm::vec2 clickPosition);
	virtual ~SelectIconShapeCommand() {}
	virtual void execute() override;


private:
	MainEditor* m_mainEditorPtr;
};

#endif // #define SELECTION_ICON_SHAPE_COMMAND_H