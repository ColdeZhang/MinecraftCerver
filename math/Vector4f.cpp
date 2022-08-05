//
// Created by 张宇衡 on 2022/8/5.
//
#include "Vector4f.h"
#include "Vector3f.h"
#include "Quaternion.h"

cerver::math::Vector4f::Vector4f(double f, double f2, double f3, double f4) {
    this->m_x = f;
    this->m_y = f2;
    this->m_z = f3;
    this->m_w = f4;
}

cerver::math::Vector4f::Vector4f(const cerver::math::Vector3f& vector3f){
    this->m_x = vector3f.x();
    this->m_y = vector3f.y();
    this->m_z = vector3f.z();
    this->m_w = 1.0;
}

int cerver::math::Vector4f::hashCode() const {
    int n = (int) m_x;
    n = 31 * n + (int) m_y;
    n = 31 * n + (int) m_z;
    n = 31 * n + (int) m_w;
    return n;
}

void cerver::math::Vector4f::mul(double f){
    this->m_x *= f;
    this->m_y *= f;
    this->m_z *= f;
    this->m_w *= f;
}

void cerver::math::Vector4f::mul(const cerver::math::Vector3f& vector3f) {
    this->m_x *= vector3f.x();
    this->m_y *= vector3f.y();
    this->m_z *= vector3f.z();
    this->m_w *= 1.0;
}

void cerver::math::Vector4f::set(double f, double f2, double f3, double f4)  {
    this->m_x = f;
    this->m_y = f2;
    this->m_z = f3;
    this->m_w = f4;
}

void cerver::math::Vector4f::add(double f, double f2, double f3, double f4) {
    this->m_x += f;
    this->m_y += f2;
    this->m_z += f3;
    this->m_w += f4;
}

double cerver::math::Vector4f::dot(cerver::math::Vector4f vector4f) const {
    return this->m_x * vector4f.x() + this->m_y * vector4f.y() + this->m_z * vector4f.z() +
           this->m_w * vector4f.w();
}

void cerver::math::Vector4f::transform(cerver::math::Quaternion quaternion) {
    Quaternion quaternion2 = Quaternion(quaternion);
    quaternion2.mul(Quaternion(this->m_x, this->m_y, this->m_z, 0.0));
    Quaternion quaternion3 = Quaternion(quaternion);
    quaternion3.conj();
    quaternion2.mul(quaternion3);
    this->set(quaternion2.i(), quaternion2.j(), quaternion2.k(), this->w());
}

void cerver::math::Vector4f::perspectiveDivide() {
    this->m_x /= this->m_w;
    this->m_y /= this->m_w;
    this->m_z /= this->m_w;
    this->m_w = 1.0;
}

