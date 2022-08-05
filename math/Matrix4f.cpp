//
// Created by 张宇衡 on 2022/8/4.
//

#include "Matrix4f.h"
#include "Quaternion.h"
#include "Vector3f.h"
#include <cmath>

cerver::math::Matrix4f::Matrix4f(std::shared_ptr<Matrix4f> matrix4f) {
    this->m00 = matrix4f->m00;
    this->m01 = matrix4f->m01;
    this->m02 = matrix4f->m02;
    this->m03 = matrix4f->m03;
    this->m10 = matrix4f->m10;
    this->m11 = matrix4f->m11;
    this->m12 = matrix4f->m12;
    this->m13 = matrix4f->m13;
    this->m20 = matrix4f->m20;
    this->m21 = matrix4f->m21;
    this->m22 = matrix4f->m22;
    this->m23 = matrix4f->m23;
    this->m30 = matrix4f->m30;
    this->m31 = matrix4f->m31;
    this->m32 = matrix4f->m32;
    this->m33 = matrix4f->m33;
}

cerver::math::Matrix4f::Matrix4f(std::shared_ptr<Quaternion> quaternion) {
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
    this->m33 = 1.0;
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

bool cerver::math::Matrix4f::isInteger() {
    std::shared_ptr<Matrix4f>matrix4f = std::make_shared<Matrix4f>(Matrix4f());
    matrix4f->m30 = 1.0;
    matrix4f->m31 = 1.0;
    matrix4f->m32 = 1.0;
    matrix4f->m33 = 0.0;
    Matrix4f matrix4f2 = this->copy();
    matrix4f2.multiply(matrix4f);
    return isInteger(matrix4f2.m00 / matrix4f2.m03) && isInteger(matrix4f2.m10 / matrix4f2.m13) && isInteger(matrix4f2.m20 / matrix4f2.m23) && isInteger(matrix4f2.m01 / matrix4f2.m03) && isInteger(matrix4f2.m11 / matrix4f2.m13) && isInteger(matrix4f2.m21 / matrix4f2.m23) && isInteger(matrix4f2.m02 / matrix4f2.m03) && isInteger(matrix4f2.m12 / matrix4f2.m13) && isInteger(matrix4f2.m22 / matrix4f2.m23);
}

bool cerver::math::Matrix4f::isInteger(double f){
    return std::abs(f - std::round(f)) <= 0.000001;
}

std::shared_ptr<cerver::math::Matrix4f> cerver::math::Matrix4f::copy() {
    return std::make_shared<Matrix4f>(*this);
}

void cerver::math::Matrix4f::multiply(std::shared_ptr<Quaternion> quaternion) {
    this->multiply(std::make_shared<Matrix4f>(Matrix4f(quaternion)));
}

void cerver::math::Matrix4f::multiply(std::shared_ptr<Matrix4f> matrix4f) {
    double f = this->m00 * matrix4f->m00 + this->m01 * matrix4f->m10 + this->m02 * matrix4f->m20 + this->m03 * matrix4f->m30;
    double f2 = this->m00 * matrix4f->m01 + this->m01 * matrix4f->m11 + this->m02 * matrix4f->m21 + this->m03 * matrix4f->m31;
    double f3 = this->m00 * matrix4f->m02 + this->m01 * matrix4f->m12 + this->m02 * matrix4f->m22 + this->m03 * matrix4f->m32;
    double f4 = this->m00 * matrix4f->m03 + this->m01 * matrix4f->m13 + this->m02 * matrix4f->m23 + this->m03 * matrix4f->m33;
    double f5 = this->m10 * matrix4f->m00 + this->m11 * matrix4f->m10 + this->m12 * matrix4f->m20 + this->m13 * matrix4f->m30;
    double f6 = this->m10 * matrix4f->m01 + this->m11 * matrix4f->m11 + this->m12 * matrix4f->m21 + this->m13 * matrix4f->m31;
    double f7 = this->m10 * matrix4f->m02 + this->m11 * matrix4f->m12 + this->m12 * matrix4f->m22 + this->m13 * matrix4f->m32;
    double f8 = this->m10 * matrix4f->m03 + this->m11 * matrix4f->m13 + this->m12 * matrix4f->m23 + this->m13 * matrix4f->m33;
    double f9 = this->m20 * matrix4f->m00 + this->m21 * matrix4f->m10 + this->m22 * matrix4f->m20 + this->m23 * matrix4f->m30;
    double f10 = this->m20 * matrix4f->m01 + this->m21 * matrix4f->m11 + this->m22 * matrix4f->m21 + this->m23 * matrix4f->m31;
    double f11 = this->m20 * matrix4f->m02 + this->m21 * matrix4f->m12 + this->m22 * matrix4f->m22 + this->m23 * matrix4f->m32;
    double f12 = this->m20 * matrix4f->m03 + this->m21 * matrix4f->m13 + this->m22 * matrix4f->m23 + this->m23 * matrix4f->m33;
    double f13 = this->m30 * matrix4f->m00 + this->m31 * matrix4f->m10 + this->m32 * matrix4f->m20 + this->m33 * matrix4f->m30;
    double f14 = this->m30 * matrix4f->m01 + this->m31 * matrix4f->m11 + this->m32 * matrix4f->m21 + this->m33 * matrix4f->m31;
    double f15 = this->m30 * matrix4f->m02 + this->m31 * matrix4f->m12 + this->m32 * matrix4f->m22 + this->m33 * matrix4f->m32;
    double f16 = this->m30 * matrix4f->m03 + this->m31 * matrix4f->m13 + this->m32 * matrix4f->m23 + this->m33 * matrix4f->m33;
    this->m00 = f;
    this->m01 = f2;
    this->m02 = f3;
    this->m03 = f4;
    this->m10 = f5;
    this->m11 = f6;
    this->m12 = f7;
    this->m13 = f8;
    this->m20 = f9;
    this->m21 = f10;
    this->m22 = f11;
    this->m23 = f12;
    this->m30 = f13;
    this->m31 = f14;
    this->m32 = f15;
    this->m33 = f16;
}

void cerver::math::Matrix4f::multiply(double d) {
    this->m00 *= d;
    this->m01 *= d;
    this->m02 *= d;
    this->m03 *= d;
    this->m10 *= d;
    this->m11 *= d;
    this->m12 *= d;
    this->m13 *= d;
    this->m20 *= d;
    this->m21 *= d;
    this->m22 *= d;
    this->m23 *= d;
    this->m30 *= d;
    this->m31 *= d;
    this->m32 *= d;
    this->m33 *= d;
}

void cerver::math::Matrix4f::add(std::shared_ptr<Matrix4f> matrix4f) {
    this->m00 += matrix4f->m00;
    this->m01 += matrix4f->m01;
    this->m02 += matrix4f->m02;
    this->m03 += matrix4f->m03;
    this->m10 += matrix4f->m10;
    this->m11 += matrix4f->m11;
    this->m12 += matrix4f->m12;
    this->m13 += matrix4f->m13;
    this->m20 += matrix4f->m20;
    this->m21 += matrix4f->m21;
    this->m22 += matrix4f->m22;
    this->m23 += matrix4f->m23;
    this->m30 += matrix4f->m30;
    this->m31 += matrix4f->m31;
    this->m32 += matrix4f->m32;
    this->m33 += matrix4f->m33;
}

void cerver::math::Matrix4f::subtract(std::shared_ptr<Matrix4f> matrix4f) {
    this->m00 -= matrix4f->m00;
    this->m01 -= matrix4f->m01;
    this->m02 -= matrix4f->m02;
    this->m03 -= matrix4f->m03;
    this->m10 -= matrix4f->m10;
    this->m11 -= matrix4f->m11;
    this->m12 -= matrix4f->m12;
    this->m13 -= matrix4f->m13;
    this->m20 -= matrix4f->m20;
    this->m21 -= matrix4f->m21;
    this->m22 -= matrix4f->m22;
    this->m23 -= matrix4f->m23;
    this->m30 -= matrix4f->m30;
    this->m31 -= matrix4f->m31;
    this->m32 -= matrix4f->m32;
    this->m33 -= matrix4f->m33;
}

double cerver::math::Matrix4f::trace() const {
    return this->m00 + this->m11 + this->m22 + this->m33;
}

std::shared_ptr<cerver::math::Matrix4f> cerver::math::Matrix4f::perspective(double fov, double f, double f2, double f3) {
    double f4 = 1.0 / std::tan(fov * 0.01745329238474369 / 2.0);
    Matrix4f matrix4f = Matrix4f();
    matrix4f.m00 = f4 / f;
    matrix4f.m11 = f4;
    matrix4f.m22 = (f2 + f3) / (f2 - f3);
    matrix4f.m32 = -1.0;
    matrix4f.m23 = 2.0 * f2 * f3 / (f2 - f3);
    return std::make_shared<Matrix4f>(matrix4f);
}

std::shared_ptr<cerver::math::Matrix4f> cerver::math::Matrix4f::orthographic(double f, double f2, double f3, double f4) {
    Matrix4f matrix4f = Matrix4f();
    matrix4f.m00 = 2.0 / f;
    matrix4f.m11 = 2.0 / f2;
    double  f5 = f4 - f3;
    matrix4f.m22 = -2.0 / f5;
    matrix4f.m33 = 1.0;
    matrix4f.m03 = -1.0;
    matrix4f.m13 = 1.0;
    matrix4f.m23 = -(f4 + f3) / f5;
    return std::make_shared<Matrix4f>(matrix4f);
}

std::shared_ptr<cerver::math::Matrix4f>
cerver::math::Matrix4f::orthographic(double f, double f2, double f3, double f4, double f5, double f6) {
    Matrix4f matrix4f = Matrix4f();
    double f7 = f2 - f;
    double f8 = f3 - f4;
    double f9 = f6 - f5;
    matrix4f.m00 = 2.0 / f7;
    matrix4f.m11 = 2.0 / f8;
    matrix4f.m22 = -2.0 / f9;
    matrix4f.m03 = -(f2 + f) / f7;
    matrix4f.m13 = -(f3 + f4) / f8;
    matrix4f.m23 = -(f6 + f5) / f9;
    matrix4f.m33 = 1.0;
    return std::make_shared<Matrix4f>(matrix4f);
}

void cerver::math::Matrix4f::translate(std::shared_ptr<Vector3f> vector3f) {
    this->m03 += vector3f->x();
    this->m13 += vector3f->y();
    this->m23 += vector3f->z();
}

void cerver::math::Matrix4f::multiplyWithTranslation(double f, double f2, double f3) {
    this->m03 = this->m00 * f + this->m01 * f2 + this->m02 * f3 + this->m03;
    this->m13 = this->m10 * f + this->m11 * f2 + this->m12 * f3 + this->m13;
    this->m23 = this->m20 * f + this->m21 * f2 + this->m22 * f3 + this->m23;
    this->m33 = this->m30 * f + this->m31 * f2 + this->m32 * f3 + this->m33;
}

std::shared_ptr<cerver::math::Matrix4f> cerver::math::Matrix4f::createScaleMatrix(double f, double f2, double f3) {
    Matrix4f matrix4f = Matrix4f();
    matrix4f.m00 = f;
    matrix4f.m11 = f2;
    matrix4f.m22 = f3;
    matrix4f.m33 = 1.0;
    return std::make_shared<Matrix4f>(matrix4f);
}

std::shared_ptr<cerver::math::Matrix4f> cerver::math::Matrix4f::createTranslateMatrix(double f, double f2, double f3) {
    Matrix4f matrix4f = Matrix4f();
    matrix4f.m00 = 1.0;
    matrix4f.m11 = 1.0;
    matrix4f.m22 = 1.0;
    matrix4f.m33 = 1.0;
    matrix4f.m03 = f;
    matrix4f.m13 = f2;
    matrix4f.m23 = f3;
    return std::make_shared<Matrix4f>(matrix4f);
}

int cerver::math::Matrix4f::hashCode() const {
    int n = this->m00 != 0.0 ? int(this->m00) : 0;
    n = 31 * n + (this->m01 != 0.0 ? int(this->m01) : 0);
    n = 31 * n + (this->m02 != 0.0 ? int(this->m02) : 0);
    n = 31 * n + (this->m03 != 0.0 ? int(this->m03) : 0);
    n = 31 * n + (this->m10 != 0.0 ? int(this->m10) : 0);
    n = 31 * n + (this->m11 != 0.0 ? int(this->m11) : 0);
    n = 31 * n + (this->m12 != 0.0 ? int(this->m12) : 0);
    n = 31 * n + (this->m13 != 0.0 ? int(this->m13) : 0);
    n = 31 * n + (this->m20 != 0.0 ? int(this->m20) : 0);
    n = 31 * n + (this->m21 != 0.0 ? int(this->m21) : 0);
    n = 31 * n + (this->m22 != 0.0 ? int(this->m22) : 0);
    n = 31 * n + (this->m23 != 0.0 ? int(this->m23) : 0);
    n = 31 * n + (this->m30 != 0.0 ? int(this->m30) : 0);
    n = 31 * n + (this->m31 != 0.0 ? int(this->m31) : 0);
    n = 31 * n + (this->m32 != 0.0 ? int(this->m32) : 0);
    n = 31 * n + (this->m33 != 0.0 ? int(this->m33) : 0);
    return n;
}

int cerver::math::Matrix4f::bufferIndex(int n, int n2) {
    return n2 * 4 + n;
}

void cerver::math::Matrix4f::load(std::map<int, double> buffer) {
    this->m00 = buffer[this->bufferIndex(0, 0)];
    this->m01 = buffer[this->bufferIndex(0, 1)];
    this->m02 = buffer[this->bufferIndex(0, 2)];
    this->m03 = buffer[this->bufferIndex(0, 3)];
    this->m10 = buffer[this->bufferIndex(1, 0)];
    this->m11 = buffer[this->bufferIndex(1, 1)];
    this->m12 = buffer[this->bufferIndex(1, 2)];
    this->m13 = buffer[this->bufferIndex(1, 3)];
    this->m20 = buffer[this->bufferIndex(2, 0)];
    this->m21 = buffer[this->bufferIndex(2, 1)];
    this->m22 = buffer[this->bufferIndex(2, 2)];
    this->m23 = buffer[this->bufferIndex(2, 3)];
    this->m30 = buffer[this->bufferIndex(3, 0)];
    this->m31 = buffer[this->bufferIndex(3, 1)];
    this->m32 = buffer[this->bufferIndex(3, 2)];
    this->m33 = buffer[this->bufferIndex(3, 3)];
}

void cerver::math::Matrix4f::loadTransposed(std::map<int, double> buffer) {
    this->m00 = buffer[this->bufferIndex(0, 0)];
    this->m10 = buffer[this->bufferIndex(1, 0)];
    this->m20 = buffer[this->bufferIndex(2, 0)];
    this->m30 = buffer[this->bufferIndex(3, 0)];
    this->m01 = buffer[this->bufferIndex(0, 1)];
    this->m11 = buffer[this->bufferIndex(1, 1)];
    this->m21 = buffer[this->bufferIndex(2, 1)];
    this->m31 = buffer[this->bufferIndex(3, 1)];
    this->m02 = buffer[this->bufferIndex(0, 2)];
    this->m12 = buffer[this->bufferIndex(1, 2)];
    this->m22 = buffer[this->bufferIndex(2, 2)];
    this->m32 = buffer[this->bufferIndex(3, 2)];
    this->m03 = buffer[this->bufferIndex(0, 3)];
    this->m13 = buffer[this->bufferIndex(1, 3)];
    this->m23 = buffer[this->bufferIndex(2, 3)];
    this->m33 = buffer[this->bufferIndex(3, 3)];
}

void cerver::math::Matrix4f::load(std::map<int, double> buffer, bool bl) {
    if (bl) {
        this->loadTransposed(buffer);
    } else {
        this->load(buffer);
    }
}

void cerver::math::Matrix4f::load(std::shared_ptr<Matrix4f> matrix4f) {
    this->m00 = matrix4f->m00;
    this->m01 = matrix4f->m01;
    this->m02 = matrix4f->m02;
    this->m03 = matrix4f->m03;
    this->m10 = matrix4f->m10;
    this->m11 = matrix4f->m11;
    this->m12 = matrix4f->m12;
    this->m13 = matrix4f->m13;
    this->m20 = matrix4f->m20;
    this->m21 = matrix4f->m21;
    this->m22 = matrix4f->m22;
    this->m23 = matrix4f->m23;
    this->m30 = matrix4f->m30;
    this->m31 = matrix4f->m31;
    this->m32 = matrix4f->m32;
    this->m33 = matrix4f->m33;
}

std::string cerver::math::Matrix4f::toString() {
    std::string stringBuilder("Matrix4f:\n");
    stringBuilder.append(std::to_string(this->m00));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m01));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m02));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m03));
    stringBuilder.append("\n");
    stringBuilder.append(std::to_string(this->m10));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m11));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m12));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m13));
    stringBuilder.append("\n");
    stringBuilder.append(std::to_string(this->m20));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m21));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m22));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m23));
    stringBuilder.append("\n");
    stringBuilder.append(std::to_string(this->m30));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m31));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m32));
    stringBuilder.append(" ");
    stringBuilder.append(std::to_string(this->m33));
    stringBuilder.append("\n");
    return stringBuilder;
}

void cerver::math::Matrix4f::store(std::map<int, double> buffer) {
    buffer[this->bufferIndex(0, 0)] = this->m00;
    buffer[this->bufferIndex(0, 1)] = this->m01;
    buffer[this->bufferIndex(0, 2)] = this->m02;
    buffer[this->bufferIndex(0, 3)] = this->m03;
    buffer[this->bufferIndex(1, 0)] = this->m10;
    buffer[this->bufferIndex(1, 1)] = this->m11;
    buffer[this->bufferIndex(1, 2)] = this->m12;
    buffer[this->bufferIndex(1, 3)] = this->m13;
    buffer[this->bufferIndex(2, 0)] = this->m20;
    buffer[this->bufferIndex(2, 1)] = this->m21;
    buffer[this->bufferIndex(2, 2)] = this->m22;
    buffer[this->bufferIndex(2, 3)] = this->m23;
    buffer[this->bufferIndex(3, 0)] = this->m30;
    buffer[this->bufferIndex(3, 1)] = this->m31;
    buffer[this->bufferIndex(3, 2)] = this->m32;
    buffer[this->bufferIndex(3, 3)] = this->m33;
}

void cerver::math::Matrix4f::storeTransposed(std::map<int, double> buffer) {
    buffer[this->bufferIndex(0, 0)] = this->m00;
    buffer[this->bufferIndex(1, 0)] = this->m10;
    buffer[this->bufferIndex(2, 0)] = this->m20;
    buffer[this->bufferIndex(3, 0)] = this->m30;
    buffer[this->bufferIndex(0, 1)] = this->m01;
    buffer[this->bufferIndex(1, 1)] = this->m11;
    buffer[this->bufferIndex(2, 1)] = this->m21;
    buffer[this->bufferIndex(3, 1)] = this->m31;
    buffer[this->bufferIndex(0, 2)] = this->m02;
    buffer[this->bufferIndex(1, 2)] = this->m12;
    buffer[this->bufferIndex(2, 2)] = this->m22;
    buffer[this->bufferIndex(3, 2)] = this->m32;
    buffer[this->bufferIndex(0, 3)] = this->m03;
    buffer[this->bufferIndex(1, 3)] = this->m13;
    buffer[this->bufferIndex(2, 3)] = this->m23;
    buffer[this->bufferIndex(3, 3)] = this->m33;
}

void cerver::math::Matrix4f::store(std::map<int, double> buffer, bool bl) {
    if (bl) {
        this->storeTransposed(buffer);
    } else {
        this->store(buffer);
    }
}

void cerver::math::Matrix4f::setIdentity() {
    this->m00 = 1.0;
    this->m01 = 0.0;
    this->m02 = 0.0;
    this->m03 = 0.0;
    this->m10 = 0.0;
    this->m11 = 1.0;
    this->m12 = 0.0;
    this->m13 = 0.0;
    this->m20 = 0.0;
    this->m21 = 0.0;
    this->m22 = 1.0;
    this->m23 = 0.0;
    this->m30 = 0.0;
    this->m31 = 0.0;
    this->m32 = 0.0;
    this->m33 = 1.0;
}

double cerver::math::Matrix4f::adjugateAndDet() {
    double f = this->m00 * this->m11 - this->m01 * this->m10;
    double f2 = this->m00 * this->m12 - this->m02 * this->m10;
    double f3 = this->m00 * this->m13 - this->m03 * this->m10;
    double f4 = this->m01 * this->m12 - this->m02 * this->m11;
    double f5 = this->m01 * this->m13 - this->m03 * this->m11;
    double f6 = this->m02 * this->m13 - this->m03 * this->m12;
    double f7 = this->m20 * this->m31 - this->m21 * this->m30;
    double f8 = this->m20 * this->m32 - this->m22 * this->m30;
    double f9 = this->m20 * this->m33 - this->m23 * this->m30;
    double f10 = this->m21 * this->m32 - this->m22 * this->m31;
    double f11 = this->m21 * this->m33 - this->m23 * this->m31;
    double f12 = this->m22 * this->m33 - this->m23 * this->m32;
    double f13 = this->m11 * f12 - this->m12 * f11 + this->m13 * f10;
    double f14 = -this->m10 * f12 + this->m12 * f9 - this->m13 * f8;
    double f15 = this->m10 * f11 - this->m11 * f9 + this->m13 * f7;
    double f16 = -this->m10 * f10 + this->m11 * f8 - this->m12 * f7;
    double f17 = -this->m01 * f12 + this->m02 * f11 - this->m03 * f10;
    double f18 = this->m00 * f12 - this->m02 * f9 + this->m03 * f8;
    double f19 = -this->m00 * f11 + this->m01 * f9 - this->m03 * f7;
    double f20 = this->m00 * f10 - this->m01 * f8 + this->m02 * f7;
    double f21 = this->m31 * f6 - this->m32 * f5 + this->m33 * f4;
    double f22 = -this->m30 * f6 + this->m32 * f3 - this->m33 * f2;
    double f23 = this->m30 * f5 - this->m31 * f3 + this->m33 * f;
    double f24 = -this->m30 * f4 + this->m31 * f2 - this->m32 * f;
    double f25 = -this->m21 * f6 + this->m22 * f5 - this->m23 * f4;
    double f26 = this->m20 * f6 - this->m22 * f3 + this->m23 * f2;
    double f27 = -this->m20 * f5 + this->m21 * f3 - this->m23 * f;
    double f28 = this->m20 * f4 - this->m21 * f2 + this->m22 * f;
    this->m00 = f13;
    this->m01 = f14;
    this->m02 = f15;
    this->m03 = f16;
    this->m10 = f17;
    this->m11 = f18;
    this->m12 = f19;
    this->m13 = f20;
    this->m20 = f21;
    this->m21 = f22;
    this->m22 = f23;
    this->m23 = f24;
    this->m30 = f25;
    this->m31 = f26;
    this->m32 = f27;
    this->m33 = f28;
    return f * f12 - f2 * f11 + f3 * f10 + f4 * f9 - f5 * f8 + f6 * f7;
}

double cerver::math::Matrix4f::determinant() {
    double f = this->m00 * this->m11 - this->m01 * this->m10;
    double f2 = this->m00 * this->m12 - this->m02 * this->m10;
    double f3 = this->m00 * this->m13 - this->m03 * this->m10;
    double f4 = this->m01 * this->m12 - this->m02 * this->m11;
    double f5 = this->m01 * this->m13 - this->m03 * this->m11;
    double f6 = this->m02 * this->m13 - this->m03 * this->m12;
    double f7 = this->m20 * this->m31 - this->m21 * this->m30;
    double f8 = this->m20 * this->m32 - this->m22 * this->m30;
    double f9 = this->m20 * this->m33 - this->m23 * this->m30;
    double f10 = this->m21 * this->m32 - this->m22 * this->m31;
    double f11 = this->m21 * this->m33 - this->m23 * this->m31;
    double f12 = this->m22 * this->m33 - this->m23 * this->m32;
    return f * f12 - f2 * f11 + f3 * f10 + f4 * f9 - f5 * f8 + f6 * f7;
}

void cerver::math::Matrix4f::transpose() {
    double f = this->m10;
    this->m10 = this->m01;
    this->m01 = f;
    f = this->m20;
    this->m20 = this->m02;
    this->m02 = f;
    f = this->m21;
    this->m21 = this->m12;
    this->m12 = f;
    f = this->m30;
    this->m30 = this->m03;
    this->m03 = f;
    f = this->m31;
    this->m31 = this->m13;
    this->m13 = f;
    f = this->m32;
    this->m32 = this->m23;
    this->m23 = f;
}

bool cerver::math::Matrix4f::invert() {
    float f = this->adjugateAndDet();
    if (std::abs(f) > 1.0E-6f) {
        this->multiply(f);
        return true;
    }
    return false;
}












