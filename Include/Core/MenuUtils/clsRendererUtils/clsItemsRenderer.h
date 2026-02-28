#pragma once

#include <iostream>
#include "..\clsRenderer.h"


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

    public:
    
    clsItemsRenderer(clsRenderer& Renderer) : _Renderer(Renderer) {}

    void RenderItems(unsigned int SelectedItem);

};

// include nested classe here
#include "clsItemsPage.h"

void clsRenderer::clsItemsRenderer::RenderItems(unsigned int SelectedItem){

    clsItemsPage(_Renderer, *this).RenderPage(SelectedItem);
    
}