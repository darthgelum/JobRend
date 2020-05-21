#include "CubeEntity.h"
#include "MainCanvas.h"
void CubeEntity::Start() {
	cube = new Model("models\\teapot.obj");
	//cube->describeMesh();
};

void CubeEntity::Update()
{
    Uint32 red = MainCanvas::CColor(0xFF, 0x00, 0x00);
    MainCanvas* canvas = Screen::GetCanvas();
    std::vector<Vector3> vertices = (cube->getMesh()).vertices;
    for (Vector3 v : vertices) {
        int x = (v.x * 12) + canvas->GetWidth() / 2;
        int y = (-v.y * 12) + canvas->GetHeight() / 2;
        if ((x >= 0) && (y >= 0) && (x < canvas->GetWidth()) && (y < canvas->GetHeight())) {
            canvas->SetPixelColor(red, x, y);
        }
    }
}
