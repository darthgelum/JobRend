#pragma once

#include "Vectors.h"
#include <vector>


struct Mesh {
    int numVertices = 0;
    std::vector<Vector3> vertices;
    int numFaces = 0;
    std::vector<Vector3> faces;
};
