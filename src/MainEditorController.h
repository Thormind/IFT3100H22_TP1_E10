// filtre: MainEditor/Control
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
 File names:    	  			MainEditorController.h
								MainEditorController.cpp
 Date created: 				    2022-02-10
 *******************************************************
 Change history
 *******************************************************
 2022-02-10	Initial version (et1)
********************************************************/

#pragma once

#ifndef MAIN_EDITOR_CONTROLLER_H
#define MAIN_EDITOR_CONTROLLER_H

#include <stack>
#include "MainEditor.h"
#include "GameMap.h"
#include "Action.h"
#include "MainEditorUndoAction.h"
#include "MainEditorRedoAction.h"
#include "StartIconEditionAction.h"
#include "UndoableCommand.h"

/**
 * Base class that manages all the data for the main editor
 * @author Frederic Belanger
 * @author Donald-Simon Hache
 * @author Stephane Boulanger
 * @version 1.0
 * @since 1.0
 */
class MainEditorController {
public:
	// On ne veut pas pouvoir cloner un Singleton
	MainEditorController(MainEditorController &other) = delete;

	// On ne veut pas que le singleton soit assignable
	void operator=(const MainEditorController &) = delete;

	static MainEditorController * getInstance();

	// Le controleur doit garder un pointeur vers le modele. 
	// Ce pointeur est assigne a chaque commande qui peut
	// modifier le modele.
	void setMainEditorPtr(MainEditor * mainEditorPtr);
	
	// Toutes les actions a traiter
	void execute(const MainEditorUndoAction & mainEditorUndoAction);
	void execute(const MainEditorRedoAction & mainEditorRedoAction);
	void execute(const StartIconEditionAction & startEditionAction);

	void undo();
	void redo();
	void pushToUndoStack(UndoableCommand & aCommand);
	void pushToRedoStack(UndoableCommand & aCommand);
	void resetStacks();

protected:
	// On met le constructeur privé pour ne pas que la classe soit instanciable a l'exterieur d'elle
	// meme.
	MainEditorController();

private:
	void popFromUndoStack();
	void popFromRedoStack();

	// Tout le programme utilise cette unique instance du singleton
	static MainEditorController * s_singletonInstancePtr;

	MainEditor * m_mainEditorPtr;
	std::stack<UndoableCommand *> m_undoStack;
	std::stack<UndoableCommand *> m_redoStack;

};

#endif // #define MAIN_EDITOR_CONTROLLER_H

