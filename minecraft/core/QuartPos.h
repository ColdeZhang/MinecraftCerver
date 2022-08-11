//
// Created by deer on 2022/8/11.
//

#ifndef MINECRAFTCERVER_QUARTPOS_H
#define MINECRAFTCERVER_QUARTPOS_H

namespace minecraft {
    namespace core {

        class QuartPos {
        public:
            int BITS = 2;
            int SIZE = 4;
            int MASK = 3;
            int SECTION_TO_QUARTS_BITS = 2;

        public:
            QuartPos() = default;

            static int fromBlock(int n) ;

            static int quartLocal(int n);

            static int toBlock(int n);

            static int fromSection(int n);

            static int toSection(int n);
        };

    } // minecraft
} // core

#endif //MINECRAFTCERVER_QUARTPOS_H
