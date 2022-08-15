//
// Created by deer on 2022/8/12.
//

#include "Bridge.h"

namespace cerver {
    namespace bridge {
        Bridge::LauncherPtr Bridge::getLauncher() {
            if (INITIALIZED) return LAUNCHER;
            //LAUNCHER = createLauncher();
            INITIALIZED = true;
            return LAUNCHER;
        }

    } // cerver
} // bridge