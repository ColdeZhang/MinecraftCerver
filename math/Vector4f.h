//
// Created by 张宇衡 on 2022/8/3.
//

#ifndef MINECRAFTCERVER_VECTOR4F_H
#define MINECRAFTCERVER_VECTOR4F_H

#include <string>

/*
 * transform(Matrix4f matrix4f) 未实现
 */
namespace cerver {
    namespace math {
        class Vector3f;
        class Quaternion;
        class Vector4f {
        public:
            Vector4f() = default;

            Vector4f(double f, double f2, double f3, double f4);

            Vector4f(const Vector3f& vector3f);

            int hashCode() const;

            double x() const { return this->m_x; }

            double y() const { return this->m_y; }

            double z() const { return this->m_z; }

            double w() const { return this->m_w; }

            void mul(double f);

            void mul(const Vector3f& vector3f);

            void set(double f, double f2, double f3, double f4);

            void add(double f, double f2, double f3, double f4);

            double dot(Vector4f vector4f) const;

            void transform(Quaternion quaternion);

            void perspectiveDivide();

            void lerp(Vector4f vector4f, double f) {
                double f2 = 1.0 - f;
                this->m_x = f2 * this->m_x + f * vector4f.x();
                this->m_y = f2 * this->m_y + f * vector4f.y();
                this->m_z = f2 * this->m_z + f * vector4f.z();
                this->m_w = f2 * this->m_w + f * vector4f.w();
            }

            std::string toString() {
                return std::string("[") + std::to_string(this->m_x) + ", " + std::to_string(this->m_y) + ", " +
                       std::to_string(this->m_z) + ", " + std::to_string(this->m_w) + "]";
            }


        private:
            double m_x;
            double m_y;
            double m_z;
            double m_w;
        };
    }
}

#endif //MINECRAFTCERVER_VECTOR4F_H
