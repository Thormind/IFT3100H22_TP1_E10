// filtre: IconEditor/Control/Actions

#pragma once

#ifndef ICON_EDITOR_REDO_ACTION_H
#define ICON_EDITOR_REDO_ACTION_H

#include "Action.h"

class IconEditorRedoAction : public Action {
public:
	virtual ~IconEditorRedoAction() {}
	virtual void execute() override;
	void buttonPressed();

};

#endif // #define ICON_EDITOR_REDO_ACTION_H	