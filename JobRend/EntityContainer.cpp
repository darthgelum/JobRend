#include "Entity.h"
#include "EntityContainer.h"
#include "LinesDrawEntity.h"
#include "BaseInput.h"
void EntityContainer::LoadEntities()
{
	Add(new LinesDrawEntity());
	Add(new BaseInputEntity());

}
