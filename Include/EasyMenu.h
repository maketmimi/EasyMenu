#pragma once

#include <iostream>
#include <vector>
#include "Core\MenuUtils\clsMenu.h"
#include "Core\MenuUtils\clsNavigator.h"

class EasyMenu {

    clsMenu _Menu;
    
public:
    
    // Creates an empty menu that does not have even a default header or footer
    EasyMenu(){}

    // Creates default menu with a default footer and a header that shows the menu label
    EasyMenu(const std::string& MenuLabel){

        _Menu = clsMenu::GetDefaultMenu(MenuLabel);

    }

    // this shows the interactive menu and returns what the user selected.
    unsigned int RunMenu(){

        return clsNavigator::GetSelection(_Menu);

    }

    void AddItem(const std::string& Label, bool Active = true, bool Visible = true){

        _Menu.AddItem(Label, Active, Visible);

    }

    bool UpdateItem(size_t ItemNumber, const std::string& Label, bool Active = true, bool Visible = true){

        _Menu.UpdateItem(ItemNumber, Label, Active, Visible);

    }

    bool RemoveItem(size_t ItemNumber){

        _Menu.RemoveItem(ItemNumber);

    }

    bool SetVisibility(size_t ItemNumber, bool Visible){

        _Menu.SetVisibility(ItemNumber, Visible);

    }

    bool SetActivity(size_t ItemNumber, bool Active){

        _Menu.SetActivity(ItemNumber, Active);

    }

    void ClearItems(){

        _Menu.ClearItems();

    }
  
    void ClearHeader(){

        _Menu.ClearHeader();

    }

    void ClearFooter(){

        _Menu.ClearFooter();

    }

    void ClearMenu(){

        _Menu.ClearMenu();

    }

    void SetHeader(const EasyMenuComponents::clsEasyMenuHeader& Header){

        _Menu.SetMenuHeader(Header);

    }
    EasyMenuComponents::clsEasyMenuHeader GetHeader() const {

        return _Menu.GetMenuHeader();

    }
    
    void SetFooter(const EasyMenuComponents::clsEasyMenuFooter& Footer){
        
        _Menu.SetMenuFooter(Footer);
        
    }
    EasyMenuComponents::clsEasyMenuFooter GetFooter() const {

        return _Menu.GetMenuFooter();

    }
    
};