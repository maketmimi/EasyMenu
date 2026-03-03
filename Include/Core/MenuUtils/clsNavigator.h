#pragma once

#include <iostream>
#include "Core/MenuUtils/clsMenu.h"
#include "Core/MenuUtils/clsRenderer.h"
#include "Core/Platform/IPlatform.h"
#include "Core/Platform/PlatformFactory.h"
#include <memory>

class clsNavigator {

    IPlatform& _Platform;

    unsigned int _SelectNextItem(const clsMenu& MenuToNavigate, unsigned int SelectedItem){

        do
        {
            ++SelectedItem %= MenuToNavigate.GetNumberOfItems();
        }
        while (!MenuToNavigate.GetItem(SelectedItem).IsNavigable());

        return SelectedItem;
    }
    
    unsigned int _SelectPreviousItem(const clsMenu& MenuToNavigate, unsigned int SelectedItem){
        
        do
        {
            if (SelectedItem == 0)
                SelectedItem = (unsigned int) MenuToNavigate.GetNumberOfItems() - 1;
            else 
                SelectedItem--;
        }
        while (!MenuToNavigate.GetItem(SelectedItem).IsNavigable());

        return SelectedItem;
    }

    unsigned int _GetClosestNavigableItemNumber(const clsMenu& MenuToNavigate, unsigned int ItemToStartFrom = 1){

        if (MenuToNavigate.GetItem(ItemToStartFrom).IsNavigable())
            return ItemToStartFrom;
        
        return _SelectNextItem(MenuToNavigate, ItemToStartFrom);
    }

    unsigned int _GetItemNumberToStartFrom(const clsMenu& MenuToNavigate, unsigned int ItemToStartFrom = 1){

        // note that the items numbering is starting from 0 inside the class and from 1 for the outside users
        if (ItemToStartFrom < 1)
            ItemToStartFrom = 0;
        else
            ItemToStartFrom--;

        if (MenuToNavigate.IsItemNumberInMenu(ItemToStartFrom))
            return _GetClosestNavigableItemNumber(MenuToNavigate, ItemToStartFrom);
        else
            return _GetClosestNavigableItemNumber(MenuToNavigate, 0);

    }

    // returns 0 if the Menu is empty
    unsigned int _NavigateMenu(const clsMenu& MenuToNavigate, unsigned int ItemToStartFrom = 1){

        clsRenderer MenuRenderer(_Platform);
        _Platform.PrepareTerminal();

        if (MenuToNavigate.IsEmpty() || !MenuToNavigate.CheckIfThereIsNavigableItems())
        {
            MenuRenderer.RenderMenu(MenuToNavigate, 0); 
            _Platform.RestoreTerminal();
            return 0; // Can't navigate menu
        }
        
        unsigned int SelectedItem {_GetItemNumberToStartFrom(MenuToNavigate, ItemToStartFrom)};
        
        while (true){

            MenuRenderer.RenderMenu(MenuToNavigate, SelectedItem);

            IPlatform::enKey KeyPressed {_Platform.ReadValidKey()};

            switch (KeyPressed)
            {
            case IPlatform::enKey::UpArrow:
                SelectedItem = _SelectPreviousItem(MenuToNavigate, SelectedItem);
                break;
            case IPlatform::enKey::DownArrow:
                SelectedItem = _SelectNextItem(MenuToNavigate, SelectedItem);
                break;
            default:
                _Platform.RestoreTerminal();
                return SelectedItem + 1; // note that the items numbering is starting from 0 inside the class and from 1 for the outside users
            }

        }
        
    } 

public:

    clsNavigator(IPlatform& Platform) : _Platform(Platform)
    {}

    // this shows the menu to the user and
    // returns the selected item starting from 1, 
    // and returns 0 if the Menu is empty or can't be navigated ie. "all items are invisible"
    unsigned int GetSelection(const clsMenu& MenuToNavigate, unsigned int ItemToStartFrom = 1){

        return _NavigateMenu(MenuToNavigate, ItemToStartFrom);

    }

};