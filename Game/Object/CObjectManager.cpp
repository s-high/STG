#include "CObjectManager.h"


CObjectManager::CObjectManager() {
}

std::vector<std::shared_ptr<CBaseObject>> CObjectManager::getObject() const {
	return this->objectVector;
}

void CObjectManager::addObject(std::shared_ptr<CBaseObject> o) {
	this->objectVector.push_back(o);
}

void CObjectManager::clear() {
	this->objectVector.clear();
}

void CObjectManager::upDate() {
	std::vector<std::shared_ptr<CBaseObject>> nextObjectVector;
	for (auto e : this->objectVector) {
		e->upDate();
		if (e->getIsAlive()) {
			nextObjectVector.push_back(e);
		} else {
			e->finalize();
		}
	}
	objectVector.swap(nextObjectVector);
}

void CObjectManager::render() {
	for (auto e : this->objectVector) {
		e->render();
	}
}

int CObjectManager::getSize() {
	return this->objectVector.size();
}

CObjectManager::~CObjectManager() {
}
