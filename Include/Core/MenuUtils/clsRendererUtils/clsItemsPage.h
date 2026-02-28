#pragma once

#include <iostream>
#include "clsItemsRenderer.h"


class clsRenderer::clsItemsRenderer::clsItemsPage{
        
    clsRenderer& _Renderer;
    clsItemsRenderer& _ItemsRenderer;

    unsigned short _NumberOfItemsInPage {}, _PageNumber {}, _FirstItemIndex {}, _LastItemIndex {};

    unsigned short _CaculateNumberOfItemsInPage(){
        
        IPlatform::stTerminalSize CurrentTerminalSize {_Renderer._Platform.GetTerminalSize()};
        
        unsigned short MenuBlocksLinesNumber {(unsigned short) (_Renderer._MenuToRender.GetMenuHeader().GetNumberOfLines() + _Renderer._MenuToRender.GetMenuFooter().GetNumberOfLines())};
        
        unsigned short AvalibleLinesForItems {(unsigned short) (CurrentTerminalSize.Rows - MenuBlocksLinesNumber)};
        
        // there is a min value for the number of items in the page which is 2
        const short MIN_PAGE_SIZE = 2;

        if (AvalibleLinesForItems > _Renderer._MenuToRender.GetNumberOfItems() || _Renderer._MenuToRender.GetNumberOfItems() < MIN_PAGE_SIZE)
            return _Renderer._MenuToRender.GetNumberOfItems();
        else
            return AvalibleLinesForItems > MIN_PAGE_SIZE ? AvalibleLinesForItems : MIN_PAGE_SIZE;
    
   }

    void _PreparePage(unsigned int SelectedItem){

        _NumberOfItemsInPage = _CaculateNumberOfItemsInPage();
        _PageNumber = SelectedItem / _NumberOfItemsInPage;
        _FirstItemIndex = _NumberOfItemsInPage * _PageNumber;
        short tempLastItemIndex {(short) (_FirstItemIndex + _NumberOfItemsInPage - 1)};
        _LastItemIndex = tempLastItemIndex >= _Renderer._MenuToRender.GetVItems().size() ? _Renderer._MenuToRender.GetVItems().size() - 1 : tempLastItemIndex;

    }

public:
    
    clsItemsPage(clsRenderer& Renderer, clsItemsRenderer& ItemsRenderer)
    : _Renderer(Renderer), _ItemsRenderer(ItemsRenderer) {}
    
    void RenderPage(unsigned int SelectedItem){

        if (_Renderer._MenuToRender.IsEmpty()) std::cout << "Ops... this menu is empty!\n";

        _PreparePage(SelectedItem);

        const std::vector<EasyMenuComponents::clsEasyMenuItem>& vItems {_Renderer._MenuToRender.GetVItems()};

        for (short i = _FirstItemIndex; i <= _LastItemIndex; i++)
            _ItemsRenderer._RenderSingelItem(vItems.at(i), (i == SelectedItem));
            
    }

};