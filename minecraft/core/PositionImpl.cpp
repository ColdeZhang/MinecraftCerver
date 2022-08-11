//
// Created by deer on 2022/8/11.
//

#include "PositionImpl.h"

namespace minecraft {
    namespace core {
        PositionImpl::PositionImpl(double d, double d2, double d3) {
            this->m_x = d;
            this->m_y = d2;
            this->m_z = d3;
        }

        double PositionImpl::x() {
            return this->m_x;
        }

        double PositionImpl::y() {
            return this->m_y;
        }

        double PositionImpl::z() {
            return this->m_z;
        }
    } // minecraft
} // core