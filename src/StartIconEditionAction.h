#pragma once

#ifndef START_ICON_EDITION_ACTION_H
#define START_ICON_EDITION_ACTION_H

#include "ofMain.h"
#include "Action.h"

class StartIconEditionAction : Action {
public:
	
	virtual ~StartIconEditionAction() {}
	virtual void execute() override;
	void buttonPressed();

	ofColor const& getColor() const;
	glm::vec2 const& getPosition() const;
	

private: 
	ofColor m_color;
	glm::vec2 m_position;
	




};


#endif // #define START_ICON_EDITION_ACTION_H

