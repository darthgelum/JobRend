#include "Model.h"
#include <stdio.h>
#include <fstream>
#include <sstream>
#include "Vectors.h"

Model::Model() {};

Model::Model(std::string path) {
    LoadObj(path);
}

Mesh* Model::GetMesh() {
    return &mMesh;
}

void Model::describeMesh() {
    int meshSize = mMesh.numVertices;
    for (int i = 0; i < meshSize; ++i) {
        Vector3 vertex = mMesh.vertices[i];
        printf("Vertex  %2.1d: %f, %f, %f \n", i, vertex.x, vertex.y, vertex.z);
    }
    printf("Meshsize is: %d \n", meshSize);
}

void Model::LoadObj(std::string path) {
    printf("Loading model...\n");
    std::string line, title, x, y, z;

    std::ifstream file;
    file.open(path.c_str());
    while (!file.eof()) {
        std::getline(file, line);
        std::istringstream iss(line);

        iss >> title >> x >> y >> z;

        if (title == "f") {
            Vector3 face(x, y, z);
            SetFace(face);
        }
        if (title == "v") {
            Vector3 vertex(x, y, z);
            SetVertice(vertex);
        }
    }
    file.clear();
    file.seekg(0, file.beg);
    //Close file after reading
    file.close();
}


void Model::SetFace(Vector3 face) {

    mMesh.faces.push_back(face);

    mMesh.numFaces = mMesh.faces.size();
}

void Model::SetVertice(Vector3 vertex) {

    mMesh.vertices.push_back(vertex);

    mMesh.numVertices = mMesh.vertices.size();
}


