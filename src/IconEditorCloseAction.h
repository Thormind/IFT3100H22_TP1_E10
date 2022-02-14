// filtre: IconEditor/Control/Actions

#pragma once

#ifndef ICON_EDITOR_CLOSE_ACTION_H
#define ICON_EDITOR_CLOSE_ACTION_H

#include "Action.h"

class IconEditorCloseAction : public Action {
public:
	virtual ~IconEditorCloseAction() {}
	virtual void execute() override;
	void buttonPressed();
};

#endif // #define ICON_EDITOR_CLOSE_ACTION_H	

