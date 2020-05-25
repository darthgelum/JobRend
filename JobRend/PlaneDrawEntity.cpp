#include "PlaneDrawEntity.h"
#include "array"
#include <algorithm>

#include "Color.h"
#include "Engine.h"
void PlaneDrawEntity::Start()
{
	buildPlane();
}

void PlaneDrawEntity::Update()
{

	drawModel();
}

void PlaneDrawEntity::buildPlane()
{
	mModel = new Model();
	int width = Engine::Renderer()->GetWidth();
	int height = Engine::Renderer()->GetHeight();
	int cellWidth = 100;
	int cols = width / cellWidth;
	int rows = height / cellWidth;
	cols++;
	rows++;
	int x, y;
	for (int i = 0; i < cols * rows; i++)
	{
		int col = floor(i % cols);
		int row = floor(i / cols);
		x = col*cellWidth;
		y = row * cellWidth;
		Vector3 vertice = Vector3(x - Engine::Renderer()->GetWidth()/2, y - Engine::Renderer()->GetHeight()/2, 0);

		mModel->SetVertice(vertice);
		if (row!=0 && col != cols-1)
		{
			int number = ((row * cols) + col)+1;
			mModel->SetFace(Vector3(number, number-cols, number-cols+1));
		}
		if (row != 0 && col == cols - 1)
		{
			int number = ((row * cols) + col) + 1;
			mModel->SetFace(Vector3(number-1, number - cols, number));
		}
	}
	Mesh* modelMesh = mModel->GetMesh();
	std::vector<Vector3>* vertices = &modelMesh->vertices;


}

void PlaneDrawEntity::drawModel()
{
	Color red = Color(255, 0, 0, 0);
	
	std::vector<Vector3>* faces = &mModel->GetMesh()->faces;
	std::vector<Vector3>* vertices = &mModel->GetMesh()->vertices;
	for (Vector3 f : *faces) {
		Vector3 v1 = (*vertices)[f.x - 1];
		Vector3 v2 = (*vertices)[f.y - 1];
		Vector3 v3 = (*vertices)[f.z - 1];
		Engine::Renderer()->DrawLine(v1, v2, red);
		Engine::Renderer()->DrawLine(v2, v3, red);
		Engine::Renderer()->DrawLine(v1, v3, red);


	}
	float theta2 = 0.004;
	int size = mModel->GetMesh()->numVertices;


}
