//
// Created by deer on 2022/8/6.
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
                    char CUSTOM_COLOR_PREFIX = '#';
                    std::map<ChatFormattingPtr, TextColorPtr> LEGACY_FORMAT_TO_COLOR;
                    std::map<std::string, TextColorPtr> NAMED_COLORS;
                    int value;
                    std::string name;

                public:
                    TextColor() = default;

                    TextColor(int n, std::string string);

                    explicit TextColor(int n);

                    int getValue() const;

                    std::string serialize();

                    std::string formatValue() const;

                    size_t hashCode();

                    std::string toString();

                    TextColorPtr fromLegacyFormat(ChatFormattingPtr chatFormatting);

                    static TextColorPtr fromRgb(int n);

                    TextColorPtr parseColor(std::string string) const;
                };

            } // cerver
        } // minecraft
    } // network
} // chat

#endif //MINECRAFTCERVER_TEXTCOLOR_H
