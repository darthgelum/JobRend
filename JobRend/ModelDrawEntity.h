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
	std::list<Vector2> l;
	bool switcher = false;
	float offset = 5;
	float multiplier = 8;
	void clear();
	Model* cube;
};

