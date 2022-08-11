//
// Created by deer on 2022/8/11.
//

#ifndef MINECRAFTCERVER_POSITIONIMPL_H
#define MINECRAFTCERVER_POSITIONIMPL_H

#include "minecraft/core/Position.h"

namespace minecraft {
    namespace core {

        class PositionImpl : public Position {
        protected:
            double m_x;
            double m_y;
            double m_z;

        public:
            PositionImpl(double d, double d2, double d3);

            double x() override;

            double y() override;

            double z() override;
        };


    } // minecraft
} // core

#endif //MINECRAFTCERVER_POSITIONIMPL_H
