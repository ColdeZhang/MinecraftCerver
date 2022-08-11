//
// Created by deer on 2022/8/11.
//

#ifndef MINECRAFTCERVER_RUNNINGGAME_H
#define MINECRAFTCERVER_RUNNINGGAME_H

#include "bridge/game/GameSession.h"
#include "bridge/game/Language.h"
#include "bridge/game/PerformanceMetrics.h"
#include "bridge/game/GameVersion.h"
#include "bridge/launcher/SessionEventListener.h"

namespace cerver {
    namespace bridge {
        namespace game {
            class RunningGame {
                virtual GameVersion getVersion();

                virtual Language getSelectedLanguage();

                virtual GameSession getCurrentSession();

                virtual PerformanceMetrics getPerformanceMetrics();

                virtual void setSessionEventListener(launcher::SessionEventListener var1);
            };
        } // game
    } // bridge
}

#endif //MINECRAFTCERVER_RUNNINGGAME_H
