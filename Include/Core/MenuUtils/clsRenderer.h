#pragma once

#include <iostream>
#include "clsMenu.h"
#include "..\MenuComponents\clsEasyMenuItem.h"
#include <vector>
#include "..\Platform\IPlatform.h"

class clsRenderer {

    IPlatform& _Platform;
    const clsMenu& _MenuToRender;

    class clsItemsRenderer;

    void RenderMenuBlock(const EasyMenuComponents::clsMenuBlock& MenuBlock){

        const std::vector<std::string>& vLines {MenuBlock.GetVLines()};

        for (const std::string& Line : vLines)
            std::cout << Line << '\n';
        
    }

public:

    clsRenderer(IPlatform& Platform, const clsMenu& MenuToRender)
    : _Platform(Platform), _MenuToRender(MenuToRender) {}

    void RenderMenu(const unsigned int SelectedItem);

};


// include the nested classes definations here
#include "clsRendererUtils\clsItemsRenderer.h"


void clsRenderer::RenderMenu(const unsigned int SelectedItem){

    _Platform.ClearScreen();
    RenderMenuBlock(_MenuToRender.GetMenuHeader());
    
    clsItemsRenderer(*this).RenderItems(SelectedItem);
    
    RenderMenuBlock(_MenuToRender.GetMenuFooter());

}   
 