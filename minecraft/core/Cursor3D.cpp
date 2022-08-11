//
// Created by deer on 2022/8/11.
//

#include "Cursor3D.h"

namespace cerver {
    namespace minecraft {
        namespace core {
            Cursor3D::Cursor3D(int n, int n2, int n3, int n4, int n5, int n6) {
                this->originX = n;
                this->originY = n2;
                this->originZ = n3;
                this->width = n4 - n + 1;
                this->height = n5 - n2 + 1;
                this->depth = n6 - n3 + 1;
                this->end = this->width * this->height * this->depth;
            }

            bool Cursor3D::advance() {
                if (this->index == this->end) return false;
                this->x = this->index % this->width;
                int n = this->index / this->width;
                this->y = n % this->height;
                this->z = n / this->height;
                this->index++;
                return true;
            }

            int Cursor3D::nextX() const {
                return this->originX + this->x;
            }

            int Cursor3D::nextY() const {
                return this->originY + this->y;
            }

            int Cursor3D::nextZ() const {
                return this->originZ + this->z;
            }

            int Cursor3D::getNextType() const {
                int n = 0;
                if (this->x == 0 || this->x == this->width - 1) n++;
                if (this->y == 0 || this->y == this->height - 1) n++;
                if (this->z == 0 || this->z == this->depth - 1) n++;
                return n;
            }
        } // minecraft
    } // core
}