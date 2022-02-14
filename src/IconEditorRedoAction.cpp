// filtre: IconEditor/Control/Actions

#include "IconEditorRedoAction.h"
#include "IconEditorController.h"

void IconEditorRedoAction::execute() {
	IconEditorController::getInstance()->execute(*this);
}

void IconEditorRedoAction::buttonPressed() {
	execute();
}
