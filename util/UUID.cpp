//
// Created by deer on 2022/8/11.
//

#include "UUID.h"

namespace cerver {
    namespace util {

        std::string UUID::toString() {
            char buf[37];
            uuid_unparse(m_uuid, buf);
            return {buf};
        }
    } // util
}