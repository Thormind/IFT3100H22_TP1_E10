// filtre: IconEditor/Control

#include <iostream>
#include "IconEditorController.h"
#include "IconEditorCloseCommand.h"
#include "SelectIconShapeCommand.h"

IconEditorController * IconEditorController::s_singletonInstancePtr(nullptr);

IconEditorController::IconEditorController()
	: m_iconEditorPtr(nullptr) {
}

IconEditorController * IconEditorController::getInstance() {
	if (s_singletonInstancePtr == nullptr) {
		s_singletonInstancePtr = new IconEditorController();
	}

	return s_singletonInstancePtr;
}

void IconEditorController::setIconEditorPtr(IconEditor * iconEditorPtr) {
	m_iconEditorPtr = iconEditorPtr;
}

void IconEditorController::execute(const IconEditorUndoAction & iconEditorUndoAction) {
	undo();
}

void IconEditorController::execute(const IconEditorRedoAction & iconEditorRedoAction) {
	redo();
}

void IconEditorController::execute(const IconEditorCloseAction & iconEditorCloseAction) {
	IconEditorCloseCommand closeCommand(m_iconEditorPtr);
	closeCommand.execute();
}

void IconEditorController::execute(const IconSquareSelectAction& iconSquareSelectAction) {
	SelectIconShapeCommand selectSquareCommand(iconSquareSelectAction.getClickPosition());
	selectSquareCommand.execute();
}

void IconEditorController::undo() {
	if (m_undoStack.size() != 0) {
		m_undoStack.top()->undo();
		popFromUndoStack();
	}
}

void IconEditorController::redo() {
	if (m_redoStack.size() != 0) {
		m_redoStack.top()->execute();
		popFromRedoStack();
	}
}

void IconEditorController::pushToUndoStack(UndoableCommand & aCommand) {
	m_undoStack.push(&aCommand);
}

void IconEditorController::pushToRedoStack(UndoableCommand & aCommand) {
	m_redoStack.push(&aCommand);
}

void IconEditorController::popFromUndoStack() {
	m_undoStack.pop();
}

void IconEditorController::popFromRedoStack() {
	m_redoStack.pop();
}

void IconEditorController::resetStacks() {
}