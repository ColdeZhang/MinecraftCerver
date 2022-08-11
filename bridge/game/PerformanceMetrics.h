//
// Created by deer on 2022/8/11.
//

#ifndef MINECRAFTCERVER_PERFORMANCEMETRICS_H
#define MINECRAFTCERVER_PERFORMANCEMETRICS_H

namespace cerver {
    namespace bridge {
        namespace game {
            class PerformanceMetrics {
                virtual int getMinTime();

                virtual int getMaxTime();

                virtual int getAverageTime();

                virtual int getSampleCount();
            };
        } // game
    } // bridge
}

#endif //MINECRAFTCERVER_PERFORMANCEMETRICS_H
