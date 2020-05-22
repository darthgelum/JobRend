#include "Model.h"
#include <stdio.h>
#include <fstream>
#include <sstream>
#include "Vector3.h"

Model::Model(std::string path) {
    buildMesh(path);
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

void Model::buildMesh(std::string path) {
    printf("Loading models...\n");
    std::string line, v, x, y, z;

    std::ifstream file;
    file.open(path.c_str());

    //Get vertices into mesh
    GetVertices(file);

    //Get faces
    GetFaces(file);

    //Close file after reading
    file.close();
    mMesh.numVertices = mMesh.vertices.size();
}

void Model::GetFaces(std::ifstream& file) {
    std::string line, f, x, y, z;
    while (!file.eof()) {

        std::getline(file, line);
        std::istringstream iss(line);
        iss >> f;
        if (f == "f") {
            iss >> x >> y >> z;
            Vector3 face(x, y, z);
            mMesh.faces.push_back(face);
        }
    }
    mMesh.numFaces = mMesh.faces.size();
    file.clear();
    file.seekg(0, file.beg);
}

void Model::Rotate(float theta)
{
    int size = mMesh.numVertices;
    float cos_t = std::cos(theta);
    float sin_t = std::sin(theta);
    std::vector<Vector3>* vertices = &mMesh.vertices;
    // Rotation matrix
    for (int i = 0; i < size; ++i) {
        float xOld = (*vertices)[i].x;
        float zOld = (*vertices)[i].z;
        (*vertices)[i].x = xOld * cos_t + zOld * sin_t;
        (*vertices)[i].z = -xOld * sin_t + zOld * cos_t;
    }
}

void Model::GetVertices(std::ifstream& file) {
    std::string line, v, x, y, z;
    while (!file.eof()) {
        std::getline(file, line);
        std::istringstream iss(line);
        iss >> v;
        if (v == "v") {
            iss >> x >> y >> z;
            Vector3 vertex(x, y, z);
            mMesh.vertices.push_back(vertex);
        }
    }
    mMesh.numVertices = mMesh.vertices.size();
    file.clear();
    file.seekg(0, file.beg);
}