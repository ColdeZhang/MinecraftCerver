//
// Created by deer on 2022/8/4.
//

#ifndef MINECRAFTCERVER_MATRIX4F_H
#define MINECRAFTCERVER_MATRIX4F_H

#include <vector>
#include <map>
#include "Constants.h"

/*
 * equals() 未实现
 */
namespace cerver{
    namespace math{
        class Quaternion;
        class Vector3f;
        class Matrix4f {

            typedef std::shared_ptr<Quaternion> QuaternionPtr;
            typedef std::shared_ptr<Vector3f> Vector3fPtr;
            typedef std::shared_ptr<Matrix4f> Matrix4fPtr;

        public:
            int ORDER = 4;
            double m00{};
            double m01{};
            double m02{};
            double m03{};
            double m10{};
            double m11{};
            double m12{};
            double m13{};
            double m20{};
            double m21{};
            double m22{};
            double m23{};
            double m30{};
            double m31{};
            double m32{};
            double m33{};

        public:
            Matrix4f() = default;

            Matrix4f(Matrix4fPtr matrix4f);

            Matrix4f(QuaternionPtr quaternion);

            bool isInteger();

            static bool isInteger(double f);

            Matrix4fPtr copy();

            void multiply(Matrix4fPtr matrix4f);

            void multiply(QuaternionPtr quaternion);

            void multiply(double d);

            void add(Matrix4fPtr matrix4f);

            void subtract(Matrix4fPtr matrix4f);

            double trace() const;

            Matrix4fPtr perspective(double fov, double f, double f2, double f3);

            Matrix4fPtr orthographic(double f, double f2, double f3, double f4);

            Matrix4fPtr orthographic(double f, double f2, double f3, double f4, double f5, double f6);

            void translate(Vector3fPtr vector3f);

            void multiplyWithTranslation(double f, double f2, double f3);

            Matrix4fPtr createScaleMatrix(double f, double f2, double f3);

            Matrix4fPtr createTranslateMatrix(double f, double f2, double f3);

            int hashCode() const;

            int bufferIndex(int n, int n2);

            void load(FloatBuffer buffer);

            void loadTransposed(FloatBuffer buffer);

            void load(FloatBuffer buffer, bool bl);

            void load(Matrix4fPtr matrix4f);

            std::string toString();

            void store(FloatBuffer buffer);

            void storeTransposed(FloatBuffer buffer);

            void store(FloatBuffer buffer, bool bl);

            void setIdentity();

            double adjugateAndDet();

            double determinant();

            void transpose();

            bool invert();
        };
    }
}



#endif //MINECRAFTCERVER_MATRIX4F_H
