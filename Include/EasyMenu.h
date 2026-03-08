#pragma once

#include <iostream>
#include <vector>
#include "Core/MenuUtils/clsMenu.h"
#include "Core/MenuUtils/clsNavigator.h"
#include "Core/Platform/IPlatform.h"
#include <memory>
#include "Core/Platform/PlatformFactory.h"

class EasyMenu {

    std::unique_ptr<IPlatform> _Platform {CreatePlatform()};
    clsMenu _Menu;
    
public:
    
    // Creates an empty menu that does not have even a default header or footer
    EasyMenu(){}

    // Creates default menu with a default footer and a header that shows the menu label
    EasyMenu(const std::string& MenuLabel){

        _Menu = clsMenu::GetDefaultMenu(MenuLabel);

    }

    /// @brief This method shows the menu to the user and returns the number of the selected item starting from 1
    /// @param ItemToStartFrom this specifies the number of the item to start from another words the first item to be highlighted defaults to 1 which is the first item
    /// @return returns the Number of the selected item 
    unsigned int RunMenu(unsigned int ItemToStartFrom = 1){

        return clsNavigator(*_Platform).GetSelection(_Menu, ItemToStartFrom);

    }

    void AddItem(const std::string& Label, bool Active = true, bool Visible = true){

        _Menu.AddItem(Label, Active, Visible);

    }

    bool UpdateItem(size_t ItemNumber, const std::string& Label, bool Active = true, bool Visible = true){

        return _Menu.UpdateItem(ItemNumber, Label, Active, Visible);

    }

    bool RemoveItem(size_t ItemNumber){

        return _Menu.RemoveItem(ItemNumber);

    }

    bool SetVisibility(size_t ItemNumber, bool Visible){

        return _Menu.SetVisibility(ItemNumber, Visible);

    }

    bool SetActivity(size_t ItemNumber, bool Active){

        return _Menu.SetActivity(ItemNumber, Active);

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
    const EasyMenuComponents::clsEasyMenuHeader& GetHeader() const {

        return _Menu.GetMenuHeader();

    }
    
    void SetFooter(const EasyMenuComponents::clsEasyMenuFooter& Footer){
        
        _Menu.SetMenuFooter(Footer);
        
    }
    const EasyMenuComponents::clsEasyMenuFooter& GetFooter() const {

        return _Menu.GetMenuFooter();

    }
    
    size_t GetNumberOfItems() const{

        return _Menu.GetNumberOfItems();

    }

    bool IsEmpty() const {

        return _Menu.IsEmpty();

    }

};