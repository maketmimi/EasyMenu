#pragma once

#include <iostream>
#include "clsMenu.h"
#include "clsRenderer.h"
#include "..\Platform\IPlatform.h"
#include "..\Platform\PlatformFactory.h"
#include <memory>

class clsNavigator {

    static unsigned int _NavigateMenu(const clsMenu& Menu){

        std::unique_ptr<IPlatform> Platform {CreatePlatform()}; 

        Platform->PrepareTerminal();

        



    } 

public:

    static unsigned int GetSelection(const clsMenu& Menu){

        return _NavigateMenu(Menu);

    }

};