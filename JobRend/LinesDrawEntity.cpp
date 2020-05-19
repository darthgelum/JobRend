#include <iostream>
#include "Entity.h"
class LinesDrawEntity : public Entity
{
	void Start() override {
		std::cout << "Hey, i'm alive" << std::endl;
	}
};
