#pragma once

#include <string>

struct Vector3 {
    float x = 0;
    float y = 0;
    float z = 0;

    Vector3(float x1, float y1, float z1) : x(x1), y(y1), z(z1)
    {}

    Vector3(std::string x1, std::string y1, std::string z1) :
        x(std::stof(x1)), y(std::stof(y1)), z(std::stof(z1))
    {}

    void rotX(float thetaX);
    void rotY(float thetaY);
    void rotZ(float thetaZ);

    void scale(float scale);
    void translate(float dx, float dy, float dz);
};

struct Vector2 {
    float x = 0;
    float y = 0;

    Vector2(float x1, float y1) : x(x1), y(y1)
    {}

    Vector2(std::string x1, std::string y1) :
        x(std::stof(x1)), y(std::stof(x1))
    {}
};