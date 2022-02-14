#include <iostream>
#include "StartIconEditionCommand.h"
#include "MainEditorController.h"
#include "IconEditor.h"
#include "ofMain.h"

StartIconEditionCommand::StartIconEditionCommand(MainEditor* mainEditionPtr) 
	: m_mainEditorPtr(mainEditionPtr), m_iconEditorWindowPtr(nullptr) {
}

StartIconEditionCommand::~StartIconEditionCommand() {
	delete m_iconEditorWindowPtr;
	m_iconEditorWindowPtr = nullptr;
	m_mainEditorPtr = nullptr;
}

void StartIconEditionCommand::execute() {

	//m_mainEditorPtr->hideEditor();
	m_mainEditorPtr->setShouldBeDrawn(false);
	std::cout << "Start icon editor" << std::endl;
	ofGLFWWindowSettings settings;
	settings.setSize(500, 500);
	settings.shareContextWith = m_mainEditorPtr->getOfBaseWindowSharedPtr();


	// les () sont en fait un appel au constructeur de "IconEditor"
	shared_ptr<IconEditor> iconEditorSharedPtr = make_shared<IconEditor>(m_mainEditorPtr);
	shared_ptr<ofAppBaseWindow> temporaryWindow = ofCreateWindow(settings);
	

	m_iconEditorWindowPtr = new IconEditorWindow(iconEditorSharedPtr);
	iconEditorSharedPtr->attachObserver(*m_iconEditorWindowPtr);

	ofRunApp(temporaryWindow, iconEditorSharedPtr);
	//m_mainEditorPtr->setShouldBeDrawn(false);


}