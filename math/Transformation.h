//
// Created by deer on 2022/8/5.
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
            Matrix4fPtr matrix;
            bool decomposed;
            Vector3fPtr translation;
            QuaternionPtr leftRotation;
            Vector3fPtr scale;
            QuaternionPtr rightRotation;

            TransformationPtr IDENTITY;

        public:
            Transformation() = default;

            explicit Transformation(const Matrix4fPtr& matrix4f);

            Transformation(const Vector3fPtr& vector3f, const QuaternionPtr& quaternion, const Vector3fPtr& vector3f2, const QuaternionPtr& quaternion2);

            TransformationPtr identity();

            TransformationPtr compose(const TransformationPtr& transformation);

            TransformationPtr inverse();

            std::pair<Matrix3fPtr, Vector3fPtr> toAffine(const Matrix4fPtr& matrix4f);

            Matrix4fPtr getMatrix();

            Vector3fPtr getTranslation();

            QuaternionPtr getLeftRotation();

            Vector3fPtr getScale();

            QuaternionPtr getRightRotation();

            bool equals();

            int hashCode();

            TransformationPtr slerp(const TransformationPtr& transformation, double f);



        private:
            void ensureDecomposed();

            Matrix4fPtr compose(const Vector3fPtr& vector3f, const QuaternionPtr& quaternion, const Vector3fPtr& vector3f2, const QuaternionPtr& quaternion2);


        };
    }
}


#endif //MINECRAFTCERVER_TRANSFORMATION_H
