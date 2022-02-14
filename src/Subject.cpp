// filtre: SharedModels

#include "Subject.h"

void Subject::attachObserver(Observer & observer) {
	m_observerPtrList.push_back(&observer);
}

void Subject::notifyObservers() {
	for (Observer * observerPtr : m_observerPtrList) {
		observerPtr->update();
	}
}
