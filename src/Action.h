// filtre: MainEditor/Control/Actions

#pragma once

#ifndef ACTION_H
#define ACTION_H

class Action {
public:
	virtual ~Action() {}
	virtual void execute() = 0;

protected:
	Action() {}
};

#endif // #define ACTION_H	