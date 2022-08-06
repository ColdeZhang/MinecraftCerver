//
// Created by 张宇衡 on 2022/8/3.
//

#ifndef MINECRAFTCERVER_VECTOR3D_H
#define MINECRAFTCERVER_VECTOR3D_H

#include <cstdio>
#include <memory>

/*
 * 全部实现
 */
namespace cerver {
    namespace math {

        class Vector3d {

            typedef std::shared_ptr<Vector3d> Vector3dPtr;

        public:
            double x;
            double y;
            double z;

            Vector3d(double d, double d2, double d3);

            void set(const Vector3dPtr& vector3d);

            void set(double d, double d2, double d3);

            void scale(double d);

            void add(const Vector3dPtr& vector3d);

        };
    }
}
#endif //MINECRAFTCERVER_VECTOR3D_H
