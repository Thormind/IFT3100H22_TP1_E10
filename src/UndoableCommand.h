// filtre: MainEditor/Control/Commands

#pragma once

#ifndef UNDOABLE_COMMAND_H
#define UNDOABLE_COMMAND_H

#include "Command.h"

class UndoableCommand : public Command {
public:
	virtual ~UndoableCommand() {}
	virtual void undo() = 0;
	void redo();

protected:
	UndoableCommand() {}
};

#endif // #define UNDOABLE_COMMAND_H	