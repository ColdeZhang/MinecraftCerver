//
// Created by deer on 2022/8/11.
//

#ifndef MINECRAFTCERVER_DATE_H
#define MINECRAFTCERVER_DATE_H

#include <memory>
#include <string>
namespace cerver {
    namespace util {

        class Date {

            typedef std::shared_ptr<Date> DatePtr;
            typedef unsigned long long ulong;

        public:
            Date();

            Date(ulong milliseconds);

            bool after(const DatePtr &date) const;

            bool before(const DatePtr &date) const;

            DatePtr clone();

            int compareTo(DatePtr date) const;

            bool equals(DatePtr date);

            ulong getTime() const;

            size_t hashCode();

            void setTime(ulong time);

            std::string toString() const;

        private:
            ulong m_time;
            std::string m_format;
        };

    } // util
}

#endif //MINECRAFTCERVER_DATE_H
