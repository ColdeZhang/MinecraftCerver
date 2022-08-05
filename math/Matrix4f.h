//
// Created by 张宇衡 on 2022/8/4.
//

#ifndef MINECRAFTCERVER_MATRIX4F_H
#define MINECRAFTCERVER_MATRIX4F_H

#include <vector>
#include <map>
/*
 * equals() 未实现
 */
namespace cerver{
    namespace math{
        class Quaternion;
        class Vector3f;
        class Matrix4f {
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

            Matrix4f(Matrix4f const &matrix4f);

            Matrix4f(Quaternion quaternion);

            bool isInteger();

            static bool isInteger(double f);

            Matrix4f copy();

            void multiply(Matrix4f matrix4f);

            void multiply(Quaternion quaternion);

            void multiply(double d);

            void add(const Matrix4f& matrix4f);

            void subtract(const Matrix4f& matrix4f);

            double trace() const;

            Matrix4f perspective(double fov, double f, double f2, double f3);

            Matrix4f orthographic(double f, double f2, double f3, double f4);

            Matrix4f orthographic(double f, double f2, double f3, double f4, double f5, double f6);

            void translate(Vector3f vector3f);

            void multiplyWithTranslation(double f, double f2, double f3);

            Matrix4f createScaleMatrix(double f, double f2, double f3);

            Matrix4f createTranslateMatrix(double f, double f2, double f3);

            int hashCode() const;

            int bufferIndex(int n, int n2);

            void load(std::map<int, double> buffer);

            void loadTransposed(std::map<int, double> buffer);

            void load(std::map<int, double> buffer, bool bl);

            void load(Matrix4f matrix4f);

            std::string toString();

            void store(std::map<int, double> buffer);

            void storeTransposed(std::map<int, double> buffer);

            void store(std::map<int, double> buffer, bool bl);

            void setIdentity();

            double adjugateAndDet();

            double determinant();

            void transpose();

            bool invert();
        };
    }
}



#endif //MINECRAFTCERVER_MATRIX4F_H
