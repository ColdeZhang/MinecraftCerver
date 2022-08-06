//
// Created by 张宇衡 on 2022/8/6.
//

#include "Vector3d.h"

cerver::math::Vector3d::Vector3d(double d, double d2, double d3)  {
    this->x = d;
    this->y = d2;
    this->z = d3;
}

void cerver::math::Vector3d::set(const Vector3dPtr& vector3d) {
    this->x = vector3d->x;
    this->y = vector3d->y;
    this->z = vector3d->z;
}

void cerver::math::Vector3d::set(double d, double d2, double d3) {
    this->x = d;
    this->y = d2;
    this->z = d3;
}

void cerver::math::Vector3d::add(const Vector3dPtr& vector3d) {
    this->x += vector3d->x;
    this->y += vector3d->y;
    this->z += vector3d->z;
}

void cerver::math::Vector3d::scale(double d) {
    this->x *= d;
    this->y *= d;
    this->z *= d;
}
