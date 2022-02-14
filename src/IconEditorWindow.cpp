// filtre: IconEditor/View

#include "IconEditorWindow.h"
#include "IconEditorRenderer.h"

IconEditorWindow::IconEditorWindow(shared_ptr<IconEditor> iconEditorSharedPtr)
	: m_iconEditorSharedPtr(iconEditorSharedPtr) {
	setup();
	cout << "test icon editor window construit ";
}


void IconEditorWindow::update() {
	draw();
}

void IconEditorWindow::setup() {
	ofSetWindowTitle(WINDOW_TITLE);
	ofSetWindowShape(1800, 800);
	setupAllGui();
	addAllListeners();
}


void IconEditorWindow::draw() {
	//m_testPanelGui.setUseTTF(true); // pour corriger un bug avec le texte si on ouvre une 2ieme fenetre

	//ofSetCircleResolution(30);
	//ofSetColor(ofColor::white);
	//ofDrawCircle(300, 300, 100);
	//m_testPanelGui.setUseTTF(false); // pour corriger un bug avec le texte si on ouvre une 2ieme fenetre

	drawAllGuiPanels();
	IconEditorRenderer::draw(m_iconEditorSharedPtr->getRenderTable());
}

void IconEditorWindow::setupAllGui() {
	//m_testPanelGui.setUseTTF(true); // pour corriger un bu avec le texte si on ouvre une 2ieme fenetre
	setupTestPanelGui();
}

void IconEditorWindow::setupTestPanelGui() {
	// seulement pour tester, voir "MainEditorWindow" pour exemple "correct"
	m_testPanelGui.setDefaultWidth(300); 
	m_testPanelGui.setup("Test menu");

	// position relative a la nouvelle fenetre "pop up".
	m_testPanelGui.setPosition(100, 100);

	m_testPanelGui.add(m_closeAndSaveButton.setup("Save change and close", 20, 20));

}

void IconEditorWindow::addAllListeners() {
	m_closeAndSaveButton.addListener(&m_iconEditorCloseAction, &IconEditorCloseAction::buttonPressed);
}

void IconEditorWindow::drawAllGuiPanels() {
	m_testPanelGui.setTextColor(ofColor::green);
	m_testPanelGui.draw();
}
