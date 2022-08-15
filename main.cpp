#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

int main(int argc, char *argv[]) {

    std::unordered_set<std::string> optionSpecBuilder{
        "-help",
        "-initSettings",
        "-demo",
        "-forceUpgrade",
        "-eraseCache",
        "-safeMode",
    };

    std::unordered_set<std::string> optionSet;
    for (int i = 1; i < argc; i++) {
        optionSet.insert(argv[i]);
    }

    try{
        // 如果有 -help 则打印帮助信息
        if (optionSet.find("-help") != optionSet.end()) {
            std::cout << "Usage: cerver [options]" << std::endl;
            std::cout << "Options:" << std::endl;
            std::cout << "  -help               Print this help message" << std::endl;
            std::cout << "  -initSettings       Initialize the settings" << std::endl;
            std::cout << "  -demo               Start the demo" << std::endl;
            std::cout << "  -forceUpgrade       Force the upgrade" << std::endl;
            std::cout << "  -eraseCache         Erase the cache" << std::endl;
            std::cout << "  -safeMode           Start the server in safe mode" << std::endl;
            return 0;
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }


    return 0;
}
