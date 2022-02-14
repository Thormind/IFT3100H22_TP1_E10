#pragma once
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
 File names:    	  			StartIconEditionCommand.h
								StartIconEditionCommand.cpp
 Date created: 				    2022-02-10
 *******************************************************
 Change history
 *******************************************************
 2022-02-10	Initial version (et1)
********************************************************/

#ifndef START_ICON_EDITION_COMMAND_H
#define START_ICON_EDITION_COMMAND_H

#include "Command.h"
#include "MainEditor.h"
#include "IconEditorWindow.h"

/**
 * Class that command the icon edition action
 * @author Stephane Boulanger
 * @version 1.0
 * @since 1.0
 */
class StartIconEditionCommand : public Command {
public:
		StartIconEditionCommand(MainEditor* mainEditionPtr);
	
		virtual ~StartIconEditionCommand();
		virtual void execute() override;
		
private:
	MainEditor* m_mainEditorPtr;
	IconEditorWindow * m_iconEditorWindowPtr;
};


#endif // #define START_ICON_EDITION_COMMAND_H
