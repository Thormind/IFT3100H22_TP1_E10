// filtre: MainEditor/Control/Commands	

#include "UndoableCommand.h"


void UndoableCommand::redo() {
	execute();
}
