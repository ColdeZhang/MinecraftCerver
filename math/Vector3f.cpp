//
// Created by 张宇衡 on 2022/8/4.
//
#include "Vector3f.h"
#include "Vector4f.h"
#include "Matrix3f.h"
#include "Quaternion.h"

cerver::math::Vector3f::Vector3f(double f, double f2, double f3) {
    this->m_x = f;
    this->m_y = f2;
    this->m_z = f3;
}

cerver::math::Vector3f::Vector3f(std::shared_ptr<Vector4f> vector4f) {
    this->m_x = vector4f->x();
    this->m_y = vector4f->y();
    this->m_z = vector4f->z();
}

int cerver::math::Vector3f::hashCode() {
    int n = (int) m_x;
    n = 31 * n + (int) m_y;
    n = 31 * n + (int) m_z;
    return n;
}

void cerver::math::Vector3f::mul(double f) {
    this->m_x *= f;
    this->m_y *= f;
    this->m_z *= f;
}

void cerver::math::Vector3f::set(double f, double f2, double f3) {
    this->m_x = f;
    this->m_y = f2;
    this->m_z = f3;
}

void cerver::math::Vector3f::load(std::shared_ptr<Vector3f> vector3f) {
    this->m_x = vector3f->x();
    this->m_y = vector3f->y();
    this->m_z = vector3f->z();
}

void cerver::math::Vector3f::add(double f, double f2, double f3) {
    this->m_x += f;
    this->m_y += f2;
    this->m_z += f3;
}

void cerver::math::Vector3f::add(std::shared_ptr<Vector3f> vector3f) {
    this->m_x += vector3f->x();
    this->m_y += vector3f->y();
    this->m_z += vector3f->z();
}

void cerver::math::Vector3f::sub(std::shared_ptr<Vector3f> vector3f) {
    this->m_x -= vector3f->x();
    this->m_y -= vector3f->y();
    this->m_z -= vector3f->z();
}

double cerver::math::Vector3f::dot(std::shared_ptr<Vector3f> vector3f) {
    return this->m_x * vector3f->x() + this->m_y * vector3f->y() + this->m_z * vector3f->z();
}

void cerver::math::Vector3f::cross(std::shared_ptr<Vector3f> vector3f) {
    double f = this->m_x;
    double f2 = this->m_y;
    double f3 = this->m_z;
    double f4 = vector3f->x();
    double f5 = vector3f->y();
    double f6 = vector3f->z();
    this->m_x = f2 * f6 - f3 * f5;
    this->m_y = f3 * f4 - f * f6;
    this->m_z = f * f5 - f2 * f4;
}

void cerver::math::Vector3f::transform(std::shared_ptr<Matrix3f> matrix3f) {
    double f = this->m_x;
    double f2 = this->m_y;
    double f3 = this->m_z;
    this->m_x = matrix3f->m00 * f + matrix3f->m01 * f2 + matrix3f->m02 * f3;
    this->m_y = matrix3f->m10 * f + matrix3f->m11 * f2 + matrix3f->m12 * f3;
    this->m_z = matrix3f->m20 * f + matrix3f->m21 * f2 + matrix3f->m22 * f3;
}

void cerver::math::Vector3f::transform(std::shared_ptr<Quaternion> quaternion) {
    Quaternion quaternion2 = Quaternion(quaternion);
    quaternion2.mul(std::make_shared<Quaternion>(this->m_x, this->m_y, this->m_z, 0.0));
    Quaternion quaternion3 = Quaternion(quaternion);
    quaternion3.conj();
    quaternion2.mul(std::make_shared<Quaternion>(quaternion3));
    this->set(quaternion2.i(), quaternion2.j(), quaternion2.k());
}

void cerver::math::Vector3f::lerp(std::shared_ptr<Vector3f> vector3f, double f) {
    double f2 = 1.0 - f;
    this->m_x = f2 * this->m_x + f * vector3f->x();
    this->m_y = f2 * this->m_y + f * vector3f->y();
    this->m_z = f2 * this->m_z + f * vector3f->z();
}

std::shared_ptr<cerver::math::Quaternion> cerver::math::Vector3f::rotation(double f) {
    return std::make_shared<Quaternion>(static_cast<std::shared_ptr<Vector3f>>(this), f, false);
}

std::shared_ptr<cerver::math::Quaternion> cerver::math::Vector3f::rotationDegrees(double f) {
    return std::make_shared<Quaternion>(static_cast<std::shared_ptr<Vector3f>>(this), f, true);
}

std::shared_ptr<cerver::math::Vector3f> cerver::math::Vector3f::copy() {
    return std::make_shared<Vector3f>(this->m_x, this->m_y, this->m_z);
}

std::string cerver::math::Vector3f::toString() const {
    return "[" + std::to_string(this->m_x) + ", " + std::to_string(this->m_y) + ", " +
           std::to_string(this->m_z) + "]";
}



