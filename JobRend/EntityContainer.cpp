#include "Entity.h"
#include "EntityContainer.h"
#include "LinesDrawEntity.h"
void EntityContainer::LoadEntities()
{
	Add(new LinesDrawEntity());
}
