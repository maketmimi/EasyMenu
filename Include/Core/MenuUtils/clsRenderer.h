#pragma once

#include <iostream>
#include "Core/MenuUtils/clsMenu.h"
#include "Core/MenuComponents/clsEasyMenuItem.h"
#include <vector>
#include "Core/Platform/IPlatform.h"
#include <memory>


class clsRenderer {

    IPlatform& _Platform;

    class clsItemsRenderer;

    std::unique_ptr<clsItemsRenderer> _ItemsRenderer {std::make_unique<clsItemsRenderer>(*this)};

    void RenderMenuBlock(const EasyMenuComponents::clsMenuBlock& MenuBlock){

        const std::vector<std::string>& vLines {MenuBlock.GetVLines()};

        for (const std::string& Line : vLines)
            std::cout << Line << '\n';
        
    }

public:

    clsRenderer(IPlatform& Platform)
    : _Platform(Platform){}

    void RenderMenu(const clsMenu& MenuToRender, const unsigned int SelectedItem);

};


// include the nested classes definations here
#include "Core/MenuUtils/clsRendererUtils/clsItemsRenderer.h"


void clsRenderer::RenderMenu(const clsMenu& MenuToRender, const unsigned int SelectedItem){

    _Platform.ClearScreen();
    RenderMenuBlock(MenuToRender.GetMenuHeader());
    
    _ItemsRenderer->RenderItems(MenuToRender, SelectedItem);
    
    RenderMenuBlock(MenuToRender.GetMenuFooter());

}   
 