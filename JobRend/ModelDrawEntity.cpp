#include "ModelDrawEntity.h"
#include "MainCanvas.h"
#include <list>
void ModelDrawEntity::Start() {
	model = new Model("models\\teapot.obj");
	//cube->describeMesh();
    int size = model->GetMesh()->numVertices;
    for (int i = 0; i < size; ++i) {
        (model->GetMesh()->vertices)[i].scale(20);
    }
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
        //canvas->DrawLine(v1, v2, green);
        //canvas->DrawLine(v2, v3, red);
        //canvas->DrawLine(v1, v3, blue);
        canvas->ColorTriangle(v3, v2, v1);
    }
    rotate();

}

void ModelDrawEntity::rotate()
{
    Mesh* modelMesh = model->GetMesh();
    std::vector<Vector3>* vertices = &modelMesh->vertices;
    float theta2 = 0.004;
    int size = modelMesh->numVertices;
    for (int i = 0; i < size; ++i) {
        // (*vertices)[i].rotX(thetax);
        (*vertices)[i].rotX(theta2);
        (*vertices)[i].rotY(theta2);
        (*vertices)[i].rotZ(theta2);
    }
}
