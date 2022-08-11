//
// Created by deer on 2022/8/11.
//

#ifndef MINECRAFTCERVER_LANGUAGE_H
#define MINECRAFTCERVER_LANGUAGE_H

#include <string>

namespace cerver {
    namespace bridge {
        namespace game {
            class Language {

                virtual std::string getCode();

                virtual std::string getName();

                virtual std::string getRegion();

            };
        } // game
    } // bridge
}

#endif //MINECRAFTCERVER_LANGUAGE_H
