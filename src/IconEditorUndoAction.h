// filtre: IconEditor/Control/Actions

#pragma once

#ifndef ICON_EDITOR_UNDO_ACTION_H
#define ICON_EDITOR_UNDO_ACTION_H

#include "Action.h"

class IconEditorUndoAction : public Action {
public:
	virtual ~IconEditorUndoAction() {}
	virtual void execute() override;
	void buttonPressed();

};

#endif // #define ICON_EDITOR_UNDO_ACTION_H	

