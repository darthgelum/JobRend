#pragma once
#include "Entity.h"
#include "Model.h"
#include <list>
class ModelDrawEntity : public Entity
{
public:
	void Start() override;
	void Update() override;

private:
	std::list<Uint32*> l;
	void clear();
	Model* model;
};

