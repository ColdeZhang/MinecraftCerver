//
// Created by deer on 2022/8/11.
//

#ifndef MINECRAFTCERVER_GAMESESSION_H
#define MINECRAFTCERVER_GAMESESSION_H

#include "util/UUID.h"
#include <string>

namespace cerver {
    namespace bridge {
        namespace game {
            class GameSession {

                virtual int getPlayerCount();

                virtual bool isRemoteServer();

                virtual std::string getDifficulty();

                virtual std::string getGameMode();

                virtual util::UUID getSessionId();

            };
        } // game
    } // bridge
}

#endif //MINECRAFTCERVER_GAMESESSION_H
