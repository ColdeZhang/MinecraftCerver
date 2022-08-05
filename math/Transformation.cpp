//
// Created by 张宇衡 on 2022/8/5.
//

#include "Transformation.h"
#include "Vector3f.h"
#include "Matrix3f.h"
#include "Quaternion.h"
#include "Matrix4f.h"

cerver::math::Transformation::Transformation(const std::shared_ptr<Matrix4f>& matrix4f) {
    this->matrix = (matrix4f == nullptr) ? this->IDENTITY->matrix : matrix4f;
}

cerver::math::Transformation::Transformation(const std::shared_ptr<Vector3f>& vector3f, const std::shared_ptr<Quaternion>& quaternion,
                                             const std::shared_ptr<Vector3f>& vector3f2, const std::shared_ptr<Quaternion>& quaternion2) {
    this->matrix = Transformation().compose(vector3f, quaternion, vector3f2, quaternion2);
    this->translation = (vector3f != nullptr) ? vector3f : std::make_shared<Vector3f>();
    this->leftRotation = (quaternion != nullptr) ? quaternion : Quaternion().ONE->copy();
    this->scale = (vector3f2 != nullptr) ? vector3f2 : std::make_shared<Vector3f>(1.0f, 1.0f, 1.0f);
    this->rightRotation = (quaternion2 != nullptr) ? quaternion2 : Quaternion().ONE->copy();
    this->decomposed = true;
}

cerver::math::Transformation::TransformationPtr cerver::math::Transformation::identity() {
    return this->IDENTITY;
}

cerver::math::Transformation::TransformationPtr
cerver::math::Transformation::compose(const cerver::math::Transformation::TransformationPtr& transformation) {
    std::shared_ptr<Matrix4f> matrix4f = this->getMatrix();
    matrix4f->multiply(transformation->getMatrix());
    return std::make_shared<Transformation>(matrix4f);
}

cerver::math::Transformation::TransformationPtr cerver::math::Transformation::inverse() {
    if (std::make_shared<Transformation>(*this) == IDENTITY){
        return std::make_shared<Transformation>(*this);
    }
    std::shared_ptr<Matrix4f> matrix4f = this->getMatrix();
    if (matrix4f->invert()){
        return std::make_shared<Transformation>(matrix4f);
    }
    return nullptr;
}

std::pair<std::shared_ptr<cerver::math::Matrix3f>, std::shared_ptr<cerver::math::Vector3f>>
cerver::math::Transformation::toAffine(const cerver::math::Transformation::Matrix4fPtr& matrix4f) {
    matrix4f->multiply(1.0 / matrix4f->m33);
    Vector3f vector3f = Vector3f(matrix4f->m03, matrix4f->m13, matrix4f->m23);
    Matrix3f matrix3f = Matrix3f(matrix4f);
    return {std::make_shared<Matrix3f>(matrix3f), std::make_shared<Vector3f>(vector3f)};
}

cerver::math::Transformation::Matrix4fPtr cerver::math::Transformation::getMatrix() {
    return this->matrix->copy();
}

cerver::math::Transformation::Vector3fPtr cerver::math::Transformation::getTranslation() {
    this->ensureDecomposed();
    return this->translation->copy();
}

cerver::math::Transformation::QuaternionPtr cerver::math::Transformation::getLeftRotation() {
    this->ensureDecomposed();
    return this->leftRotation->copy();
}

cerver::math::Transformation::Vector3fPtr cerver::math::Transformation::getScale() {
    this->ensureDecomposed();
    return this->scale->copy();
}

cerver::math::Transformation::QuaternionPtr cerver::math::Transformation::getRightRotation() {
    this->ensureDecomposed();
    return this->rightRotation->copy();
}

int cerver::math::Transformation::hashCode() {
    std::hash<std::shared_ptr<cerver::math::Matrix4f>> hashM4;
    return (int)hashM4(this->matrix);
}

cerver::math::Transformation::TransformationPtr
cerver::math::Transformation::slerp(const cerver::math::Transformation::TransformationPtr& transformation, double f) {
    std::shared_ptr<Vector3f> vector3f = this->getTranslation();
    std::shared_ptr<Quaternion> quaternion = this->getLeftRotation();
    std::shared_ptr<Vector3f> vector3f2 = this->getScale();
    std::shared_ptr<Quaternion> quaternion2 = this->getRightRotation();
    vector3f->lerp(transformation->getTranslation(), f);
    quaternion->slerp(transformation->getLeftRotation(), f);
    vector3f2->lerp(transformation->getScale(), f);
    quaternion2->slerp(transformation->getRightRotation(), f);
    return std::make_shared<Transformation>(vector3f, quaternion, vector3f2, quaternion2);
}

void cerver::math::Transformation::ensureDecomposed() {
    if (!this->decomposed){
        std::pair<std::shared_ptr<cerver::math::Matrix3f>, std::shared_ptr<cerver::math::Vector3f>> pair = Transformation().toAffine(
                this->matrix);
        std::tuple<std::shared_ptr<cerver::math::Quaternion>, std::shared_ptr<cerver::math::Vector3f>, std::shared_ptr<cerver::math::Quaternion>> triple = pair.first->svdDecompose();
        this->translation = pair.second;
        this->leftRotation = std::get<0>(triple);
        this->scale = std::get<1>(triple);
        this->rightRotation = std::get<2>(triple);
        this->decomposed = true;
    }
}

cerver::math::Transformation::Matrix4fPtr
cerver::math::Transformation::compose(const cerver::math::Transformation::Vector3fPtr& vector3f,
                                      const cerver::math::Transformation::QuaternionPtr& quaternion,
                                      const cerver::math::Transformation::Vector3fPtr& vector3f2,
                                      const cerver::math::Transformation::QuaternionPtr& quaternion2) {
    std::shared_ptr<Matrix4f> matrix4f =  std::make_shared<Matrix4f>();
    matrix4f->setIdentity();
    if (quaternion != nullptr) {
        matrix4f->multiply(std::make_shared<Matrix4f>(quaternion));
    }
    if (vector3f2 != nullptr) {
        matrix4f->multiply(Matrix4f().createScaleMatrix(vector3f2->x(), vector3f2->y(), vector3f2->z()));
    }
    if (quaternion2 != nullptr) {
        matrix4f->multiply(std::make_shared<Matrix4f>(quaternion2));
    }
    if (vector3f != nullptr) {
        matrix4f->m03 = vector3f->x();
        matrix4f->m13 = vector3f->y();
        matrix4f->m23 = vector3f->z();
    }
    return matrix4f;
}

