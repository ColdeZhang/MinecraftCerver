//
// Created by deer on 2022/8/11.
//

#ifndef MINECRAFTCERVER_POSITION_H
#define MINECRAFTCERVER_POSITION_H

namespace cerver {
    namespace minecraft {
        namespace core {

            class Position {
            public:
                virtual double x();

                virtual double y();

                virtual double z();
            };

        } // minecraft
    } // core
}

#endif //MINECRAFTCERVER_POSITION_H
