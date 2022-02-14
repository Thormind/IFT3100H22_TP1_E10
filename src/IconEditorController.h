// filtre: IconEditor/Control
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
 File names:    	  			IconEditorController.h
								IconEditorController.cpp
 Date created: 				    2022-02-10
 *******************************************************
 Change history
 *******************************************************
 2022-02-10	Initial version (et1)
********************************************************/

#pragma once

#ifndef ICON_EDITOR_CONTROLLER_H
#define ICON_EDITOR_CONTROLLER_H

#include <stack>
#include "IconEditor.h"
#include "IconEditorUndoAction.h"
#include "IconEditorRedoAction.h"
#include "IconEditorCloseAction.h"
#include "UndoableCommand.h"
#include "IconSquareSelectAction.h"
#include "StartIconEditionAction.h"

/**
 * Class that control icon editor
 * @author Frederic Belanger
 * @author Stephane Boulanger
 * @version 1.0
 * @since 1.0
 */
class IconEditorController {
public:
	// On ne veut pas pouvoir cloner un Singleton
	IconEditorController(IconEditorController &other) = delete;

	// On ne veut pas que le singleton soit assignable
	void operator=(const IconEditorController &) = delete;

	static IconEditorController * getInstance();

	// Le controleur doit garder un pointeur vers le modele. 
	// Ce pointeur est assigne a chaque commande qui peut
	// modifier le modele.
	void setIconEditorPtr(IconEditor * iconEditorPtr);

	// Toutes les actions a traiter
	void execute(const IconEditorUndoAction & iconEditorUndoAction);
	void execute(const IconEditorRedoAction & iconEditorRedoAction);
	void execute(const IconEditorCloseAction & iconEditorCloseAction);
	void execute(const IconSquareSelectAction& iconSquareSelectAction);

	void undo();
	void redo();
	void pushToUndoStack(UndoableCommand & aCommand);
	void pushToRedoStack(UndoableCommand & aCommand);
	void resetStacks();

protected:
	// On met le constructeur privé pour ne pas que la classe soit instanciable a l'exterieur d'elle
	// meme.
	IconEditorController();

private:
	void popFromUndoStack();
	void popFromRedoStack();

	// Tout le programme utilise cette unique instance du singleton
	static IconEditorController * s_singletonInstancePtr;

	IconEditor * m_iconEditorPtr;
	std::stack<UndoableCommand *> m_undoStack;
	std::stack<UndoableCommand *> m_redoStack;

};

#endif // #define ICON_EDITOR_CONTROLLER_H

