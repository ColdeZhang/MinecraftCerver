//
// Created by deer on 2022/8/15.
//

#ifndef MINECRAFTCERVER_STRINGUTIL_H
#define MINECRAFTCERVER_STRINGUTIL_H

#include <regex>
#include <string>

namespace cerver {
    namespace minecraft {
        namespace util {

            class StringUtil {
            private:
                std::regex STRIP_COLOR_PATTERN = std::regex("\\u00a7[0-9a-fA-FK-Ok-oR]");
                std::regex LINE_PATTERN = std::regex(R"(\r\n|\v)");
                std::regex LINE_END_PATTERN = std::regex(R"((?:\r\n|\v)$)");

            public:
                std::string formatTickDuration(int n);

                std::string stripColor(std::string string);

                bool isNullOrEmpty(std::string string);

                std::string truncateStringIfNecessary(std::string string, int n, bool bl);

                int lineCount(std::string string);

                bool endsWithNewLine(std::string string);

                std::string trimChatMessage(std::string string);
            };

        } // cerver
    } // minecraft
} // util

#endif //MINECRAFTCERVER_STRINGUTIL_H
