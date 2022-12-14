//
// Created by deer on 2022/8/3.
//

#ifndef MINECRAFTCERVER_MATRIX3F_H
#define MINECRAFTCERVER_MATRIX3F_H

#include <cmath>
#include <map>
#include "Constants.h"

namespace cerver {
    namespace math {
        class Quaternion;
        class Matrix4f;
        class Vector3f;
        class Matrix3f {

            typedef std::shared_ptr<Matrix4f> Matrix4fPtr;
            typedef std::shared_ptr<Quaternion> QuaternionPtr;
            typedef std::shared_ptr<Matrix3f> Matrix3fPtr;
            typedef std::shared_ptr<Vector3f> Vector3fPtr;

        private:
            int ORDER = 3;
            double G = 3.0 + 2.0 + sqrt(2.0);
            double CS = cos(0.39269908169872414);
            double SS = sin(0.39269908169872414);
            double SQ2 = 1.0 / sqrt(2.0);
        public:
            double m00{};
            double m01{};
            double m02{};
            double m10{};
            double m11{};
            double m12{};
            double m20{};
            double m21{};
            double m22{};
        public:
            Matrix3f() = default;

            explicit Matrix3f(const QuaternionPtr& quaternion);

            explicit Matrix3f(const Matrix4fPtr& matrix4f);

            explicit Matrix3f(const Matrix3fPtr& matrix3f);

            static Matrix3fPtr createScaleMatrix(double f, double f2, double f3);

            int hashCode() const;

            static int bufferIndex(int n, int n2);

            void load(FloatBuffer floatBuffer);

            void loadTransposed(FloatBuffer floatBuffer);

            void load(const FloatBuffer& floatBuffer, bool bl);

            void load(const Matrix3fPtr& matrix3f);

            std::string toString() const;

            void store(FloatBuffer floatBuffer);

            void storeTransposed(FloatBuffer floatBuffer);

            void store(const FloatBuffer& floatBuffer, bool bl);

            void setIdentity();

            double adjugateAndDet();

            double determinant() const;

            bool invert();

            void set(int n, int n2, double f);

            void mul(const Matrix3fPtr& matrix3f);

            void mul(const QuaternionPtr& quaternion);

            void mul(double f);

            void add(const Matrix3fPtr& matrix3f);

            void sub(const Matrix3fPtr& matrix3f);

            double trace() const;

            Matrix3fPtr copy();

            void transpose();

            std::tuple<QuaternionPtr, Vector3fPtr, QuaternionPtr> svdDecompose();

        private:
            std::pair<double, double> approxGivensQuat(double f, double f2, double f3);

            void sortSingularValues(const Matrix3fPtr& matrix3f, const QuaternionPtr& quaternion);

            static std::pair<double, double> qrGivensQuat(double f, double f2);

            QuaternionPtr stepJacobi(const Matrix3fPtr& matrix3f);

        };
    }
}

#endif //MINECRAFTCERVER_MATRIX3F_H
