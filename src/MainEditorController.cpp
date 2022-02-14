// filtre: MainEditor/Control

#include <iostream>
#include "MainEditorController.h"
#include "StartIconEditionCommand.h"

MainEditorController * MainEditorController::s_singletonInstancePtr(nullptr);

MainEditorController::MainEditorController() 
	: m_mainEditorPtr(nullptr) {
}

MainEditorController * MainEditorController::getInstance() {
	if (s_singletonInstancePtr == nullptr) {
		s_singletonInstancePtr = new MainEditorController();
	}

	return s_singletonInstancePtr;
}

void MainEditorController::setMainEditorPtr(MainEditor * mainEditorPtr) {
	m_mainEditorPtr = mainEditorPtr;
}

void MainEditorController::execute(const MainEditorUndoAction & mainEditorUndoAction) {
	undo();
}

void MainEditorController::execute(const MainEditorRedoAction & mainEditorRedoAction) {
	redo();
}

void MainEditorController::execute(const StartIconEditionAction& startEditionAction) {
	StartIconEditionCommand* startIconEditionCommandPtr = new StartIconEditionCommand(m_mainEditorPtr);
	startIconEditionCommandPtr->execute();
}

void MainEditorController::undo() {
	if (m_undoStack.size() != 0) {
		m_undoStack.top()->undo();
		popFromUndoStack();
	}
}

void MainEditorController::redo() {
	if (m_redoStack.size() != 0) {
		m_redoStack.top()->execute();
		popFromRedoStack();
	}
}

void MainEditorController::pushToUndoStack(UndoableCommand & aCommand) {
	m_undoStack.push(&aCommand);
}

void MainEditorController::pushToRedoStack(UndoableCommand & aCommand) {
	m_redoStack.push(&aCommand);
}

void MainEditorController::popFromUndoStack() {
	m_undoStack.pop();
}

void MainEditorController::popFromRedoStack() {
	m_redoStack.pop();
}

void MainEditorController::resetStacks() {
}


