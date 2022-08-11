#include <iostream>

#include "util/Date.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    util::Date date;

    std::cout << date.toString() << std::endl;

    return 0;
}
