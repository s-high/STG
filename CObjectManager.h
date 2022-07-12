#pragma once
#include <memory>
#include <vector>
#include "CBaseObject.h"

class CObjectManager
{
	std::vector<std::shared_ptr<CBaseObject>> objectVector;
public:
	CObjectManager();
	std::vector<std::shared_ptr<CBaseObject>> getObject() const;
	void addObject(std::shared_ptr<CBaseObject>);
	void clear();
	void upDate();
	void render();
	int getSize();
	~CObjectManager();
};

