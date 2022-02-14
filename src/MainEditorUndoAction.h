// filtre: MainEditor/Control/Actions

#pragma once

#ifndef MAIN_EDITOR_UNDO_ACTION_H
#define MAIN_EDITOR_UNDO_ACTION_H

#include "Action.h"

class MainEditorUndoAction : public Action {
public:
	virtual ~MainEditorUndoAction() {}
	virtual void execute() override;
	void buttonPressed();

};

#endif // #define MAIN_EDITOR_UNDO_ACTION_H	