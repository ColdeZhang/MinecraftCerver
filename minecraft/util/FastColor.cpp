//
// Created by deer on 2022/8/15.
//

#include "FastColor.h"

int cerver::minecraft::util::FastColor::ARGB32::alpha(int n)
{
    return n >> 24;
}

int cerver::minecraft::util::FastColor::ARGB32::red(int n)
{
    return n >> 16 & 0xFF;
}

int cerver::minecraft::util::FastColor::ARGB32::green(int n)
{
    return n >> 8 & 0xFF;
}

int cerver::minecraft::util::FastColor::ARGB32::blue(int n)
{
    return n & 0xFF;
}

int cerver::minecraft::util::FastColor::ARGB32::color(int n, int n2, int n3, int n4)
{
    return n << 24 | n2 << 16 | n3 << 8 | n4;
}

int cerver::minecraft::util::FastColor::ARGB32::multiply(int n, int n2)
{
    return color(alpha(n) * alpha(n2) / 255, red(n) * red(n2) / 255, green(n) * green(n2) / 255, blue(n) * blue(n2) / 255);
}