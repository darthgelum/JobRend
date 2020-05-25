#include "Entity.h"
#include "EntityContainer.h"
#include "BaseInputEntity.h"
#include "ModelDrawEntity.h"
#include "PlaneDrawEntity.h"
void EntityContainer::LoadEntities()
{
	//Add(new ChessPixelDrawEntity());
	Add(new BaseInputEntity());
	//Add(new TextureDrawEntity());
	Add(new ModelDrawEntity());
	Add(new PlaneDrawEntity());
}
