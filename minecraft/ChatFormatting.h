//
// Created by 张宇衡 on 2022/8/9.
//

#ifndef MINECRAFTCERVER_CHATFORMATTING_H
#define MINECRAFTCERVER_CHATFORMATTING_H

#include <string>
#include <memory>
#include <map>
#include <regex>
#include <cwchar>

namespace cerver {
    namespace minecraft {


        class ChatFormats{

            typedef std::shared_ptr<ChatFormats> ChatFormatsPtr;

        private:
            wchar_t PREFIX_CODE = L'\u00a7';
            std::map<std::string, ChatFormatsPtr> FORMATTING_BY_NAME;
            std::regex STRIP_FORMATTING_PATTERN = std::regex("\\u00a7[0-9a-fA-FK-Ok-oR]");
            std::string m_name;
            char m_code{};
            bool m_isFormat{};
            std::string m_toString;
            int m_id{};
            long m_color{};

            void init(std::string string2, char c, bool bl, int n2, long n3);

        public:

            ChatFormats(std::string string2, char c, bool bl);

            ChatFormats(std::string string2, char c, bool bl, int n2, long n3);

            ChatFormats(std::string string2, char c, int n2, long n3);

            char getChar() const;

            int getId() const;

            bool isFormat() const;

            bool isColor();

            long getColor() const;

            std::string getName();

            std::string toString();

            std::string stripFormatting(std::string string);

            ChatFormatsPtr getByName(const std::string& string);

            ChatFormatsPtr getByID(int n);

            ChatFormatsPtr getByCode(char c);

            static std::string cleanName(std::string string);

            std::string getSerializedName();

            std::vector<std::string> getNames(bool bl, bool bl2);

            void store_FORMATTING_BY_NAME();

        };

        namespace ChatFormatting {
            typedef std::shared_ptr<ChatFormats> ChatFormatsPtr;
            static ChatFormatsPtr BLACK = std::make_shared<ChatFormats>("BLACK", '0', 0, 0);
            static ChatFormatsPtr DARK_BLUE = std::make_shared<ChatFormats>("DARK_BLUE", '1', 1, 170);
            static ChatFormatsPtr DARK_GREEN = std::make_shared<ChatFormats>("DARK_GREEN", '2', 2, 43520);
            static ChatFormatsPtr DARK_AQUA = std::make_shared<ChatFormats>("DARK_AQUA", '3', 3, 43690);
            static ChatFormatsPtr DARK_RED = std::make_shared<ChatFormats>("DARK_RED", '4', 4, 11141120);
            static ChatFormatsPtr DARK_PURPLE = std::make_shared<ChatFormats>("DARK_PURPLE", '5', 5, 11141290);
            static ChatFormatsPtr GOLD = std::make_shared<ChatFormats>("GOLD", '6', 6, 16755200);
            static ChatFormatsPtr GRAY = std::make_shared<ChatFormats>("GRAY", '7', 7, 11184810);
            static ChatFormatsPtr DARK_GRAY = std::make_shared<ChatFormats>("DARK_GRAY", '8', 8, 5592405);
            static ChatFormatsPtr BLUE = std::make_shared<ChatFormats>("BLUE", '9', 9, 5592575);
            static ChatFormatsPtr GREEN = std::make_shared<ChatFormats>("GREEN", 'a', 10, 5635925);
            static ChatFormatsPtr AQUA = std::make_shared<ChatFormats>("AQUA", 'b', 11, 5636095);
            static ChatFormatsPtr RED = std::make_shared<ChatFormats>("RED", 'c', 12, 16733525);
            static ChatFormatsPtr LIGHT_PURPLE = std::make_shared<ChatFormats>("LIGHT_PURPLE", 'd', 13, 16733695);
            static ChatFormatsPtr YELLOW = std::make_shared<ChatFormats>("YELLOW", 'e', 14, 16777045);
            static ChatFormatsPtr WHITE = std::make_shared<ChatFormats>("WHITE", 'f', 15, 16777215);
            static ChatFormatsPtr OBFUSCATED = std::make_shared<ChatFormats>("OBFUSCATED", 'k', true);
            static ChatFormatsPtr BOLD = std::make_shared<ChatFormats>("BOLD", 'l', true);
            static ChatFormatsPtr STRIKETHROUGH = std::make_shared<ChatFormats>("STRIKETHROUGH", 'm', true);
            static ChatFormatsPtr UNDERLINE = std::make_shared<ChatFormats>("UNDERLINE", 'n', true);
            static ChatFormatsPtr ITALIC = std::make_shared<ChatFormats>("ITALIC", 'o', true);
            static ChatFormatsPtr RESET = std::make_shared<ChatFormats>("RESET", 'r', -1, -1);
        }



    } // cerver
} // minecraft

#endif //MINECRAFTCERVER_CHATFORMATTING_H
