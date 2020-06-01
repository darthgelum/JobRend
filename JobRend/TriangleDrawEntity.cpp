#include "TriangleDrawEntity.h"

void TriangleDrawEntity::Start()
{
	mModel = new Model();
	Vector2 centerPoint = Screen::GetCanvas()->CenterPoint();
	mModel->SetVertice(Vector3(0, 0,0));
	mModel->SetVertice(Vector3(0, 50, 0));
	mModel->SetVertice(Vector3(50,50, 0));

	mModel->SetFace(Vector3(1,2,3));

}

void TriangleDrawEntity::Update()
{
	drawModel();
}

void TriangleDrawEntity::buildPlane()
{
}

void TriangleDrawEntity::drawModel()
{
	MainCanvas* canvas = Screen::GetCanvas();
	Uint32 red = canvas->CColor(0xFF, 0x00, 0x00);
	std::vector<Vector3>* faces = &mModel->GetMesh()->faces;
	std::vector<Vector3>* vertices = &mModel->GetMesh()->vertices;
	for (Vector3 f : *faces) {
		Vector3 v1 = (*vertices)[f.x - 1];
		Vector3 v2 = (*vertices)[f.y - 1];
		Vector3 v3 = (*vertices)[f.z - 1];
		//canvas->DrawLine(v1, v2, red);
		//canvas->DrawLine(v2, v3, red);
		//canvas->DrawLine(v1, v3, red);
		canvas->ColorTriangle(v1, v2, v3);
	}
	Mesh* modelMesh = mModel->GetMesh();
	float theta2 = 0.004;
	int size = modelMesh->numVertices;
	for (int i = 0; i < size; ++i) {
		// (*vertices)[i].rotX(thetax);
//		(*vertices)[i].rotX(theta2);
	//	(*vertices)[i].rotY(theta2);
		(*vertices)[i].rotZ(theta2);
	}
}
