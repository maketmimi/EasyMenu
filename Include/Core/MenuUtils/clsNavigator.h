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

    void SelectNextItem(){

        ++_SelectedItem%= _MenuToNavigate.GetNumberOfItems();

    }
    
    void SelectPreviousItem(){
        
        if (_SelectedItem == 0)
            _SelectedItem = _MenuToNavigate.GetNumberOfItems() - 1;
        else 
            _SelectedItem--;

    }

    // returns 0 if the Menu is empty
    unsigned int _NavigateMenu(){

        clsRenderer MenuRenderer(_Platform, _MenuToNavigate);
        _Platform.PrepareTerminal();
        
        if (_MenuToNavigate.IsEmpty())
        {
            MenuRenderer.RenderMenu(_SelectedItem); // this will show an empty menu
            _Platform.RestoreTerminal();
            return 0; // Can't navigate empty menu
        }
        
        while (true){

            MenuRenderer.RenderMenu(_SelectedItem);

            IPlatform::enKey KeyPressed {_Platform.ReadValidKey()};

            switch (KeyPressed)
            {
            case IPlatform::enKey::UpArrow:
                SelectPreviousItem();
                break;
            case IPlatform::enKey::DownArrow:
                SelectNextItem();
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
    // returns the selected item starting from 1, and returns 0 if the Menu is empty
    unsigned int GetSelection(){

        return _NavigateMenu();

    }

};