// filtre: MainEditor/Model

#include "MainEditor.h"
#include "MainEditorController.h"

bool MainEditor::m_shouldBeDrawn{ true };

void MainEditor::setup() {
	initMainEditorController();
	initRenderTable();
	m_shouldBeDrawn = true;
}

void MainEditor::update() {
}

void MainEditor::draw() {
	notifyObservers();
}

const std::map<std::string, RenderableObject*>& MainEditor::getRenderTable() const {
	return m_renderTable;
}

const std::string & MainEditor::getTestString() {
	return m_testString;
}

void MainEditor::setTestString(const std::string testString) {
	m_testString = testString;
}

void MainEditor::setShouldBeDrawn(const bool & shouldBeDrawn) {
	m_shouldBeDrawn = shouldBeDrawn;
}

void MainEditor::hideEditor() {
	cout << "hide" << endl;
	shared_ptr<ofAppGLFWWindow> glfwWin = dynamic_pointer_cast<ofAppGLFWWindow>(m_ofBaseWindowSharedPtr);
	glfwHideWindow(glfwWin->getGLFWWindow());
}

void MainEditor::showEditor() {
	cout << "show" << endl;
	shared_ptr<ofAppGLFWWindow> glfwWin = dynamic_pointer_cast<ofAppGLFWWindow>(m_ofBaseWindowSharedPtr);
	glfwShowWindow(glfwWin->getGLFWWindow());
}

void MainEditor::setOfBaseWindowSharedPtr(shared_ptr<ofAppBaseWindow> ofBaseWindowSharedPtr) {
	m_ofBaseWindowSharedPtr = ofBaseWindowSharedPtr;
	shared_ptr<ofAppGLFWWindow> glfwWin = dynamic_pointer_cast<ofAppGLFWWindow>(m_ofBaseWindowSharedPtr);
	//GLFWwindowclosefun(MainEditor::*ptr)(GLFWwindow*) = &MainEditor::windowCloseCallback;
	glfwSetWindowCloseCallback(glfwWin->getGLFWWindow(), &MainEditor::windowCloseCallback);
}

void MainEditor::windowCloseCallback (GLFWwindow* window) {
	if (!m_shouldBeDrawn) {
		cout << "dont close my window!" << endl;
		glfwSetWindowShouldClose(window, GLFW_FALSE);
	}
}

const shared_ptr<ofAppBaseWindow> & MainEditor::getOfBaseWindowSharedPtr() {
	return m_ofBaseWindowSharedPtr;
}

const bool & MainEditor::getShouldBeDrawn() {
	return m_shouldBeDrawn;
}

void MainEditor::keyPressed(int key) {

}

//--------------------------------------------------------------
void MainEditor::keyReleased(int key) {
}

//--------------------------------------------------------------
void MainEditor::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void MainEditor::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void MainEditor::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void MainEditor::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void MainEditor::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void MainEditor::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void MainEditor::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void MainEditor::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void MainEditor::dragEvent(ofDragInfo dragInfo) {

}



void MainEditor::initMainEditorController() {
	MainEditorController::getInstance()->setMainEditorPtr(this);
}

void MainEditor::initRenderTable() {
	addToRenderTable(m_gameMap);
}

void MainEditor::addToRenderTable(const RenderableObject & renderableObject) {
	m_renderTable.insert(
		{ renderableObject.getObjectUniqueId(), (RenderableObject*)&renderableObject }
	);
}


