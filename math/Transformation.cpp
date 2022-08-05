//
// Created by 张宇衡 on 2022/8/5.
//

#include "Transformation.h"
#include "Vector3f.h"
#include "Matrix3f.h"
#include "Quaternion.h"
#include "Matrix4f.h"

cerver::math::Transformation::Transformation(std::shared_ptr<Matrix4f> matrix4f) {
    this->matrix = (matrix4f == nullptr) ? this->IDENTITY->matrix : matrix4f;
}

cerver::math::Transformation::Transformation(std::shared_ptr<Vector3f> vector3f, std::shared_ptr<Quaternion> quaternion,
                                             std::shared_ptr<Vector3f> vector3f2, std::shared_ptr<Quaternion> quaternion2) {
    this->matrix = Transformation.compose(vector3f, quaternion, vector3f2, quaternion2);
    this->translation = (vector3f != nullptr) ? vector3f : std::make_shared<Vector3f>();
    this->leftRotation = (quaternion != nullptr) ? quaternion : Quaternion().ONE->copy();
    this->scale = (vector3f2 != nullptr) ? vector3f2 : std::make_shared<Vector3f>(1.0f, 1.0f, 1.0f);
    this->rightRotation = (quaternion2 != nullptr) ? quaternion2 : Quaternion().ONE->copy();
    this->decomposed = true;
}

