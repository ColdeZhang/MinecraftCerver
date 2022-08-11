//
// Created by deer on 2022/8/11.
//

#ifndef MINECRAFTCERVER_UUID_H
#define MINECRAFTCERVER_UUID_H

#include <random>
#include <uuid/uuid.h>

namespace cerver {
    namespace util {

        class UUID {
        public:
            UUID() = default;

            std::string toString();

        private:
            uuid_t m_uuid;
        };


    } // util
}

#endif //MINECRAFTCERVER_UUID_H
