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
        public:
            Quaternion() = default;

            Quaternion(double d, double d2, double d3, double d4);

            Quaternion(std::shared_ptr<Vector3f> vector3f, double f, bool bl);

            Quaternion(double f, double f2, double f3, bool bl);

            Quaternion(const std::shared_ptr<Quaternion> &quaternion);

            std::shared_ptr<Quaternion> fromYXZ(double f, double f2, double f3);

            std::shared_ptr<Quaternion> fromXYZDegrees(Vector3f vector3f);

            std::shared_ptr<Quaternion> fromXYZ(Vector3f vector3f);

            std::shared_ptr<Quaternion> fromXYZ(double f, double f2, double f3);

            Vector3f toXYZ();

            Vector3f toXYZDegrees();

            Vector3f toYXZ();

            Vector3f toYXZDegrees();

            bool equals() {

            }

            int hashCode();

            std::string toString();

            void mul(Quaternion quaternion);

            void mul(double f);

            void conj();

            void normalize();

            void set(double f, double f2, double f3, double f4);

            std::shared_ptr<Quaternion> copy();

            double i() const { return this->m_i; }

            double j() const { return this->m_j; }

            double k() const { return this->m_k; }

            double r() const { return this->m_r; }


        private:
            double m_i;
            double m_j;
            double m_k;
            double m_r;

        private:
            double cos(double d) {return std::cos(d);}

            double sin(double d) {return std::sin(d);}

        };

        std::shared_ptr<Quaternion> ONE = std::make_shared<Quaternion>(0.0, 0.0, 0.0, 1.0);

    }
}
#endif //MINECRAFTCERVER_QUATERNION_H
