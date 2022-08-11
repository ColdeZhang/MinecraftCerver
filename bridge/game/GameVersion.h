//
// Created by deer on 2022/8/11.
//

#ifndef MINECRAFTCERVER_GAMEVERSION_H
#define MINECRAFTCERVER_GAMEVERSION_H

#include <string>
#include "util/Date.h"

namespace cerver {
    namespace bridge {
        namespace game {

            class GameVersion {
            public:
                virtual std::string getId();

                virtual std::string getName();

                virtual std::string getReleaseTarget();

                virtual int getWorldVersion();

                virtual int getProtocolVersion();

                virtual int getPackVersion();

                virtual util::Date getBuildTime();

                virtual bool isStable();

            };

        } // bridge
    } // game
}

#endif //MINECRAFTCERVER_GAMEVERSION_H
