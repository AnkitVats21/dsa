#pragma once
#include "AlgorithmFactory.h"

#ifndef CATEGORY_NAME
#define CATEGORY_NAME "Unknown"
#endif

#define REGISTER_ALGORITHM(className) \
    namespace { \
        struct AutoRegister_##className { \
            AutoRegister_##className() { \
                AlgorithmFactory::instance().registerAlgorithm( \
                    #className, CATEGORY_NAME, [](){ return std::make_unique<className>(); } \
                ); \
            } \
        }; \
        static AutoRegister_##className global_instance_##className; \
    }
