#include <iostream>
#include "SelectIconShapeCommand.h"
#include "ofMain.h"

SelectIconShapeCommand::SelectIconShapeCommand(glm::vec2 clickPosition) {
	std::cout << "click in square at positon x = " +
		std::to_string(clickPosition.x) + " y = " + std::to_string(clickPosition.y)
		<< std::endl;
}

void SelectIconShapeCommand::execute() {

}
