//
// Created by 张宇衡 on 2022/8/9.
//

#include "ChatFormatting.h"

#include <utility>
#include <algorithm>

namespace cerver {
    namespace minecraft {
        ChatFormats::ChatFormats(std::string string2, char c, bool bl) {
            init(std::move(string2), c, bl, -1, -1);
        }

        ChatFormats::ChatFormats(std::string string2, char c, int n2, long n3) {
            init(std::move(string2), c, false, n2, n3);
        }

        ChatFormats::ChatFormats(std::string string2, char c, bool bl, int n2, long n3) {
            init(std::move(string2), c, bl, n2, n3);
        }

        void ChatFormats::init(std::string string2, char c, bool bl, int n2, long n3) {
            this->m_name = std::move(string2);
            this->m_code = c;
            this->m_isFormat = bl;
            this->m_id = n2;
            this->m_color = n3;
            this->m_toString = &"\u00a7"[c];
            this->store_FORMATTING_BY_NAME();
        }

        char ChatFormats::getChar() const {
            return this->m_code;
        }

        int ChatFormats::getId() const {
            return this->m_id;
        }

        bool ChatFormats::isFormat() const {
            return this->m_isFormat;
        }

        bool ChatFormats::isColor() {
            return !this->isFormat() && static_cast<ChatFormatsPtr>(this) != ChatFormatting::RESET;
        }

        long ChatFormats::getColor() const {
            return this->m_color;
        }

        std::string ChatFormats::getName() {
            std::string str = this->m_name;
            std::transform(str.begin(), str.end(), str.begin(), ::tolower);
            return str;
        }

        std::string ChatFormats::toString() {
            return this->m_toString;
        }

        ChatFormats::ChatFormatsPtr ChatFormats::getByName(const std::string& string) {
            if (string.empty()) return nullptr;
            return FORMATTING_BY_NAME[cerver::minecraft::ChatFormats::cleanName(string)];
        }

        std::string ChatFormats::cleanName(std::string string) {
            std::transform(string.begin(), string.end(), string.begin(), ::tolower);
            // 将字符串中的字母删除
            string.erase(std::remove_if(string.begin(), string.end(), ::isalpha), string.end());
            return string;
        }

        ChatFormats::ChatFormatsPtr ChatFormats::getByID(int n) {
            if (n < 0) return nullptr;
            for (auto &format : FORMATTING_BY_NAME) {
                if (format.second->getId() == n) return format.second;
            }
            return nullptr;
        }

        ChatFormats::ChatFormatsPtr ChatFormats::getByCode(char c) {
            std::string string = std::string(1, c);
            std::transform(string.begin(), string.end(), string.begin(), ::tolower);
            if (string[0] == '\0') return nullptr;
            for (auto &format : FORMATTING_BY_NAME) {
                if (format.second->getChar() == string[0]) return format.second;
            }
            return nullptr;
        }

        std::string ChatFormats::stripFormatting(std::string string) {
            if (string.empty()) return string;
            else return std::regex_replace(string, STRIP_FORMATTING_PATTERN, "");

        }

        std::string ChatFormats::getSerializedName() {
            return this->getName();
        }

        std::vector<std::string> ChatFormats::getNames(bool bl, bool bl2) {
            std::vector<std::string> arrayList;
            for (auto &format : FORMATTING_BY_NAME) {
                if (format.second->isColor() && !bl || format.second->isFormat() && !bl2) {
                    arrayList.push_back(format.second->getName());
                }
            }
            return arrayList;
        }

        void ChatFormats::store_FORMATTING_BY_NAME() {
            this->FORMATTING_BY_NAME["BLACK"] = ChatFormatting::BLACK;
            this->FORMATTING_BY_NAME["DARK_BLUE"] = ChatFormatting::DARK_BLUE;
            this->FORMATTING_BY_NAME["DARK_GREEN"] = ChatFormatting::DARK_GREEN;
            this->FORMATTING_BY_NAME["DARK_AQUA"] = ChatFormatting::DARK_AQUA;
            this->FORMATTING_BY_NAME["DARK_RED"] = ChatFormatting::DARK_RED;
            this->FORMATTING_BY_NAME["DARK_PURPLE"] = ChatFormatting::DARK_PURPLE;
            this->FORMATTING_BY_NAME["GOLD"] = ChatFormatting::GOLD;
            this->FORMATTING_BY_NAME["GRAY"] = ChatFormatting::GRAY;
            this->FORMATTING_BY_NAME["DARK_GRAY"] = ChatFormatting::DARK_GRAY;
            this->FORMATTING_BY_NAME["BLUE"] = ChatFormatting::BLUE;
            this->FORMATTING_BY_NAME["GREEN"] = ChatFormatting::GREEN;
            this->FORMATTING_BY_NAME["AQUA"] = ChatFormatting::AQUA;
            this->FORMATTING_BY_NAME["RED"] = ChatFormatting::RED;
            this->FORMATTING_BY_NAME["LIGHT_PURPLE"] = ChatFormatting::LIGHT_PURPLE;
            this->FORMATTING_BY_NAME["YELLOW"] = ChatFormatting::YELLOW;
            this->FORMATTING_BY_NAME["WHITE"] = ChatFormatting::WHITE;
            this->FORMATTING_BY_NAME["OBFUSCATED"] = ChatFormatting::OBFUSCATED;
            this->FORMATTING_BY_NAME["BOLD"] = ChatFormatting::BOLD;
            this->FORMATTING_BY_NAME["STRIKETHROUGH"] = ChatFormatting::STRIKETHROUGH;
            this->FORMATTING_BY_NAME["UNDERLINE"] = ChatFormatting::UNDERLINE;
            this->FORMATTING_BY_NAME["ITALIC"] = ChatFormatting::ITALIC;
            this->FORMATTING_BY_NAME["RESET"] = ChatFormatting::RESET;
        }


    } // cerver
} // minecraft