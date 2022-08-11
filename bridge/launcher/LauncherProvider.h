//
// Created by deer on 2022/8/11.
//

#ifndef MINECRAFTCERVER_LAUNCHERPROVIDER_H
#define MINECRAFTCERVER_LAUNCHERPROVIDER_H

#include "bridge/launcher/Launcher.h"

namespace cerver{
    namespace bridge{
        namespace launcher{
            class LauncherProvider{
            public:
                virtual Launcher createLauncher();;
            };
        }
    }
}

#endif //MINECRAFTCERVER_LAUNCHERPROVIDER_H
