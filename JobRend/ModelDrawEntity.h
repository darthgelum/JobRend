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
	void rotate();
	Model* model;
};

