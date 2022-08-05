//
// Created by 张宇衡 on 2022/8/5.
//
#include "Vector4f.h"
#include "Vector3f.h"
#include "Quaternion.h"
#include "Matrix4f.h"
#include "../minecraft/util/Mth.h"

cerver::math::Vector4f::Vector4f(double f, double f2, double f3, double f4) {
    this->m_x = f;
    this->m_y = f2;
    this->m_z = f3;
    this->m_w = f4;
}

cerver::math::Vector4f::Vector4f(std::shared_ptr<Vector3f> vector3f){
    this->m_x = vector3f->x();
    this->m_y = vector3f->y();
    this->m_z = vector3f->z();
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

void cerver::math::Vector4f::mul(std::shared_ptr<Vector3f> vector3f) {
    this->m_x *= vector3f->x();
    this->m_y *= vector3f->y();
    this->m_z *= vector3f->z();
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

double cerver::math::Vector4f::dot(std::shared_ptr<Vector4f> vector4f) const {
    return this->m_x * vector4f->x() + this->m_y * vector4f->y() + this->m_z * vector4f->z() +
           this->m_w * vector4f->w();
}

void cerver::math::Vector4f::transform(std::shared_ptr<Quaternion> quaternion) {
    Quaternion quaternion2 = Quaternion(quaternion);
    quaternion2.mul(std::make_shared<Quaternion>(this->m_x, this->m_y, this->m_z, 0.0));
    Quaternion quaternion3 = Quaternion(quaternion);
    quaternion3.conj();
    quaternion2.mul(std::make_shared<Quaternion>(quaternion3));
    this->set(quaternion2.i(), quaternion2.j(), quaternion2.k(), this->w());
}

void cerver::math::Vector4f::perspectiveDivide() {
    this->m_x /= this->m_w;
    this->m_y /= this->m_w;
    this->m_z /= this->m_w;
    this->m_w = 1.0;
}

void cerver::math::Vector4f::lerp(std::shared_ptr<Vector4f> vector4f, double f) {
    double f2 = 1.0 - f;
    this->m_x = f2 * this->m_x + f * vector4f->x();
    this->m_y = f2 * this->m_y + f * vector4f->y();
    this->m_z = f2 * this->m_z + f * vector4f->z();
    this->m_w = f2 * this->m_w + f * vector4f->w();
}

std::string cerver::math::Vector4f::toString() const {
    return std::string("[") + std::to_string(this->m_x) + ", " + std::to_string(this->m_y) + ", " +
           std::to_string(this->m_z) + ", " + std::to_string(this->m_w) + "]";
}

bool cerver::math::Vector4f::normalize() {
    double f = this->x() * this->x() + this->y() * this->y() + this->z() * this->z() + this->w() * this->w();
    if (f < 0.000001) {
        return false;
    }
    double f2 = cerver::minecraft::util::Mth::fastInvSqrt(f);
    this->m_x *= f2;
    this->m_y *= f2;
    this->m_z *= f2;
    this->m_w *= f2;
    return true;
}

void cerver::math::Vector4f::transform(std::shared_ptr<Matrix4f> matrix4f) {
    double f = this->m_x;
    double f2 = this->m_y;
    double f3 = this->m_z;
    double f4 = this->m_w;
    this->m_x = matrix4f->m00 * f + matrix4f->m01 * f2 + matrix4f->m02 * f3 + matrix4f->m03 * f4;
    this->m_y = matrix4f->m10 * f + matrix4f->m11 * f2 + matrix4f->m12 * f3 + matrix4f->m13 * f4;
    this->m_z = matrix4f->m20 * f + matrix4f->m21 * f2 + matrix4f->m22 * f3 + matrix4f->m23 * f4;
    this->m_w = matrix4f->m30 * f + matrix4f->m31 * f2 + matrix4f->m32 * f3 + matrix4f->m33 * f4;
}

