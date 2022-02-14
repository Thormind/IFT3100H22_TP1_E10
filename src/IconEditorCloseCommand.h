// filtre: IconEditor/Control/Commands

#pragma once

#ifndef ICON_EDITOR_CLOSE_COMMAND_H
#define ICON_EDITOR_CLOSE_COMMAND_H

#include "Command.h"
#include "IconEditor.h"

class IconEditorCloseCommand : public Command {
public:
	IconEditorCloseCommand(IconEditor* iconEditionPtr);

	virtual ~IconEditorCloseCommand() {}
	virtual void execute() override;

private:
	IconEditor* m_iconEditorPtr;
};

#endif // #define ICON_EDITOR_CLOSE_COMMAND_H	