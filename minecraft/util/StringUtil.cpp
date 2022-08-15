//
// Created by deer on 2022/8/15.
//

#include "StringUtil.h"

namespace cerver
{
    namespace minecraft
    {
        namespace util
        {
            std::string StringUtil::formatTickDuration(int n)
            {
                int n2 = n / 20;
                int n3 = n2 / 60;
                if ((n2 %= 60) < 10)
                {
                    return n3 + ":0" + n2;
                }
                return n3 + ":" + n2;
            }

            std::string StringUtil::stripColor(std::string string)
            {
                return std::regex_replace(string, this->STRIP_COLOR_PATTERN, "");
            }

            bool StringUtil::isNullOrEmpty(std::string string)
            {
                return string.empty();
            }

            std::string StringUtil::truncateStringIfNecessary(std::string string, int n, bool bl)
            {
                if (string.length() <= n)
                {
                    return string;
                }
                if (bl && n > 3)
                {
                    return string.substr(0, n - 3) + "...";
                }
                return string.substr(0, n);
            }

            int StringUtil::lineCount(std::string string)
            {
                if (string.empty())
                {
                    return 0;
                }
                return std::regex_replace(string, this->LINE_PATTERN, "").length() + 1;
            }

            bool StringUtil::endsWithNewLine(std::string string)
            {
                return std::regex_search(string, this->LINE_END_PATTERN);
            }

            std::string StringUtil::trimChatMessage(std::string string)
            {
                return this->truncateStringIfNecessary(string, 256, false);
            }
        } // cerver
    }     // minecraft
} // util