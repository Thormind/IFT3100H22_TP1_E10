#include "StartIconEditionAction.h"
#include "MainEditorController.h"



void StartIconEditionAction::execute() {
	MainEditorController::getInstance()->execute(*this);
}

void  StartIconEditionAction::buttonPressed() {
	execute();
}

ofColor const& StartIconEditionAction::getColor() const {
	return m_color;
}

glm::vec2 const& StartIconEditionAction::getPosition() const {
	return m_position;
}

