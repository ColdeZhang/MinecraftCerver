//
// Created by deer on 2022/8/15.
//

#ifndef MINECRAFTCERVER_TUPLE_H
#define MINECRAFTCERVER_TUPLE_H

namespace cerver {
    namespace minecraft {
        namespace util {
            template<typename A, typename B>
            class Tuple {
            private:
                A m_a;
                B m_b;

            public:
                Tuple(A a, B b);

                A getA();

                void setA(A a);

                B getB();

                void setB(B b);
            };
        }
    }
}

#endif //MINECRAFTCERVER_TUPLE_H