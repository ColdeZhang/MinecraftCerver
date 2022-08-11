//
// Created by deer on 2022/8/7.
//

#include "DataResult.h"

namespace cerver {
    namespace serialization {

        template<class R>
        DataResult<R> DataResult<R>::unbox(App<struct Mu, R> app) {
            return (DataResult)app;
        }




    } // cerver
} // serialization