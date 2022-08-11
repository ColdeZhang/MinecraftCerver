//
// Created by deer on 2022/8/6.
//

#ifndef MINECRAFTCERVER_KIND1_H
#define MINECRAFTCERVER_KIND1_H

#include "K1.h"
#include "App.h"

namespace cerver {
    namespace datafixers {
        namespace kinds {

            template<class F, class Mu>
            class Kind1 : public App<Mu, F> {
            public:
                template<class Proof>
                Kind1<F, Proof> unbox(App<Proof, F> app){
                    return app;
                }


            };

        }
    }
}

#endif //MINECRAFTCERVER_KIND1_H
