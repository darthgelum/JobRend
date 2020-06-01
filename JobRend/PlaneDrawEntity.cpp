#include "PlaneDrawEntity.h"
#include "array"
#include <algorithm>
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
	int width = Screen::GetWidth();
	int height = Screen::GetHeight();
	int cellWidth = 100;
	int cols = width / cellWidth;
	int rows = height / cellWidth;
	cols++;
	rows++;
	int x, y;
	MainCanvas* canvas = Screen::GetCanvas();
	for (int i = 0; i < cols * rows; i++)
	{
		int col = floor(i % cols);
		int row = floor(i / cols);
		x = col*cellWidth;
		y = row * cellWidth;
		Vector3 vertice = Vector3(x - canvas->CenterPoint().x, y - canvas->CenterPoint().y, 0);

		mModel->SetVertice(vertice);
		int number = ((row * cols) + col) + 1;
		if (row!=0 && col != cols-1)
		{

			//mModel->SetFace(Vector3(number - 1, number - cols, number));
			mModel->SetFace(Vector3(number, number-cols, number-cols+1));
		}
		if (row != 0 && col == cols - 1)
		{
			mModel->SetFace(Vector3(number-1, number - cols, number));
		}
	}
	Mesh* modelMesh = mModel->GetMesh();
	std::vector<Vector3>* vertices = &modelMesh->vertices;


}

void PlaneDrawEntity::drawModel()
{

	MainCanvas* canvas = Screen::GetCanvas();
	Uint32 red = canvas->CColor(0xFF, 0x00, 0x00);
	std::vector<Vector3>* faces = &mModel->GetMesh()->faces;
	std::vector<Vector3>* vertices = &mModel->GetMesh()->vertices;
	for (Vector3 f : *faces) {
		Vector3 v1 = (*vertices)[f.x - 1];
		Vector3 v2 = (*vertices)[f.y - 1];
		Vector3 v3 = (*vertices)[f.z - 1];

		canvas->ColorTriangle(v1, v2, v3);
	}
	float theta2 = 0.004;
	int size = mModel->GetMesh()->numVertices;


}
