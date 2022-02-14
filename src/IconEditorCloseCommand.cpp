
#include "IconEditorCloseCommand.h"
#include "MainEditorController.h"

IconEditorCloseCommand::IconEditorCloseCommand(IconEditor* iconEditionPtr)
	: m_iconEditorPtr(iconEditionPtr) {

}

void IconEditorCloseCommand::execute() {
	cout << "closing IconEditor" << endl;

	//A effacer
	m_iconEditorPtr->changeTestString();
	m_iconEditorPtr->sendNewTestStringToMainEditor();
	
	//m_iconEditorPtr->showMainEditor();
	m_iconEditorPtr->releaseMainWindow();
	ofGetCurrentWindow()->setWindowShouldClose();
}