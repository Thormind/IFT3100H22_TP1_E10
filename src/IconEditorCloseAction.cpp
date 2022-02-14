#include "IconEditorCloseAction.h"
#include "IconEditorController.h"

void IconEditorCloseAction::execute() {
	IconEditorController::getInstance()->execute(*this);
}

void IconEditorCloseAction::buttonPressed() {
	execute();
}