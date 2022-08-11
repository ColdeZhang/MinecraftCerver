//
// Created by deer on 2022/8/6.
//

#ifndef MINECRAFTCERVER_MESSAGE_H
#define MINECRAFTCERVER_MESSAGE_H

#include <string>

namespace cerver {
    namespace brigadier {

        /*!
         * @typedef 接口类
         */
        class Message {
        public:
            virtual std::string getString(){return "null exception";};
        };

    } // cerver
} // brigadier

#endif //MINECRAFTCERVER_MESSAGE_H
