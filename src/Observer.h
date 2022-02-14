// filtre: SharedModels

#pragma once

#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
	virtual ~Observer() {}
	virtual void update() = 0;

protected:
	Observer() {}
};

#endif // #define OBSERVER_H
