// filtre: SharedModels

#pragma once

#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

class Subject {
public:
	virtual ~Subject() {}
	void attachObserver(Observer & observer);
	void notifyObservers();

private:
	std::vector<Observer *> m_observerPtrList;


};

#endif // #define MAIN_EDITOR_H