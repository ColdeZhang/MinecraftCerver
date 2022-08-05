//
// Created by 张宇衡 on 2022/8/3.
//

#ifndef MINECRAFTCERVER_VECTOR3F_H
#define MINECRAFTCERVER_VECTOR3F_H

#include <cstdio>
#include <memory>

/*
 * Vector3f(Vec3 vec3) 未实现
 * equals() 未实现
 * clamp(Vector3f vector3f, Vector3f vector3f2) 未实现
 * clamp(float f, float f2) 未实现
 * normalize() 未实现
 * map(Float2FloatFunction float2FloatFunction) 未实现
 */
namespace cerver {
    namespace math {
        class Vector4f;
        class Matrix3f;
        class Quaternion;
        class Vector3f {
        public:
            std::shared_ptr<Vector3f> XN = std::make_shared<Vector3f>(-1.0, 0.0, 0.0);
            std::shared_ptr<Vector3f> XP = std::make_shared<Vector3f>(1.0, 0.0, 0.0);
            std::shared_ptr<Vector3f> YN = std::make_shared<Vector3f>(0.0, -1.0, 0.0);
            std::shared_ptr<Vector3f> YP = std::make_shared<Vector3f>(0.0, 1.0, 0.0);
            std::shared_ptr<Vector3f> ZN = std::make_shared<Vector3f>(0.0, 0.0, -1.0);
            std::shared_ptr<Vector3f> ZP = std::make_shared<Vector3f>(0.0, 0.0, 1.0);
            std::shared_ptr<Vector3f> ZERO = std::make_shared<Vector3f>(0.0, 0.0, 0.0);

            Vector3f() = default;

            Vector3f(double f, double f2, double f3);

            explicit Vector3f(Vector4f vector4f);

            int hashCode();

            double x() const { return this->m_x; }

            double y() const { return this->m_y; }

            double z() const { return this->m_z; }

            void mul(double f);

            void set(double f, double f2, double f3);

            void load(const Vector3f& vector3f);

            void add(double f, double f2, double f3);

            void add(const Vector3f& vector3f);

            void sub(Vector3f vector3f);

            double dot(Vector3f vector3f);

            void cross(Vector3f vector3f);

            void transform(Matrix3f matrix3f);

            void transform(const Quaternion &quaternion);

            void lerp(const Vector3f& vector3f, double f);

            Quaternion rotation(double f);

            Quaternion rotationDegrees(double f);

            std::shared_ptr<Vector3f> copy();

            std::string toString() const;

        private:
            double m_x;
            double m_y;
            double m_z;
        };
    }
}
#endif //MINECRAFTCERVER_VECTOR3F_H
