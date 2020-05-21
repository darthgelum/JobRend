#include "Entity.h"
#include "EntityContainer.h"
#include "LinesDrawEntity.h"
#include "BaseInputEntity.h"
#include "TextureDrawEntity.h"
void EntityContainer::LoadEntities()
{
	Add(new LinesDrawEntity());
	Add(new BaseInputEntity());
	Add(new TextureDrawEntity());

}
