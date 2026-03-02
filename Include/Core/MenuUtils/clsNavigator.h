#pragma once

#include <iostream>
#include "Core/MenuUtils/clsMenu.h"
#include "Core/MenuUtils/clsRenderer.h"
#include "Core/Platform/IPlatform.h"
#include "Core/Platform/PlatformFactory.h"
#include <memory>

class clsNavigator {

    IPlatform& _Platform;

    bool _IsItemNavigable(const EasyMenuComponents::clsEasyMenuItem& ItemToCheck){

        return ItemToCheck.IsActive() && ItemToCheck.IsVisible();

    }

    void _SelectNextItem(const clsMenu& MenuToNavigate, unsigned int& SelectedItem){

        do
        {
            ++SelectedItem%= MenuToNavigate.GetNumberOfItems();
        }
        while (!_IsItemNavigable(MenuToNavigate.GetItem(SelectedItem)));

    }
    
    void _SelectPreviousItem(const clsMenu& MenuToNavigate, unsigned int& SelectedItem){
        
        do
        {
            if (SelectedItem == 0)
                SelectedItem = (unsigned int) MenuToNavigate.GetNumberOfItems() - 1;
            else 
                SelectedItem--;
        }
        while (!_IsItemNavigable(MenuToNavigate.GetItem(SelectedItem)));

    }

    // returns 0 if the Menu is empty
    unsigned int _NavigateMenu(const clsMenu& MenuToNavigate){

        clsRenderer MenuRenderer(_Platform);
        _Platform.PrepareTerminal();

        unsigned int SelectedItem {0};
        
        if (MenuToNavigate.IsEmpty() || !MenuToNavigate.CheckIfThereIsNavigableItems())
        {
            MenuRenderer.RenderMenu(MenuToNavigate, SelectedItem); 
            _Platform.RestoreTerminal();
            return 0; // Can't navigate menu
        }
        
        while (true){

            MenuRenderer.RenderMenu(MenuToNavigate, SelectedItem);

            IPlatform::enKey KeyPressed {_Platform.ReadValidKey()};

            switch (KeyPressed)
            {
            case IPlatform::enKey::UpArrow:
                _SelectPreviousItem(MenuToNavigate, SelectedItem);
                break;
            case IPlatform::enKey::DownArrow:
                _SelectNextItem(MenuToNavigate, SelectedItem);
                break;
            default:
                _Platform.RestoreTerminal();
                return SelectedItem + 1;      
            }

        }
        
    } 

public:

    clsNavigator(IPlatform& Platform) : _Platform(Platform)
    {}

    // this shows the menu to the user and
    // returns the selected item starting from 1, 
    // and returns 0 if the Menu is empty or can't be navigated ie. "all items are invisible"
    unsigned int GetSelection(const clsMenu& MenuToNavigate){

        return _NavigateMenu(MenuToNavigate);

    }

};