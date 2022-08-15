//
// Created by deer on 2022/8/15.
//

#ifndef MINECRAFTCERVER_UTIL_H
#define MINECRAFTCERVER_UTIL_H

namespace cerver
{
    namespace minecraft
    {
        namespace util
        {
            class FastColor
            {
            private:
                class ARGB32
                {
                public:
                    int alpha(int n);

                    int red(int n);

                    int green(int n);

                    int blue(int n);

                    int color(int n, int n2, int n3, int n4);

                    int multiply(int n, int n2);
                };

            public:
                ARGB32 argb32_impl = ARGB32();
            };
        } // namespace util
    }     // namespace minecraft
} // namespace cerver

#endif //MINECRAFTCERVER_UTIL_H
