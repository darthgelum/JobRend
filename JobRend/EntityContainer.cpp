#include "Entity.h"
#include "EntityContainer.h"
#include "ChessPixelDrawEntity.h"
#include "BaseInputEntity.h"
#include "TextureDrawEntity.h"
#include "ModelDrawEntity.h"
#include "PlaneDrawEntity.h"
#include "TriangleDrawEntity.h"
void EntityContainer::LoadEntities()
{
	//Add(new ChessPixelDrawEntity());
	Add(new BaseInputEntity());
	//Add(new TextureDrawEntity());
	//Add(new ModelDrawEntity());
	Add(new PlaneDrawEntity());
	//Add(new TriangleDrawEntity());
}
