//
// Created by 张宇衡 on 2022/8/4.
//

#include "Mth.h"

double cerver::minecraft::util::Mth::fastInvSqrt(double f) {
    double f2 = 0.5 * f;
    int i = (int)f;
    i = 1597463007 - (i >> 1);
    f = (int)i;
    f = f * (1.5 - f2 * f * f);
    return f;
}