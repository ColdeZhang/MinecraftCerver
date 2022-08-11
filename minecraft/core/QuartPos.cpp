//
// Created by deer on 2022/8/11.
//

#include "QuartPos.h"

namespace cerver {
    namespace minecraft {
        namespace core {
            int QuartPos::fromBlock(int n) {
                return n >> 2;
            }

            int QuartPos::quartLocal(int n) {
                return n & 3;
            }

            int QuartPos::toBlock(int n) {
                return n << 2;
            }

            int QuartPos::fromSection(int n) {
                return n << 2;
            }

            int QuartPos::toSection(int n) {
                return n >> 2;
            }


        } // minecraft
    } // core
}