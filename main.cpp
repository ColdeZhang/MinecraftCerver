#include <iostream>

#include "math/Vector3f.h"

#include "minecraft/network/chat/TextColor.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    typedef std::shared_ptr<cerver::minecraft::network::chat::TextColor> TextColorPtr;

    TextColorPtr t1 = std::make_shared<cerver::minecraft::network::chat::TextColor>()->parseColor("#ff5555");

    std::cout<<t1->hashCode()<<std::endl;

    return 0;
}
