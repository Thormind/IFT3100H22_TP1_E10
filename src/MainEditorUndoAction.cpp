// filtre: MainEditor/Control/Actions

#include "MainEditorUndoAction.h"
#include "MainEditorController.h"

void MainEditorUndoAction::execute() {
	MainEditorController::getInstance()->execute(*this);
}

void MainEditorUndoAction::buttonPressed() {
	execute();
}
