#include "ModelDrawEntity.h"
#include "MainCanvas.h"
#include <list>
void ModelDrawEntity::Start() {
	cube = new Model("models\\ayumi.obj");
	//cube->describeMesh();
};

void ModelDrawEntity::Update()
{
    clear();
    MainCanvas* canvas = Screen::GetCanvas();
    Uint32 red = canvas->CColor(0xFF, 0x00, 0x00);
    std::vector<Vector3> vertices = (cube->getMesh()).vertices;
    for (Vector3 v : vertices) {
        int x = (v.x * offset) + canvas->CenterPoint().x;
        int y = (-v.y * offset) + canvas->CenterPoint().y*2;
        if ((x >= 0) && (y >= 0) && (x < canvas->GetWidth()) && (y < canvas->GetHeight())) {
            canvas->SetPixelColor(red, x, y);
            l.push_back(Vector2(x, y));
        }
    }
}

void ModelDrawEntity::clear()
{
    MainCanvas* canvas = Screen::GetCanvas();
    for (Vector2 px : l)
    {
        canvas->SetPixelColor(canvas->CColor(0,0,0) , px.x, px.y);
    }
    l.clear();
}
