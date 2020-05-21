#pragma once
#include "Entity.h"
#include "Model.h"
class CubeEntity : public Entity
{
public:
	void Start() override;
	void Update() override;
private:
	Model* cube;
};

