//
// Created by deer on 2022/8/3.
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

            typedef std::shared_ptr<Vector3f> Vector3fPtr;
            typedef std::shared_ptr<Vector4f> Vector4fPtr;
            typedef std::shared_ptr<Quaternion> QuaternionPtr;
            typedef std::shared_ptr<Matrix3f> Matrix3fPtr;

        public:
            Vector3fPtr XN = std::make_shared<Vector3f>(-1.0, 0.0, 0.0);
            Vector3fPtr XP = std::make_shared<Vector3f>(1.0, 0.0, 0.0);
            Vector3fPtr YN = std::make_shared<Vector3f>(0.0, -1.0, 0.0);
            Vector3fPtr YP = std::make_shared<Vector3f>(0.0, 1.0, 0.0);
            Vector3fPtr ZN = std::make_shared<Vector3f>(0.0, 0.0, -1.0);
            Vector3fPtr ZP = std::make_shared<Vector3f>(0.0, 0.0, 1.0);
            Vector3fPtr ZERO = std::make_shared<Vector3f>(0.0, 0.0, 0.0);

            Vector3f() = default;

            Vector3f(double f, double f2, double f3);

            explicit Vector3f(Vector4fPtr vector4f);

            int hashCode();

            double x() const { return this->m_x; }

            double y() const { return this->m_y; }

            double z() const { return this->m_z; }

            void mul(double f);

            void set(double f, double f2, double f3);

            void load(Vector3fPtr vector3f);

            void add(double f, double f2, double f3);

            void add(Vector3fPtr vector3f);

            void sub(Vector3fPtr vector3f);

            double dot(Vector3fPtr vector3f);

            void cross(Vector3fPtr vector3f);

            void transform(Matrix3fPtr matrix3f);

            void transform(QuaternionPtr quaternion);

            void lerp(Vector3fPtr vector3f, double f);

            QuaternionPtr rotation(double f);

            QuaternionPtr rotationDegrees(double f);

            Vector3fPtr copy();

            std::string toString() const;

        private:
            double m_x{};
            double m_y{};
            double m_z{};
        };
    }
}
#endif //MINECRAFTCERVER_VECTOR3F_H
