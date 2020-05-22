#include "ModelDrawEntity.h"
#include "MainCanvas.h"
#include <list>
void ModelDrawEntity::Start() {
	model = new Model("models\\ayumi.obj");
	//cube->describeMesh();

};

void ModelDrawEntity::Update()
{
    MainCanvas* canvas = Screen::GetCanvas();

    float theta = 0.04;
    float cos_e = std::cos(theta);
    float sin_e = std::sin(theta);
    Mesh* modelMesh = model->GetMesh();
    std::vector<Vector3>* vertices = &modelMesh->vertices;

    Uint32 red = canvas->CColor(0xFF, 0x00, 0x00);
    Uint32 green = canvas->CColor(0x00, 0xFF, 0x00);
    Uint32 blue = canvas->CColor(0x00, 0x00, 0xFF);

    std::vector<Vector3>* faces = &modelMesh->faces;
    for (Vector3 f : *faces) {
        Vector3 v1 = (*vertices)[f.x - 1];
        Vector3 v2 = (*vertices)[f.y - 1];
        Vector3 v3 = (*vertices)[f.z - 1];
        canvas->DrawLine(v1, v2, green);
       /* canvas->DrawLine(v2, v3, red);
        canvas->DrawLine(v1, v3, green);*/
    }

    model->Rotate(theta);
}
