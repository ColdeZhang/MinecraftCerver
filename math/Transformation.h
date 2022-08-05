//
// Created by 张宇衡 on 2022/8/5.
//

#ifndef MINECRAFTCERVER_TRANSFORMATION_H
#define MINECRAFTCERVER_TRANSFORMATION_H

#include <cstdio>
#include <memory>

namespace cerver {
    namespace math {
        class Quaternion;

        class Vector3f;

        class Matrix4f;

        class Matrix3f;

        class Transformation {
            typedef std::shared_ptr<Matrix4f> Matrix4fPtr;
            typedef std::shared_ptr<Vector3f> Vector3fPtr;
            typedef std::shared_ptr<Quaternion> QuaternionPtr;
            typedef std::shared_ptr<Matrix3f> Matrix3fPtr;
            typedef std::shared_ptr<Transformation> TransformationPtr;
        private:
            Matrix4fPtr matrix4f;
            Matrix4fPtr matrix;
            bool decomposed;
            Vector3fPtr translation;
            QuaternionPtr leftRotation;
            Vector3fPtr scale;
            QuaternionPtr rightRotation;

            TransformationPtr IDENTITY;

        public:
            explicit Transformation(Matrix4fPtr matrix4f);

            Transformation(Vector3fPtr vector3f, QuaternionPtr quaternion, Vector3fPtr vector3f2, QuaternionPtr quaternion2);

            TransformationPtr identity();

            TransformationPtr compose(TransformationPtr transformation);

            TransformationPtr inverse();

        private:
            void ensureDecomposed();

            Matrix4fPtr compose(Vector3fPtr vector3f, QuaternionPtr quaternion, Vector3fPtr vector3f2, QuaternionPtr quaternion2);

            std::pair<Matrix3fPtr, Vector3fPtr> toAffine(Matrix4fPtr matrix4f);
        };
    }
}


#endif //MINECRAFTCERVER_TRANSFORMATION_H
