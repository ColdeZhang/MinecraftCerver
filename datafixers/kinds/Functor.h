//
// Created by deer on 2022/8/6.
//

#ifndef MINECRAFTCERVER_FUNCTOR_H
#define MINECRAFTCERVER_FUNCTOR_H

#include "K1.h"

namespace cerver {
    namespace datafixers {
        namespace kinds {

            class F : public K1{};

            template<class F, class Mu>
            class Functor {
                Functor<F, Mu> unbox() {}
            };

        }
    }
}

#endif //MINECRAFTCERVER_FUNCTOR_H
