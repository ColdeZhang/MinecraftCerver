//
// Created by deer on 2022/8/11.
//

#ifndef MINECRAFTCERVER_HASH_H
#define MINECRAFTCERVER_HASH_H

#include <utility>

namespace cerver {
    namespace util {

        template<class T>
        size_t Hash(T *t) {
            std::hash<T *> hashThis;
            return hashThis(t);
        }

    } // util
}

#endif //MINECRAFTCERVER_HASH_H
