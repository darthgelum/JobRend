#pragma once
#include "Entity.h"
#include "Model.h"
class PlaneDrawEntity : public Entity
{
	void Start() override;
	void Update() override;
private:
	void buildPlane();
	void drawModel();
	Model* mModel;
};

