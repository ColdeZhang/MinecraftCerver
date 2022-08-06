//
// Created by 张宇衡 on 2022/8/3.
//

#ifndef MINECRAFTCERVER_QUATERNION_H
#define MINECRAFTCERVER_QUATERNION_H

#include <cstdio>
#include <memory>
#include <cmath>
#include <string>

/*
 * equals() 未实现
 */
namespace cerver {
    namespace math {
        class Vector3f;
        class Quaternion {

            typedef std::shared_ptr<Vector3f> Vector3fPtr;
            typedef std::shared_ptr<Quaternion> QuaternionPtr;

        public:
            Quaternion() = default;

            Quaternion(double d, double d2, double d3, double d4);

            Quaternion(Vector3fPtr vector3f, double f, bool bl);

            Quaternion(double f, double f2, double f3, bool bl);

            Quaternion(const QuaternionPtr &quaternion);

            QuaternionPtr fromYXZ(double f, double f2, double f3);

            QuaternionPtr fromXYZDegrees(Vector3fPtr vector3f);

            QuaternionPtr fromXYZ(Vector3fPtr vector3f);

            QuaternionPtr fromXYZ(double f, double f2, double f3);

            Vector3fPtr toXYZ();

            Vector3fPtr toXYZDegrees();

            Vector3fPtr toYXZ();

            Vector3fPtr toYXZDegrees();

            int hashCode();

            std::string toString();

            void mul(QuaternionPtr quaternion);

            void mul(double f);

            void conj();

            void normalize();

            void set(double f, double f2, double f3, double f4);

            void slerp(QuaternionPtr quaternion, float f);

            QuaternionPtr copy();

            double i() const { return this->m_i; }

            double j() const { return this->m_j; }

            double k() const { return this->m_k; }

            double r() const { return this->m_r; }

            QuaternionPtr ONE = std::make_shared<Quaternion>(0.0, 0.0, 0.0, 1.0);

        private:
            double m_i;
            double m_j;
            double m_k;
            double m_r;

        private:
            double cos(double d) {return std::cos(d);}

            double sin(double d) {return std::sin(d);}

        };
    }
}
#endif //MINECRAFTCERVER_QUATERNION_H
