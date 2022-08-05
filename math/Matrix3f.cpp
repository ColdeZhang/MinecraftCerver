//
// Created by 张宇衡 on 2022/8/4.
//
#include "Quaternion.h"
#include "Matrix3f.h"
#include <utility>
#include "Matrix4f.h"
#include "Vector3f.h"
#include "../minecraft/util/Mth.h"

cerver::math::Matrix3f::Matrix3f(std::shared_ptr<Quaternion> quaternion) {
    double f = quaternion->i();
    double f2 = quaternion->j();
    double f3 = quaternion->k();
    double f4 = quaternion->r();
    double f5 = 2.0 * f * f;
    double f6 = 2.0 * f2 * f2;
    double f7 = 2.0 * f3 * f3;
    this->m00 = 1.0 - f6 - f7;
    this->m11 = 1.0 - f7 - f5;
    this->m22 = 1.0 - f5 - f6;
    double f8 = f * f2;
    double f9 = f2 * f3;
    double f10 = f * f3;
    double f11 = f4 * f;
    double f12 = f4 * f2;
    double f13 = f4 * f3;
    this->m10 = 2.0 * (f8 + f13);
    this->m01 = 2.0 * (f8 - f13);
    this->m20 = 2.0 * (f10 - f12);
    this->m02 = 2.0 * (f10 + f12);
    this->m21 = 2.0 * (f9 + f11);
    this->m12 = 2.0 * (f9 - f11);
}

std::shared_ptr<cerver::math::Matrix3f> cerver::math::Matrix3f::createScaleMatrix(double f, double f2, double f3) {
    Matrix3f matrix3f;
    matrix3f.m00 = f;
    matrix3f.m11 = f2;
    matrix3f.m22 = f3;
    return std::make_shared<Matrix3f>(matrix3f);
}

cerver::math::Matrix3f::Matrix3f(std::shared_ptr<Matrix4f> matrix4f) {
    this->m00 = matrix4f->m00;
    this->m01 = matrix4f->m01;
    this->m02 = matrix4f->m02;
    this->m10 = matrix4f->m10;
    this->m11 = matrix4f->m11;
    this->m12 = matrix4f->m12;
    this->m20 = matrix4f->m20;
    this->m21 = matrix4f->m21;
    this->m22 = matrix4f->m22;
}

cerver::math::Matrix3f::Matrix3f(std::shared_ptr<Matrix3f> matrix3f) {
    this->m00 = matrix3f->m00;
    this->m01 = matrix3f->m01;
    this->m02 = matrix3f->m02;
    this->m10 = matrix3f->m10;
    this->m11 = matrix3f->m11;
    this->m12 = matrix3f->m12;
    this->m20 = matrix3f->m20;
    this->m21 = matrix3f->m21;
    this->m22 = matrix3f->m22;
}

std::pair<double, double> cerver::math::Matrix3f::approxGivensQuat(double f, double f2, double f3) {
    double f4 = f2;
    double f5 = 2.0 * (f - f3);
    if (G * f4 * f4 < f5 * f5) {
        double f6 = cerver::minecraft::util::Mth::fastInvSqrt(f4 * f4 + f5 * f5);
        return {f6 * f4, f6 * f5};
    }
    return {SS, CS};
}

std::pair<double, double> cerver::math::Matrix3f::qrGivensQuat(double f, double f2) {
    double f3;
    double f4 = std::hypot(f, f2);
    double f5 = f4 > 1.0E-6f ? f2 : 0.0f;
    double f6 = std::abs(f) + std::max(f4, 0.0000001);
    if (f < 0.0f) {
        f3 = f5;
        f5 = f6;
        f6 = f3;
    }
    f3 = cerver::minecraft::util::Mth::fastInvSqrt(f6 * f6 + f5 * f5);
    return {(f5 *= f3), (f6 *= f3)};
}

std::shared_ptr<cerver::math::Quaternion> cerver::math::Matrix3f::stepJacobi(std::shared_ptr<Matrix3f> matrix3f) {
    std::pair<int,double> pair;
    double f;
    double f2;
    double f3;
    double f4;
    double f5;
    std::shared_ptr<cerver::math::Quaternion> quaternion = std::make_shared<Quaternion>(Quaternion());
    std::shared_ptr<Matrix3f> matrix3f2 = std::make_shared<Matrix3f>(Matrix3f());
    Quaternion quaternion2 = cerver::math::Quaternion().ONE->copy();
    if (matrix3f->m01 * matrix3f->m01 + matrix3f->m10 * matrix3f->m10 > 0.0000001) {
        pair = approxGivensQuat(matrix3f->m00, 0.5 * (matrix3f->m01 + matrix3f->m10), matrix3f->m11);
        f5 = pair.first;
        f2 = pair.second;
        quaternion = std::make_shared<Quaternion>(Quaternion(0.0, 0.0, f5, f2));
        f4 = f2 * f2 - f5 * f5;
        f3 = -2.0 * f5 * f2;
        f = f * f2 + f5 * f5;
        quaternion2.mul(std::make_shared<Quaternion>(quaternion));
        matrix3f2->setIdentity();
        matrix3f2->m00 = f4;
        matrix3f2->m11 = f4;
        matrix3f2->m10 = -f3;
        matrix3f2->m01 = f3;
        matrix3f2->m22 = f;
        matrix3f->mul(matrix3f2);
        matrix3f2->transpose();
        matrix3f2->mul(matrix3f);
        matrix3f->load(matrix3f2);
    }
    if (matrix3f->m02 * matrix3f->m02 + matrix3f->m20 * matrix3f->m20 > 0.0000001) {
        pair = approxGivensQuat(matrix3f->m00, 0.5 * (matrix3f->m02 + matrix3f->m20), matrix3f->m22);
        double f6 = -(pair.first);
        f2 = pair.second;
        quaternion = std::make_shared<Quaternion>(Quaternion(0.0, f6, 0.0, f2));
        f4 = f2 * f2 - f6 * f6;
        f3 = -2.0 * f6 * f2;
        f = f2 * f2 + f6 * f6;
        quaternion2.mul(quaternion);
        matrix3f2->setIdentity();
        matrix3f2->m00 = f4;
        matrix3f2->m22 = f4;
        matrix3f2->m20 = f3;
        matrix3f2->m02 = -f3;
        matrix3f2->m11 = f;
        matrix3f->mul(matrix3f2);
        matrix3f2->transpose();
        matrix3f2->mul(matrix3f);
        matrix3f->load(matrix3f2);
    }
    if (matrix3f->m12 * matrix3f->m12 + matrix3f->m21 * matrix3f->m21 > 0.0000001) {
        pair = approxGivensQuat(matrix3f->m11, 0.5 * (matrix3f->m12 + matrix3f->m21), matrix3f->m22);
        f5 = pair.first;
        f2 = pair.second;
        quaternion = std::make_shared<Quaternion>(Quaternion(f5, 0.0, 0.0, f2));
        f4 = f2 * f2 - f5 * f5;
        f3 = -2.0 * f5 * f2;
        f = f2 * f2 + f5 * f5;
        quaternion2.mul(quaternion);
        matrix3f2->setIdentity();
        matrix3f2->m11 = f4;
        matrix3f2->m22 = f4;
        matrix3f2->m21 = -f3;
        matrix3f2->m12 = f3;
        matrix3f2->m00 = f;
        matrix3f->mul(matrix3f2);
        matrix3f2->transpose();
        matrix3f2->mul(matrix3f);
        matrix3f->load(matrix3f2);
    }
    return std::make_shared<Quaternion>(quaternion2);
}

void cerver::math::Matrix3f::setIdentity() {
    this->m00 = 1.0f;
    this->m01 = 0.0f;
    this->m02 = 0.0f;
    this->m10 = 0.0f;
    this->m11 = 1.0f;
    this->m12 = 0.0f;
    this->m20 = 0.0f;
    this->m21 = 0.0f;
    this->m22 = 1.0f;
}

double cerver::math::Matrix3f::adjugateAndDet() {
    double f = this->m11 * this->m22 - this->m12 * this->m21;
    double f2 = -(this->m10 * this->m22 - this->m12 * this->m20);
    double f3 = this->m10 * this->m21 - this->m11 * this->m20;
    double f4 = -(this->m01 * this->m22 - this->m02 * this->m21);
    double f5 = this->m00 * this->m22 - this->m02 * this->m20;
    double f6 = -(this->m00 * this->m21 - this->m01 * this->m20);
    double f7 = this->m01 * this->m12 - this->m02 * this->m11;
    double f8 = -(this->m00 * this->m12 - this->m02 * this->m10);
    double f9 = this->m00 * this->m11 - this->m01 * this->m10;
    double f10 = this->m00 * f + this->m01 * f2 + this->m02 * f3;
    this->m00 = f;
    this->m10 = f2;
    this->m20 = f3;
    this->m01 = f4;
    this->m11 = f5;
    this->m21 = f6;
    this->m02 = f7;
    this->m12 = f8;
    this->m22 = f9;
    return f10;
}

double cerver::math::Matrix3f::determinant() const {
    double f = this->m11 * this->m22 - this->m12 * this->m21;
    double f2 = -(this->m10 * this->m22 - this->m12 * this->m20);
    double f3 = this->m10 * this->m21 - this->m11 * this->m20;
    return this->m00 * f + this->m01 * f2 + this->m02 * f3;
}

bool cerver::math::Matrix3f::invert() {
    double f = this->adjugateAndDet();
    if (std::abs(f) > 1.0E-6f) {
        this->mul(f);
        return true;
    }
    return false;
}

void cerver::math::Matrix3f::set(int n, int n2, double f) {
    if (n == 0) {
        if (n2 == 0) {
            this->m00 = f;
        } else if (n2 == 1) {
            this->m01 = f;
        } else {
            this->m02 = f;
        }
    } else if (n == 1) {
        if (n2 == 0) {
            this->m10 = f;
        } else if (n2 == 1) {
            this->m11 = f;
        } else {
            this->m12 = f;
        }
    } else if (n2 == 0) {
        this->m20 = f;
    } else if (n2 == 1) {
        this->m21 = f;
    } else {
        this->m22 = f;
    }
}

void cerver::math::Matrix3f::mul(std::shared_ptr<Matrix3f> matrix3f) {
    double f = this->m00 * matrix3f->m00 + this->m01 * matrix3f->m10 + this->m02 * matrix3f->m20;
    double f2 = this->m00 * matrix3f->m01 + this->m01 * matrix3f->m11 + this->m02 * matrix3f->m21;
    double f3 = this->m00 * matrix3f->m02 + this->m01 * matrix3f->m12 + this->m02 * matrix3f->m22;
    double f4 = this->m10 * matrix3f->m00 + this->m11 * matrix3f->m10 + this->m12 * matrix3f->m20;
    double f5 = this->m10 * matrix3f->m01 + this->m11 * matrix3f->m11 + this->m12 * matrix3f->m21;
    double f6 = this->m10 * matrix3f->m02 + this->m11 * matrix3f->m12 + this->m12 * matrix3f->m22;
    double f7 = this->m20 * matrix3f->m00 + this->m21 * matrix3f->m10 + this->m22 * matrix3f->m20;
    double f8 = this->m20 * matrix3f->m01 + this->m21 * matrix3f->m11 + this->m22 * matrix3f->m21;
    double f9 = this->m20 * matrix3f->m02 + this->m21 * matrix3f->m12 + this->m22 * matrix3f->m22;
    this->m00 = f;
    this->m01 = f2;
    this->m02 = f3;
    this->m10 = f4;
    this->m11 = f5;
    this->m12 = f6;
    this->m20 = f7;
    this->m21 = f8;
    this->m22 = f9;
}

void cerver::math::Matrix3f::mul(std::shared_ptr<Quaternion> quaternion) {
    this->mul(std::make_shared<Matrix3f>(Matrix3f(std::move(quaternion))));
}

void cerver::math::Matrix3f::mul(double f) {
    this->m00 *= f;
    this->m01 *= f;
    this->m02 *= f;
    this->m10 *= f;
    this->m11 *= f;
    this->m12 *= f;
    this->m20 *= f;
    this->m21 *= f;
    this->m22 *= f;
}

void cerver::math::Matrix3f::add(std::shared_ptr<Matrix3f> matrix3f) {
    this->m00 += matrix3f->m00;
    this->m01 += matrix3f->m01;
    this->m02 += matrix3f->m02;
    this->m10 += matrix3f->m10;
    this->m11 += matrix3f->m11;
    this->m12 += matrix3f->m12;
    this->m20 += matrix3f->m20;
    this->m21 += matrix3f->m21;
    this->m22 += matrix3f->m22;
}

void cerver::math::Matrix3f::sub(std::shared_ptr<Matrix3f> matrix3f) {
    this->m00 -= matrix3f->m00;
    this->m01 -= matrix3f->m01;
    this->m02 -= matrix3f->m02;
    this->m10 -= matrix3f->m10;
    this->m11 -= matrix3f->m11;
    this->m12 -= matrix3f->m12;
    this->m20 -= matrix3f->m20;
    this->m21 -= matrix3f->m21;
    this->m22 -= matrix3f->m22;
}

double cerver::math::Matrix3f::trace() const {
    return this->m00 + this->m11 + this->m22;
}

std::shared_ptr<cerver::math::Matrix3f> cerver::math::Matrix3f::copy() {
    return std::make_shared<Matrix3f>(*this);
}

void cerver::math::Matrix3f::store(std::map<int, double> floatBuffer, bool bl) {
    if (bl) {
        this->storeTransposed(floatBuffer);
    } else {
        this->store(floatBuffer);
    }
}

void cerver::math::Matrix3f::storeTransposed(std::map<int, double> floatBuffer) {
    floatBuffer[this->bufferIndex(0, 0)] = this->m00;
    floatBuffer[this->bufferIndex(1, 0)] = this->m01;
    floatBuffer[this->bufferIndex(2, 0)] = this->m02;
    floatBuffer[this->bufferIndex(0, 1)] = this->m10;
    floatBuffer[this->bufferIndex(1, 1)] = this->m11;
    floatBuffer[this->bufferIndex(2, 1)] = this->m12;
    floatBuffer[this->bufferIndex(0, 2)] = this->m20;
    floatBuffer[this->bufferIndex(1, 2)] = this->m21;
    floatBuffer[this->bufferIndex(2, 2)] = this->m22;
}

int cerver::math::Matrix3f::hashCode() {
    int n = this->m00 != 0.0f ? int(this->m00) : 0;
    n = 31 * n + (this->m01 != 0.0 ? int(this->m01) : 0);
    n = 31 * n + (this->m02 != 0.0 ? int(this->m02) : 0);
    n = 31 * n + (this->m10 != 0.0 ? int(this->m10) : 0);
    n = 31 * n + (this->m11 != 0.0 ? int(this->m11) : 0);
    n = 31 * n + (this->m12 != 0.0 ? int(this->m12) : 0);
    n = 31 * n + (this->m20 != 0.0 ? int(this->m20) : 0);
    n = 31 * n + (this->m21 != 0.0 ? int(this->m21) : 0);
    n = 31 * n + (this->m22 != 0.0 ? int(this->m22) : 0);
    return n;
}

int cerver::math::Matrix3f::bufferIndex(int n, int n2) {
    return n2 * 3 + n;
}

void cerver::math::Matrix3f::load(std::map<int, double> floatBuffer) {
    this->m00 = floatBuffer[this->bufferIndex(0, 0)];
    this->m01 = floatBuffer[this->bufferIndex(0, 1)];
    this->m02 = floatBuffer[this->bufferIndex(0, 2)];
    this->m10 = floatBuffer[this->bufferIndex(1, 0)];
    this->m11 = floatBuffer[this->bufferIndex(1, 1)];
    this->m12 = floatBuffer[this->bufferIndex(1, 2)];
    this->m20 = floatBuffer[this->bufferIndex(2, 0)];
    this->m21 = floatBuffer[this->bufferIndex(2, 1)];
    this->m22 = floatBuffer[this->bufferIndex(2, 2)];
}

void cerver::math::Matrix3f::loadTransposed(std::map<int, double> floatBuffer) {
    this->m00 = floatBuffer[this->bufferIndex(0, 0)];
    this->m10 = floatBuffer[this->bufferIndex(1, 0)];
    this->m20 = floatBuffer[this->bufferIndex(2, 0)];
    this->m01 = floatBuffer[this->bufferIndex(0, 1)];
    this->m11 = floatBuffer[this->bufferIndex(1, 1)];
    this->m21 = floatBuffer[this->bufferIndex(2, 1)];
    this->m02 = floatBuffer[this->bufferIndex(0, 2)];
    this->m12 = floatBuffer[this->bufferIndex(1, 2)];
    this->m22 = floatBuffer[this->bufferIndex(2, 2)];
}

void cerver::math::Matrix3f::load(const std::map<int, double>& floatBuffer, bool bl) {
    if (bl) {
        this->loadTransposed(floatBuffer);
    } else {
        this->load(floatBuffer);
    }
}

void cerver::math::Matrix3f::load(std::shared_ptr<Matrix3f> matrix3f) {
    this->m00 = matrix3f->m00;
    this->m01 = matrix3f->m01;
    this->m02 = matrix3f->m02;
    this->m10 = matrix3f->m10;
    this->m11 = matrix3f->m11;
    this->m12 = matrix3f->m12;
    this->m20 = matrix3f->m20;
    this->m21 = matrix3f->m21;
    this->m22 = matrix3f->m22;
}

std::string cerver::math::Matrix3f::toString() const {
    std::string stringBuilder = "Matrix3f:\n";
    stringBuilder.append(std::to_string(this->m00));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m01));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m02));
    stringBuilder.append("\n");
    stringBuilder.append(std::to_string(this->m10));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m11));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m12));
    stringBuilder.append("\n");
    stringBuilder.append(std::to_string(this->m20));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m21));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m22));
    stringBuilder.append("\n");
    return stringBuilder;
}

void cerver::math::Matrix3f::store(std::map<int, double> floatBuffer) {
    floatBuffer[this->bufferIndex(0, 0)] = this->m00;
    floatBuffer[this->bufferIndex(0, 1)] = this->m01;
    floatBuffer[this->bufferIndex(0, 2)] = this->m02;
    floatBuffer[this->bufferIndex(1, 0)] = this->m10;
    floatBuffer[this->bufferIndex(1, 1)] = this->m11;
    floatBuffer[this->bufferIndex(1, 2)] = this->m12;
    floatBuffer[this->bufferIndex(2, 0)] = this->m20;
    floatBuffer[this->bufferIndex(2, 1)] = this->m21;
    floatBuffer[this->bufferIndex(2, 2)] = this->m22;
}

void cerver::math::Matrix3f::transpose() {
    double f = this->m01;
    this->m01 = this->m10;
    this->m10 = f;
    f = this->m02;
    this->m02 = this->m20;
    this->m20 = f;
    f = this->m12;
    this->m12 = this->m21;
    this->m21 = f;
}

void cerver::math::Matrix3f::sortSingularValues(std::shared_ptr<Matrix3f> matrix3f, std::shared_ptr<Quaternion> quaternion) {
    std::shared_ptr<cerver::math::Quaternion> quaternion2;
    double f;
    double f2 = matrix3f->m00 * matrix3f->m00 + matrix3f->m10 * matrix3f->m10 + matrix3f->m20 * matrix3f->m20;
    double f3 = matrix3f->m01 * matrix3f->m01 + matrix3f->m11 * matrix3f->m11 + matrix3f->m21 * matrix3f->m21;
    double f4 = matrix3f->m02 * matrix3f->m02 + matrix3f->m12 * matrix3f->m12 + matrix3f->m22 * matrix3f->m22;
    if (f2 < f3) {
        f = matrix3f->m10;
        matrix3f->m10 = -matrix3f->m00;
        matrix3f->m00 = f;
        f = matrix3f->m11;
        matrix3f->m11 = -matrix3f->m01;
        matrix3f->m01 = f;
        f = matrix3f->m12;
        matrix3f->m12 = -matrix3f->m02;
        matrix3f->m02 = f;
        quaternion2 = std::make_shared<Quaternion>(Quaternion(0.0f, 0.0f, SQ2, SQ2));
        quaternion->mul(quaternion2);
        f = f2;
        f2 = f3;
        f3 = f;
    }
    if (f2 < f4) {
        f = matrix3f->m20;
        matrix3f->m20 = -matrix3f->m00;
        matrix3f->m00 = f;
        f = matrix3f->m21;
        matrix3f->m21 = -matrix3f->m01;
        matrix3f->m01 = f;
        f = matrix3f->m22;
        matrix3f->m22 = -matrix3f->m02;
        matrix3f->m02 = f;
        quaternion2 = std::make_shared<Quaternion>(Quaternion(0.0f, SQ2, 0.0f, SQ2));
        quaternion->mul(quaternion2);
        f4 = f2;
    }
    if (f3 < f4) {
        f = matrix3f->m20;
        matrix3f->m20 = -matrix3f->m10;
        matrix3f->m10 = f;
        f = matrix3f->m21;
        matrix3f->m21 = -matrix3f->m11;
        matrix3f->m11 = f;
        f = matrix3f->m22;
        matrix3f->m22 = -matrix3f->m12;
        matrix3f->m12 = f;
        quaternion2 = std::make_shared<Quaternion>(Quaternion(SQ2, 0.0f, 0.0f, SQ2));
        quaternion->mul(quaternion2);
    }
}

std::tuple<cerver::math::Matrix3f::QuaternionPtr, cerver::math::Matrix3f::Vector3fPtr, cerver::math::Matrix3f::QuaternionPtr>
        cerver::math::Matrix3f::svdDecompose() {
    std::shared_ptr<Quaternion> quaternion = Quaternion().ONE->copy();
    std::shared_ptr<Quaternion> quaternion2 = Quaternion().ONE->copy();
    std::shared_ptr<Matrix3f> matrix3f = this->copy();
    matrix3f->transpose();
    matrix3f->mul(std::make_shared<Matrix3f>(*this));
    for (int i = 0; i < 5; ++i) {
        quaternion2->mul(Matrix3f().stepJacobi(matrix3f));
    }
    quaternion2->normalize();
    std::shared_ptr<Matrix3f> matrix3f2 = std::make_shared<Matrix3f>(*this);
    matrix3f2->mul(std::make_shared<Matrix3f>(quaternion2));
    double f = 1.0;
    std::pair<double, double> pair = Matrix3f().qrGivensQuat(matrix3f2->m00, matrix3f2->m10);
    double f2 = pair.first;
    double f3 = pair.second;
    double f4 = f3 * f3 - f2 * f2;
    double f5 = -2.0 * f2 * f3;
    double f6 = f3 * f3 + f2 * f2;
    std::shared_ptr<Quaternion> quaternion3 = std::make_shared<Quaternion>(0.0f, 0.0f, f2, f3);
    quaternion->mul(quaternion3);
    std::shared_ptr<Matrix3f> matrix3f3 = std::make_shared<Matrix3f>();
    matrix3f3->setIdentity();
    matrix3f3->m00 = f4;
    matrix3f3->m11 = f4;
    matrix3f3->m10 = f5;
    matrix3f3->m01 = -f5;
    matrix3f3->m22 = f6;
    f *= f6;
    matrix3f3->mul(matrix3f2);
    pair = Matrix3f().qrGivensQuat(matrix3f3->m00, matrix3f3->m20);
    double f7 = -(pair.first);
    double f8 = pair.second;
    double f9 = f8 * f8 - f7 * f7;
    double f10 = -2.0 * f7 * f8;
    double f11 = f8 * f8 + f7 * f7;
    std::shared_ptr<Quaternion> quaternion4 =  std::make_shared<Quaternion>(0.0f, f7, 0.0f, f8);
    quaternion->mul(quaternion4);
    std::shared_ptr<Matrix3f> matrix3f4 = std::make_shared<Matrix3f>();
    matrix3f4->setIdentity();
    matrix3f4->m00 = f9;
    matrix3f4->m22 = f9;
    matrix3f4->m20 = -f10;
    matrix3f4->m02 = f10;
    matrix3f4->m11 = f11;
    f *= f11;
    matrix3f4->mul(matrix3f3);
    pair = Matrix3f().qrGivensQuat(matrix3f4->m11, matrix3f4->m21);
    double f12 = pair.first;
    double f13 = pair.second;
    double f14 = f13 * f13 - f12 * f12;
    double f15 = -2.0 * f12 * f13;
    double f16 = f13 * f13 + f12 * f12;
    std::shared_ptr<Quaternion> quaternion5 =  std::make_shared<Quaternion>(f12, 0.0f, 0.0f, f13);
    quaternion->mul(quaternion5);
    std::shared_ptr<Matrix3f> matrix3f5 = std::make_shared<Matrix3f>();
    matrix3f5->setIdentity();
    matrix3f5->m11 = f14;
    matrix3f5->m22 = f14;
    matrix3f5->m21 = f15;
    matrix3f5->m12 = -f15;
    matrix3f5->m00 = f16;
    f *= f16;
    matrix3f5->mul(matrix3f4);
    f = 1.0 / f;
    quaternion->mul(std::sqrt(f));
    std::shared_ptr<Vector3f> vector3f = std::make_shared<Vector3f>(matrix3f5->m00 * f, matrix3f5->m11 * f, matrix3f5->m22 * f);
    return {quaternion, vector3f, quaternion2};
}

