//
// Created by 张宇衡 on 2022/8/3.
//

#ifndef MINECRAFTCERVER_VECTOR4F_H
#define MINECRAFTCERVER_VECTOR4F_H

#include <string>

/*
 *
 */
namespace cerver {
    namespace math {
        class Vector3f;
        class Quaternion;
        class Matrix4f;
        class Vector4f {

            typedef std::shared_ptr<Vector3f> Vector3fPtr;
            typedef std::shared_ptr<Quaternion> QuaternionPtr;
            typedef std::shared_ptr<Matrix4f> Matrix4fPtr;
            typedef std::shared_ptr<Vector4f> Vector4fPtr;

        public:
            Vector4f() = default;

            Vector4f(double f, double f2, double f3, double f4);

            Vector4f(Vector3fPtr vector3f);

            int hashCode() const;

            double x() const { return this->m_x; }

            double y() const { return this->m_y; }

            double z() const { return this->m_z; }

            double w() const { return this->m_w; }

            void mul(double f);

            void mul(Vector3fPtr vector3f);

            void set(double f, double f2, double f3, double f4);

            void add(double f, double f2, double f3, double f4);

            double dot(Vector4fPtr vector4f) const;

            void perspectiveDivide();

            void lerp(Vector4fPtr vector4f, double f);

            std::string toString() const;

            bool normalize();

            void transform(Matrix4fPtr matrix4f);

            void transform(QuaternionPtr quaternion);

        private:
            double m_x;
            double m_y;
            double m_z;
            double m_w;
        };
    }
}

#endif //MINECRAFTCERVER_VECTOR4F_H
