#pragma once

#include <iostream>
#include "clsMenu.h"
#include "clsRenderer.h"
#include "..\Platform\IPlatform.h"
#include "..\Platform\PlatformFactory.h"
#include <memory>

class clsNavigator {

    IPlatform& _Platform;
    const clsMenu& _MenuToNavigate;
    unsigned int _SelectedItem {0};

    bool _IsItemNavigable(const EasyMenuComponents::clsEasyMenuItem& ItemToCheck){

        return _MenuToNavigate.GetItem(_SelectedItem).IsActive() && _MenuToNavigate.GetItem(_SelectedItem).IsVisible();

    }

    void _SelectNextItem(){

        do
        {
            ++_SelectedItem%= _MenuToNavigate.GetNumberOfItems();
        }
        while (!_IsItemNavigable(_MenuToNavigate.GetItem(_SelectedItem)));

    }
    
    void _SelectPreviousItem(){
        
        do
        {
            if (_SelectedItem == 0)
                _SelectedItem = _MenuToNavigate.GetNumberOfItems() - 1;
            else 
                _SelectedItem--;
        }
        while (!_IsItemNavigable(_MenuToNavigate.GetItem(_SelectedItem)));

    }

    // returns 0 if the Menu is empty
    unsigned int _NavigateMenu(){

        clsRenderer MenuRenderer(_Platform, _MenuToNavigate);
        _Platform.PrepareTerminal();
        
        if (_MenuToNavigate.IsEmpty() || !_MenuToNavigate.CheckIfThereIsNavigableItems())
        {
            MenuRenderer.RenderMenu(_SelectedItem); 
            _Platform.RestoreTerminal();
            return 0; // Can't navigate menu
        }
        
        while (true){

            MenuRenderer.RenderMenu(_SelectedItem);

            IPlatform::enKey KeyPressed {_Platform.ReadValidKey()};

            switch (KeyPressed)
            {
            case IPlatform::enKey::UpArrow:
                _SelectPreviousItem();
                break;
            case IPlatform::enKey::DownArrow:
                _SelectNextItem();
                break;
            default:
                _Platform.RestoreTerminal();
                return _SelectedItem + 1;      
            }

        }
        
    } 

public:

    clsNavigator(IPlatform& Platform, const clsMenu& MenuToNavigate) : _Platform(Platform), _MenuToNavigate(MenuToNavigate)
    {}

    // this shows the menu to the user and
    // returns the selected item starting from 1, 
    // and returns 0 if the Menu is empty or can't be navigated ie. "all items are invisible"
    unsigned int GetSelection(){

        return _NavigateMenu();

    }

};