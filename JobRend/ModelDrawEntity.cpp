#include "ModelDrawEntity.h"
#include "MainCanvas.h"
#include <list>
void ModelDrawEntity::Start() {
	cube = new Model("models\\teapot.obj");
	//cube->describeMesh();

};

void ModelDrawEntity::Update()
{
    MainCanvas* canvas = Screen::GetCanvas();
    Uint32 red = canvas->CColor(0xFF, 0x00, 0x00);
    Uint32 green = canvas->CColor(0x00, 0xFF, 0x00);
    Uint32 white = canvas->CColor(0xFF, 0xFF, 0xFF);
    Mesh* modelMesh = cube->GetMesh();
    std::vector<Vector3>* faces = &modelMesh->faces;
    std::vector<Vector3>* vertices = &modelMesh->vertices;
    for (Vector3 f : *faces) {
        Vector3 v1 = (*vertices)[f.x - 1];
        Vector3 v2 = (*vertices)[f.y - 1];
        Vector3 v3 = (*vertices)[f.z - 1];
        canvas->DrawLine(v1, v2, white);
        canvas->DrawLine(v2, v3, red);
        canvas->DrawLine(v1, v3, green);
    }
}
