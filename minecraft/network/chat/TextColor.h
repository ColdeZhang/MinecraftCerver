//
// Created by 张宇衡 on 2022/8/6.
//

#ifndef MINECRAFTCERVER_TEXTCOLOR_H
#define MINECRAFTCERVER_TEXTCOLOR_H

#include <string>
#include <memory>
#include <map>
#include "minecraft/ChatFormatting.h"

namespace cerver {
    namespace minecraft {
        namespace network {
            namespace chat {

                class TextColor {

                    typedef std::shared_ptr<ChatFormats> ChatFormattingPtr;
                    typedef std::shared_ptr<TextColor> TextColorPtr;

                private:
                    std::string CUSTOM_COLOR_PREFIX = "#";
                    std::map<ChatFormattingPtr, TextColorPtr> LEGACY_FORMAT_TO_COLOR;
                    std::map<std::string, TextColorPtr> NAMED_COLORS;
                    int value;
                    std::string name;

                public:
                    TextColor(int n, std::string string);

                    TextColor(int n);

                    int getValue();

                    std::string serialize();

                    std::string formatValue();

                    int hashCode();

                    std::string toString();

                    TextColorPtr fromLegacyFormat(ChatFormattingPtr chatFormatting);

                    TextColorPtr fromRgb(int n);

                    TextColorPtr parseColor(std::string string);
                };

            } // cerver
        } // minecraft
    } // network
} // chat

#endif //MINECRAFTCERVER_TEXTCOLOR_H
