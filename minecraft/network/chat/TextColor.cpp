//
// Created by deer on 2022/8/6.
//

#include "TextColor.h"

#include <utility>
#include <sstream>

namespace cerver {
    namespace minecraft {
        namespace network {
            namespace chat {
                TextColor::TextColor(int n, std::string string) {
                    this->value = n;
                    this->name = std::move(string);
                }

                TextColor::TextColor(int n) {
                    this->value = n;
                    this->name = "";
                }

                int TextColor::getValue() const {
                    return this->value;
                }

                std::string TextColor::serialize() {
                    if (this->name != "") return this->name;
                    return this->formatValue();
                }

                std::string TextColor::formatValue() const {
                    std::stringstream io;
                    std::string out;
                    io<<std::hex<<this->value;
                    io>>out;
                    if (out.size() < 6){
                        std::string s_0(6 - out.size(), '0');
                        out = s_0 + out;
                    }
                    return "#" + out;
                }

                int TextColor::hashCode() {
                    std::hash <TextColor *> hashThis;
                    return hashThis(this);
                }

                std::string TextColor::toString() {
                    return !this->name.empty() ? this->name : this->formatValue();
                }

                TextColor::TextColorPtr TextColor::fromLegacyFormat(TextColor::ChatFormattingPtr chatFormatting) {
                    return LEGACY_FORMAT_TO_COLOR[chatFormatting];
                }

                TextColor::TextColorPtr TextColor::fromRgb(int n) {
                    return std::make_shared<TextColor>(n);
                }

                TextColor::TextColorPtr TextColor::parseColor(std::string string) const {
                    // 取string的第一个字符
                    char c = string[0];
                    if (string[0] == CUSTOM_COLOR_PREFIX){
                        try{
                            // 去掉#
                            string = string.substr(1);
                            // 转换为10进制整数
                            int n = std::stoi(string, nullptr, 16);
                            return std::make_shared<TextColor>()->fromRgb(n);
                        }
                        catch (std::string &e){
                            return nullptr;
                        }
                    }
                    return nullptr;
                }


            } // cerver
        } // minecraft
    } // network
} // chat