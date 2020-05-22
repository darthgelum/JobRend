#include "Vector3.h"
#include <sstream>
void Vector3::rotX(float theta) {
    float cos_e = std::cos(theta);
    float sin_e = std::sin(theta);
    float yCurr = y;
    float zCurr = z;
    y = yCurr * cos_e + -zCurr * sin_e;
    z = yCurr * sin_e + zCurr * cos_e;
}


void Vector3::rotY(float theta) {
    float cos_e = std::cos(theta);
    float sin_e = std::sin(theta);
    float xCurr = x;
    float zCurr = z;
    x = xCurr * cos_e + zCurr * sin_e;
    z = -xCurr * sin_e + zCurr * cos_e;
}

void Vector3::rotZ(float theta) {
    float cos_e = std::cos(theta);
    float sin_e = std::sin(theta);
    float xCurr = x;
    float yCurr = y;
    x = xCurr * cos_e + -yCurr * sin_e;
    y = xCurr * sin_e + yCurr * cos_e;
}

void Vector3::scale(float scale) {
    x *= scale;
    y *= scale;
    z *= scale;
}

void Vector3::translate(float dx, float dy, float dz) {
    x += dx;
    y += dy;
    z += dz;
}