#pragma once
#include <string>
#include "Mesh.h"
class Model
{
public:
    Model();
    Model(std::string path);
    void describeMesh();
    void LoadObj(std::string path);
    void SetFace(Vector3 vertex);
    void SetVertice(Vector3 vertex);
    Mesh* GetMesh();

private:
    Mesh mMesh;
};

