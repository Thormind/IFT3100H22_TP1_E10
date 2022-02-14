// filtre: MainEditor/Control/Actions

#include "MainEditorRedoAction.h"
#include "MainEditorController.h"

void MainEditorRedoAction::execute() {
	MainEditorController::getInstance()->execute(*this);
}

void MainEditorRedoAction::buttonPressed() {
	execute();
}
