//
// Created by deer on 2022/8/11.
//

#ifndef MINECRAFTCERVER_LAUNCHER_H
#define MINECRAFTCERVER_LAUNCHER_H

#include "bridge/game/RunningGame.h"

namespace cerver{
    namespace bridge{
        namespace launcher{
            class Launcher{
            public:
                virtual void registerGame(game::RunningGame var1);
            };
        }
    }
}

#endif //MINECRAFTCERVER_LAUNCHER_H
