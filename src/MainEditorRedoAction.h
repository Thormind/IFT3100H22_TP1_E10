// filtre: MainEditor/Control/Actions

#pragma once

#ifndef MAIN_EDITOR_REDO_ACTION_H
#define MAIN_EDITOR_REDO_ACTION_H

#include "Action.h"

class MainEditorRedoAction : public Action {
public:
	virtual ~MainEditorRedoAction() {}
	virtual void execute() override;
	void buttonPressed();

};

#endif // #define MAIN_EDITOR_REDO_ACTION_H	