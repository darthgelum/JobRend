#pragma once
#include <string>
#include "Mesh.h"
class Model
{
public:
    Model(std::string path);
    void describeMesh();
    void GetFaces(std::ifstream& file);
    void GetVertices(std::ifstream& file);
    Mesh* GetMesh();

private:
    void buildMesh(std::string path);

    Mesh mMesh;
};

