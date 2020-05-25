#include "ModelDrawEntity.h"
#include <list>

#include "Color.h"
#include "Engine.h"
void ModelDrawEntity::Start() {
	model = new Model("models\\teapot.obj");
	//cube->describeMesh();
    int size = model->GetMesh()->numVertices;
    for (int i = 0; i < size; ++i) {
        (model->GetMesh()->vertices)[i].scale(25);
    }
};

void ModelDrawEntity::Update()
{
    float theta = 0.04;
    float cos_e = std::cos(theta);
    float sin_e = std::sin(theta);
    Mesh* modelMesh = model->GetMesh();
    std::vector<Vector3>* vertices = &modelMesh->vertices;

    Color red = Color(255, 0, 0, 0);
    Color green = Color(0, 255, 0, 0);
    Color blue = Color(0, 0, 255, 0);

    std::vector<Vector3>* faces = &modelMesh->faces;
    for (Vector3 f : *faces) {
        Vector3 v1 = (*vertices)[f.x - 1];
        Vector3 v2 = (*vertices)[f.y - 1];
        Vector3 v3 = (*vertices)[f.z - 1];
        Engine::Renderer()->DrawLine(v1, v2, green);
        Engine::Renderer()->DrawLine(v2, v3, red);
        Engine::Renderer()->DrawLine(v1, v3, blue);
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
