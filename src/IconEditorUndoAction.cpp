// filtre: IconEditor/Control/Actions

#include "IconEditorUndoAction.h"
#include "IconEditorController.h"

void IconEditorUndoAction::execute() {
	IconEditorController::getInstance()->execute(*this);
}

void IconEditorUndoAction::buttonPressed() {
	execute();
}
