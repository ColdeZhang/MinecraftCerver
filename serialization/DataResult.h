//
// Created by deer on 2022/8/7.
//

#ifndef MINECRAFTCERVER_DATARESULT_H
#define MINECRAFTCERVER_DATARESULT_H

#include "datafixers/kinds/App.h"

namespace cerver {
    namespace serialization {

        using namespace cerver::datafixers::kinds;
        template<class R>
        class DataResult : public App<class MU, R>{
        public:

            DataResult<R> unbox(App<class Mu, R> app);

            DataResult<R> success(R r);
        };



    } // cerver
} // serialization

#endif //MINECRAFTCERVER_DATARESULT_H
