#pragma once

#include <iostream>
#include "..\clsRenderer.h"
#include <memory>

class clsRenderer::clsItemsRenderer{
        
    clsRenderer& _Renderer;

    void _RenderSingelItem(const EasyMenuComponents::clsEasyMenuItem& Item, bool IsSelected){

        if (!Item.IsVisible()) return;
        
        // may be we have a function that beleongs to a theme that prints a highlighted text or some thing
        if (IsSelected && Item.IsActive())
        {
            _Renderer._Platform.HighlightNextOutput();
            std::cout << Item.GetLabel() << '\n';
            _Renderer._Platform.ResetOutputToOriginalState();
        }
        else
            std::cout << Item.GetLabel() << '\n';

    }
    
    class clsItemsPage;

    std::unique_ptr<clsItemsPage> _ItemsPage {std::make_unique<clsItemsPage>(*this)};

    public:
    
    clsItemsRenderer(clsRenderer& Renderer) : _Renderer(Renderer) {}

    void RenderItems(const clsMenu& MenuToRender, unsigned int SelectedItem);

};

// include nested classes here
#include "clsItemsPage.h"

void clsRenderer::clsItemsRenderer::RenderItems(const clsMenu& MenuToRender, unsigned int SelectedItem){

    _ItemsPage->RenderPage(MenuToRender, SelectedItem);
    
}