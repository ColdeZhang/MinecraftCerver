//
// Created by deer on 2022/8/12.
//

#ifndef MINECRAFTCERVER_BRIDGE_H
#define MINECRAFTCERVER_BRIDGE_H


#include "bridge/launcher/Launcher.h"
#include "bridge/launcher/LauncherProvider.h"

namespace cerver {
    namespace bridge {

        class Bridge{

            typedef std::shared_ptr<launcher::Launcher> LauncherPtr;

        private:
            bool INITIALIZED{};
            LauncherPtr LAUNCHER;

        public:
            Bridge() = default;

            LauncherPtr getLauncher();

            //LauncherPtr createLauncher();
        };


    } // cerver
} // bridge




#endif //MINECRAFTCERVER_BRIDGE_H
