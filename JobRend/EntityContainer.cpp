#include "Entity.h"
#include "EntityContainer.h"
#include "ChessPixelDrawEntity.h"
#include "BaseInputEntity.h"
#include "TextureDrawEntity.h"
void EntityContainer::LoadEntities()
{
	//Add(new ChessPixelDrawEntity());
	Add(new BaseInputEntity());
	Add(new TextureDrawEntity());

}
