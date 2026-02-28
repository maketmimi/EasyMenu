#pragma once

// factory function to get the correct Platform
#include <iostream>
#include <memory>
#include "IPlatform.h"
#include "clsWindowsPlatform.h"

// initial test

std::unique_ptr<IPlatform> CreatePlatform(){

    return std::make_unique<clsWindowsPlatform>();

}



