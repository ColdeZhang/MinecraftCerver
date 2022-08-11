//
// Created by deer on 2022/8/11.
//

#ifndef MINECRAFTCERVER_SESSIONEVENTLISTENER_H
#define MINECRAFTCERVER_SESSIONEVENTLISTENER_H

#include "bridge/game/GameSession.h"
#include <memory>

namespace cerver {
    namespace bridge {
        namespace launcher {
            class SessionEventListener {
                std::shared_ptr<SessionEventListener> NONE = std::make_shared<SessionEventListener>();

                virtual void onStartGameSession(game::GameSession gameSession);

                virtual void onLeaveGameSession(game::GameSession gameSession);
            };
        } // game
    } // bridge
}

#endif //MINECRAFTCERVER_SESSIONEVENTLISTENER_H
