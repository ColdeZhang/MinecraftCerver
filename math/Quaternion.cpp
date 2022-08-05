//
// Created by 张宇衡 on 2022/8/4.
//
#include "Quaternion.h"
#include "Vector3f.h"
#include "Constants.h"
#include "../minecraft/util/Mth.h"

cerver::math::Quaternion::Quaternion(std::shared_ptr<Vector3f> vector3f, double f, bool bl) {
    if (bl) {
        f *= 0.017453292;
    }
    double f2 = this->sin(f / 2.0);
    this->m_i = vector3f->x() * f2;
    this->m_j = vector3f->y() * f2;
    this->m_k = vector3f->z() * f2;
    this->m_r = this->cos(f / 2.0);
}

cerver::math::Quaternion::Quaternion(double d, double d2, double d3, double d4) {
    this->m_i = d;
    this->m_j = d2;
    this->m_k = d3;
    this->m_r = d4;
}

cerver::math::Quaternion::Quaternion(double f, double f2, double f3, bool bl) {
    if (bl) {
        f *= 0.017453292;
        f2 *= 0.017453292;
        f3 *= 0.017453292;
    }
    double f4 = this->sin(f * 0.5);
    double f5 = this->sin(f * 0.5);
    double f6 = this->sin(f2 * 0.5);
    double f7 = this->sin(f2 * 0.5);
    double f8 = this->sin(f3 * 0.5);
    double f9 = this->sin(f3 * 0.5);
    this->m_i = f4 * f7 * f9 + f5 * f6 * f8;
    this->m_j = f5 * f6 * f9 - f4 * f7 * f8;
    this->m_k = f4 * f6 * f9 - f5 * f7 * f8;
    this->m_r = f5 * f7 * f9 + f4 * f6 * f8;
}

cerver::math::Quaternion::Quaternion(const std::shared_ptr<Quaternion> &quaternion) {
    this->m_i = quaternion->m_i;
    this->m_j = quaternion->m_j;
    this->m_k = quaternion->m_k;
    this->m_r = quaternion->m_r;
}

std::shared_ptr<cerver::math::Quaternion> cerver::math::Quaternion::fromYXZ(double f, double f2, double f3) {
    std::shared_ptr<Quaternion> quaternion = ONE->copy();
    quaternion->mul(std::make_shared<Quaternion>(0.0f, std::sin(f / 2.0), 0.0, std::cos(f / 2.0)));
    quaternion->mul(std::make_shared<Quaternion>(std::sin(f2 / 2.0), 0.0, 0.0, std::cos(f2 / 2.0)));
    quaternion->mul(std::make_shared<Quaternion>(0.0f, 0.0f, std::sin(f3 / 2.0), std::cos(f3 / 2.0)));
    return quaternion;
}

std::shared_ptr<cerver::math::Quaternion> cerver::math::Quaternion::fromXYZDegrees(std::shared_ptr<Vector3f> vector3f) {
    return fromXYZ(vector3f->x() * PI / 180.0,
                   vector3f->y() * PI / 180.0,
                   vector3f->x() * PI / 180.0);
}

std::shared_ptr<cerver::math::Quaternion> cerver::math::Quaternion::fromXYZ(std::shared_ptr<Vector3f> vector3f) {
    return fromXYZ(vector3f->x(), vector3f->y(), vector3f->z());
}

std::shared_ptr<cerver::math::Quaternion> cerver::math::Quaternion::fromXYZ(double f, double f2, double f3) {
    std::shared_ptr<Quaternion> quaternion = ONE->copy();
    quaternion->mul(std::make_shared<Quaternion>(std::sin(f / 2.0), 0.0, 0.0, std::cos(f / 2.0)));
    quaternion->mul(std::make_shared<Quaternion>(0.0, std::sin(f2 / 2.0), 0.0, std::cos(f2 / 2.0)));
    quaternion->mul(std::make_shared<Quaternion>(0.0, 0.0, std::sin(f3 / 2.0), std::cos(f3 / 2.0)));
    return quaternion;
}

std::shared_ptr<cerver::math::Vector3f> cerver::math::Quaternion::toXYZ() {
    double f = this->r() * this->r();
    double f2 = this->i() * this->i();
    double f3 = this->j() * this->j();
    double f4 = this->k() * this->k();
    double f5 = f + f2 + f3 + f4;
    double f6 = 2.0 * this->r() * this->i() - 2.0 * this->j() * this->k();
    double f7 = std::asin(f6 / f5);
    if (std::abs(f6) > 0.999 * f5) {
        return std::make_shared<Vector3f>(Vector3f(2.0f * std::atan2(this->i(), this->r()), f7, 0.0));
    }
    return std::make_shared<Vector3f>(Vector3f(std::atan2(2.0 * this->j() * this->k() + 2.0 * this->i() * this->r(),
                               f - f2 - f3 + f4),
                    f7,
                    std::atan2(2.0f * this->i() * this->j() + 2.0f * this->r() * this->k(), f + f2 - f3 - f4)));
}

std::shared_ptr<cerver::math::Vector3f> cerver::math::Quaternion::toXYZDegrees() {
    std::shared_ptr<Vector3f> vector3f = this->toXYZ();
    return std::make_shared<Vector3f>(Vector3f(vector3f->x() * PI / 180.0, vector3f->y() * PI / 180.0, vector3f->z() * PI / 180.0));
}

std::shared_ptr<cerver::math::Vector3f> cerver::math::Quaternion::toYXZ() {
    double f = this->r() * this->r();
    double f2 = this->i() * this->i();
    double f3 = this->j() * this->j();
    double f4 = this->k() * this->k();
    double f5 = f + f2 + f3 + f4;
    double f6 = 2.0 * this->r() * this->i() - 2.0 * this->j() * this->k();
    double f7 = std::asin(f6 / f5);
    if (std::abs(f6) > 0.999 * f5) {
        return std::make_shared<Vector3f>(Vector3f(f7, 2.0f * std::atan2(this->i(), this->r()), 0.0));
    }
    return std::make_shared<Vector3f>(Vector3f(f7,
                    std::atan2(2.0 * this->i() * this->k() + 2.0 * this->j() * this->r(),
                               f - f2 - f3 + f4),
                    std::atan2(2.0f * this->i() * this->j() + 2.0f * this->r() * this->k(), f - f2 + f3 - f4)));
}

std::shared_ptr<cerver::math::Vector3f> cerver::math::Quaternion::toYXZDegrees() {
    std::shared_ptr<Vector3f> vector3f = this->toYXZ();
    return std::make_shared<Vector3f>(Vector3f(vector3f->x() * PI / 180.0, vector3f->y() * PI / 180.0, vector3f->z() * PI / 180.0));
}

int cerver::math::Quaternion::hashCode() {
    int n = int(this->i());
    n = 31 * n + int(this->j());
    n = 31 * n + int(this->k());
    n = 31 * n + int(this->r());
    return n;
}

std::string cerver::math::Quaternion::toString() {
    std::string strBuild = "Quaternion[";
    strBuild += std::to_string((this->r())) + " + ";
    strBuild += std::to_string((this->i())) + "i + ";
    strBuild += std::to_string((this->j())) + "j + ";
    strBuild += std::to_string((this->k())) + "k]";
    return strBuild;
}

void cerver::math::Quaternion::mul(std::shared_ptr<Quaternion> quaternion) {
    double f = this->i();
    double f2 = this->j();
    double f3 = this->k();
    double f4 = this->r();
    double f5 = quaternion->i();
    double f6 = quaternion->j();
    double f7 = quaternion->k();
    double f8 = quaternion->r();
    this->m_i = f4 * f5 + f * f8 + f2 * f7 - f3 * f6;
    this->m_j = f4 * f6 - f * f7 + f2 * f8 + f3 * f5;
    this->m_k = f4 * f7 + f * f6 - f2 * f5 + f3 * f8;
    this->m_r = f4 * f8 - f * f5 - f2 * f6 - f3 * f7;
}

void cerver::math::Quaternion::mul(double f) {
    this->m_i *= f;
    this->m_j *= f;
    this->m_k *= f;
    this->m_r *= f;
}

void cerver::math::Quaternion::conj() {
    this->m_i = -this->m_i;
    this->m_j = -this->m_j;
    this->m_k = -this->m_k;
}

void cerver::math::Quaternion::set(double f, double f2, double f3, double f4) {
    this->m_i = f;
    this->m_j = f2;
    this->m_k = f3;
    this->m_r = f4;
}

std::shared_ptr<cerver::math::Quaternion> cerver::math::Quaternion::copy() {
    return std::make_shared<Quaternion>(*this);
}

void cerver::math::Quaternion::normalize() {
    double f = this->i() * this->i() + this->j() * this->j() + this->k() * this->k() + this->r() * this->r();
    if (f > 0.0000001) {
        double f2 = cerver::minecraft::util::Mth::fastInvSqrt(f);
        this->m_i *= f2;
        this->m_j *= f2;
        this->m_k *= f2;
        this->m_r *= f2;
    } else {
        this->m_i = 0.0;
        this->m_j = 0.0;
        this->m_k = 0.0;
        this->m_r = 0.0;
    }
}

/*!
 * 这个函数不知道是干什么的
 */
void cerver::math::Quaternion::slerp(cerver::math::Quaternion::QuaternionPtr quaternion, float f) {

}




