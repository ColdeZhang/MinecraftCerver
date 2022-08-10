//
// Created by 张宇衡 on 2022/8/7.
//

#include "Lifecycle.h"

namespace cerver {
    namespace serialization {
        Lifecycle::LifecyclePtr Lifecycle::experimental()  {
            return EXPERIMENTAL;
        }

        Lifecycle::LifecyclePtr Lifecycle::stable() {
            return STABLE;
        }

    } // cerver
} // serialization