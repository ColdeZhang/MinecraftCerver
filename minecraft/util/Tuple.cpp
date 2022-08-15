//
// Created by deer on 2022/8/15.
//

#include "Tuple.h"

namespace cerver {
    namespace minecraft {
        namespace util {
            
            template<typename A, typename B>
            Tuple<A, B>::Tuple(A a, B b) {
                m_a = a;
                m_b = b;
            }
            
            template<typename A, typename B>
            A Tuple<A, B>::getA() {
                return m_a;
            }
            
            template<typename A, typename B>
            void Tuple<A, B>::setA(A a) {
                m_a = a;
            }
            
            template<typename A, typename B>
            B Tuple<A, B>::getB() {
                return m_b;
            }
            
            template<typename A, typename B>
            void Tuple<A, B>::setB(B b) {
                m_b = b;
            }

        }
    }
}

