//
// Created by 张宇衡 on 2022/8/3.
//

#ifndef MINECRAFTCERVER_VECTOR3D_H
#define MINECRAFTCERVER_VECTOR3D_H

/*
 * 全部实现
 */
class Vector3d {
public:
    double x;
    double y;
    double z;

    Vector3d(double d, double d2, double d3) {
        this->x = d;
        this->y = d2;
        this->z = d3;
    }

    void set(Vector3d vector3d){
        this->x = vector3d.x;
        this->y = vector3d.y;
        this->z = vector3d.z;
    }

    void set(double d, double d2, double d3){
        this->x = d;
        this->y = d2;
        this->z = d3;
    }

    void scale(double d) {
        this->x *= d;
        this->y *= d;
        this->z *= d;
    }

    void add(Vector3d vector3d) {
        this->x += vector3d.x;
        this->y += vector3d.y;
        this->z += vector3d.z;
    }

};

#endif //MINECRAFTCERVER_VECTOR3D_H
