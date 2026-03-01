#pragma once

#include <iostream>
#include "clsItemsRenderer.h"


class clsRenderer::clsItemsRenderer::clsItemsPage{
        
    clsItemsRenderer& _ItemsRenderer;

    unsigned short _NumberOfItemsInPage {}, _PageNumber {}, _FirstItemIndex {}, _LastItemIndex {};

    unsigned short _CaculateNumberOfItemsInPage(const clsMenu& MenuToRender){
        
        IPlatform::stTerminalSize CurrentTerminalSize {_ItemsRenderer._Renderer._Platform.GetTerminalSize()};
        
        unsigned short MenuBlocksLinesNumber {(unsigned short) (MenuToRender.GetMenuHeader().GetNumberOfLines() + MenuToRender.GetMenuFooter().GetNumberOfLines())};
        
        unsigned short AvalibleLinesForItems {(unsigned short) (CurrentTerminalSize.Rows - MenuBlocksLinesNumber)};
        
        // there is a min value for the number of items in the page which is 2
        const unsigned short MIN_PAGE_SIZE = 2;

        if (AvalibleLinesForItems > MenuToRender.GetNumberOfItems() || MenuToRender.GetNumberOfItems() < MIN_PAGE_SIZE)
            return (unsigned short int) MenuToRender.GetNumberOfItems();
        else
            return AvalibleLinesForItems > MIN_PAGE_SIZE ? AvalibleLinesForItems : MIN_PAGE_SIZE;
    
   }

    void _PreparePage(const clsMenu& MenuToRender, unsigned int SelectedItem){

        _NumberOfItemsInPage = _CaculateNumberOfItemsInPage(MenuToRender);

        if (_NumberOfItemsInPage == 0) return; // no need to complete as the menu is empty

        _PageNumber = SelectedItem / _NumberOfItemsInPage;
        _FirstItemIndex = _NumberOfItemsInPage * _PageNumber;
        unsigned short tempLastItemIndex {(unsigned short) (_FirstItemIndex + _NumberOfItemsInPage - 1)};
        _LastItemIndex = tempLastItemIndex >= MenuToRender.GetVItems().size() ? (unsigned short int) (MenuToRender.GetVItems().size() - 1) : tempLastItemIndex;

    }

public:
    
    clsItemsPage(clsItemsRenderer& ItemsRenderer)
    : _ItemsRenderer(ItemsRenderer) {}
    
    void RenderPage(const clsMenu& MenuToRender, unsigned int SelectedItem){

        if (MenuToRender.IsEmpty()) 
        {
            std::cout << "Ops... this menu is empty!\n";
            return;
        }

        _PreparePage(MenuToRender, SelectedItem);
        const std::vector<EasyMenuComponents::clsEasyMenuItem>& vItems {MenuToRender.GetVItems()};

        for (short i = _FirstItemIndex; i <= _LastItemIndex; i++)
            _ItemsRenderer._RenderSingelItem(vItems.at(i), (i == SelectedItem));
            
    }

};