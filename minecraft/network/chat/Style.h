//
// Created by deer on 2022/8/6.
//

#ifndef MINECRAFTCERVER_STYLE_H
#define MINECRAFTCERVER_STYLE_H

#include <memory>

namespace cerver {
    namespace minecraft {
        namespace network {
            namespace chat {

                class Style {

                    typedef std::shared_ptr<Style> StylePtr;

                public:
                    //StylePtr EMPTY = ;

                    Style();


                };

            } // cerver
        } // minecraft
    } // network
} // chat

#endif //MINECRAFTCERVER_STYLE_H
