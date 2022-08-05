//
// Created by 张宇衡 on 2022/8/3.
//

#ifndef MINECRAFTCERVER_MATRIX3F_H
#define MINECRAFTCERVER_MATRIX3F_H

#include <cmath>
#include <map>

namespace cerver {
    namespace math {
        class Quaternion;
        class Matrix4f;
        class Matrix3f {
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

            explicit Matrix3f(Quaternion quaternion);

            static Matrix3f createScaleMatrix(double f, double f2, double f3);

            explicit Matrix3f(Matrix4f matrix4f);

            Matrix3f(Matrix3f const &matrix3f);

            int hashCode();

            static int bufferIndex(int n, int n2);

            void load(std::map<int, double> floatBuffer);

            void loadTransposed(std::map<int, double> floatBuffer);

            void load(const std::map<int, double>& floatBuffer, bool bl);

            void load(const Matrix3f& matrix3f);

            std::string toString() const;

            void store(std::map<int, double> floatBuffer);

            void storeTransposed(std::map<int, double> floatBuffer);

            void store(std::map<int, double> floatBuffer, bool bl);

            void setIdentity();

            double adjugateAndDet();

            double determinant() const;

            bool invert();

            void set(int n, int n2, double f);

            void mul(const Matrix3f& matrix3f);

            void mul(Quaternion quaternion);

            void mul(double f);

            void add(const Matrix3f& matrix3f);

            void sub(const Matrix3f& matrix3f);

            double trace() const;

            Matrix3f copy();

            void transpose();

        private:
            std::pair<double, double> approxGivensQuat(double f, double f2, double f3);

            void sortSingularValues(Matrix3f matrix3f, Quaternion quaternion);

            std::pair<double, double> qrGivensQuat(double f, double f2);

            Quaternion stepJacobi(Matrix3f matrix3f);

        };
    }
}

#endif //MINECRAFTCERVER_MATRIX3F_H
