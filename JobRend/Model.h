#pragma once
#include <string>
#include "Mesh.h"
class Model
{
public:
    Model(std::string path);
    void describeMesh();
    Mesh getMesh();

private:
    void buildMesh(std::string path);

    Mesh mMesh;
};

