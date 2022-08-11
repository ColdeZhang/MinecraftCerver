//
// Created by deer on 2022/8/7.
//

#ifndef MINECRAFTCERVER_LIFECYCLE_H
#define MINECRAFTCERVER_LIFECYCLE_H

#include <memory>

namespace cerver {
    namespace serialization {

        class Lifecycle {

            typedef std::shared_ptr<Lifecycle> LifecyclePtr;

        private:

            LifecyclePtr STABLE = std::make_shared<Lifecycle>();

            LifecyclePtr EXPERIMENTAL = std::make_shared<Lifecycle>();

        public:
            Lifecycle() = default;

            LifecyclePtr experimental();

            LifecyclePtr stable();
        };

    } // cerver
} // serialization

#endif //MINECRAFTCERVER_LIFECYCLE_H
