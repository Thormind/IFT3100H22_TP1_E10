#include <iostream>
#include "IconSquareSelectAction.h"
#include "IconEditorController.h"

void IconSquareSelectAction::execute() {
	IconEditorController::getInstance()->execute(*this);
}

void IconSquareSelectAction::onClickInSquare(glm::vec2& clickPosition) {
	m_clickPosition = clickPosition;
	execute();
	std::cout << "Icon Select Square Test";
}

const glm::vec2& IconSquareSelectAction::getClickPosition() const {
	return m_clickPosition;
}
