#pragma once

// factory function to get the correct Platform
#include <memory>
#include "Core/Platform/IPlatform.h"

#if defined(_WIN32)

    #include "Core/Platform/clsWindowsPlatform.h"

#elif defined(__unix__) || defined(__linux__) || defined(__APPLE__)

    #include "Core/Platform/clsPOSIXPlatform.h"

#else

    #error "Platform is not compatible with EasyMenu library"

#endif


std::unique_ptr<IPlatform> CreatePlatform(){

    #if defined(_WIN32)

        return std::make_unique<clsWindowsPlatform>();
    
    #elif defined(__unix__) || defined(__linux__) || defined(__APPLE__)

        return std::make_unique<clsPOSIXPlatform>();

    #else

        #error "Platform is not compatible with EasyMenu library"
    
    #endif

}



