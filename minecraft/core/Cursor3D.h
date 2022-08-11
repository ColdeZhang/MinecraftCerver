//
// Created by deer on 2022/8/11.
//

#ifndef MINECRAFTCERVER_CURSOR3D_H
#define MINECRAFTCERVER_CURSOR3D_H

namespace minecraft {
    namespace core {

        class Cursor3D {
        public:
            int TYPE_INSIDE = 0;
            int TYPE_FACE = 1;
            int TYPE_EDGE = 2;
            int TYPE_CORNER = 3;
        private:
            int originX;
            int originY;
            int originZ;
            int width;
            int height;
            int depth;
            int end;
            int index{};
            int x{};
            int y{};
            int z{};

        public:
            Cursor3D(int n, int n2, int n3, int n4, int n5, int n6);

            bool advance();

            int nextX() const;

            int nextY() const;

            int nextZ() const;

            int getNextType() const;
            
        };

    } // minecraft
} // core

#endif //MINECRAFTCERVER_CURSOR3D_H
