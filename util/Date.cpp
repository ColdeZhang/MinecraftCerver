//
// Created by deer on 2022/8/11.
//

#include "Date.h"
#include "sys/timeb.h"
#include "util/Hash.h"

namespace cerver {
    namespace util {
        Date::DatePtr Date::clone() {
            return std::make_shared<Date>(*this);
        }

        Date::Date() {
            struct timeb tb{};
            ftime(&tb);
            this->m_time = tb.time * 1000 + tb.millitm;
        }

        Date::Date(Date::ulong milliseconds) {
            this->m_time = milliseconds;
        }

        bool Date::after(const Date::DatePtr &date) const {
            return this->m_time > date->m_time;
        }

        bool Date::before(const Date::DatePtr &date) const {
            return this->m_time < date->m_time;
        }

        int Date::compareTo(Date::DatePtr date) const {
            if (this->m_time > date->m_time) {
                return 1;
            } else if (this->m_time < date->m_time) {
                return -1;
            } else {
                return 0;
            }
        }

        bool Date::equals(Date::DatePtr date) {
            return this->compareTo(date);
        }

        size_t Date::hashCode() {
            return Hash(this);
        }

        Date::ulong Date::getTime() const {
            return this->m_time;
        }

        void Date::setTime(Date::ulong time) {
            this->m_time = time;
        }

        std::string Date::toString() const {
            // 转换为 dow mon dd hh:mm:ss zzz yyyy
            // 比如：Tue Sep 30 00:00:00 CST 2018
            char buf[64];
            struct tm tm{};
            time_t t = this->m_time / 1000;
            localtime_r(&t, &tm);
            strftime(buf, sizeof(buf), "%a %b %d %H:%M:%S %Z %Y", &tm);
            return buf;
        }
    } // util
}