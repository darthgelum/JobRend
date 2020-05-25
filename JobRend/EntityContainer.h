#pragma once
#include <list>
#include "Entity.h"

class EntityContainer
{
	std::list <Entity*> entities;

public:
	EntityContainer()
	{
		LoadEntities();
	}
	void LoadEntities();

	void Add(Entity* entity)
	{
		entities.push_back(entity);
	}
	std::list<Entity*> GetAll()
	{
		return entities;
	}
};