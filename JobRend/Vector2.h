#pragma once
#include <string>
struct Vector2 {
    float x = 0;
    float y = 0;

    Vector2(float x1, float y1) : x(x1), y(y1)
    {}

    Vector2(std::string x1, std::string y1) :
        x(std::stof(x1)), y(std::stof(x1))
    {}
};