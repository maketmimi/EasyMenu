#pragma once

#include <iostream>
#include <vector>
#include "Core/MenuComponents/clsEasyMenuHeader.h"
#include "Core/MenuComponents/clsEasyMenuFooter.h"
#include "Core/MenuComponents/clsEasyMenuItem.h"
#include "Core/GeneralHelpers/clsStringHelpers.h"

class clsMenu {

    std::string _MenuLabel {"Easy Menu"};
    std::vector<EasyMenuComponents::clsEasyMenuItem> _vItems {};
    EasyMenuComponents::clsEasyMenuHeader _MenuHeader {};
    EasyMenuComponents::clsEasyMenuFooter _MenuFooter {};
    
public:

    // Creates an empty menu
    clsMenu(){}

    static clsMenu GetDefaultMenu(const std::string& Label){

        clsMenu DefaultMenu;

        DefaultMenu._MenuLabel = Label;
        DefaultMenu.SetMenuHeader(EasyMenuComponents::clsEasyMenuHeader::GetDefaultHeader(DefaultMenu._MenuLabel));
        DefaultMenu.SetMenuFooter(EasyMenuComponents::clsEasyMenuFooter::GetDefaultFooter());

        return DefaultMenu;
    }

    void SetMenuHeader(const EasyMenuComponents::clsEasyMenuHeader& Header){

        _MenuHeader = Header;

    }
    const EasyMenuComponents::clsEasyMenuHeader& GetMenuHeader() const { return _MenuHeader; }
    
    void SetMenuFooter(const EasyMenuComponents::clsEasyMenuFooter& Footer){
        
        _MenuFooter = Footer;
        
    }
    const EasyMenuComponents::clsEasyMenuFooter& GetMenuFooter() const { return _MenuFooter; }

    const std::vector<EasyMenuComponents::clsEasyMenuItem>& GetVItems() const { return _vItems; }

    // this won't affect the label shown in the default header
    void SetMenuLabel(const std::string& Label){

        _MenuLabel = Label;

    }
    std::string GetMenuLabel() const { return _MenuLabel; }

    void AddItem(const std::string& Label, bool Active = true, bool Visible = true){

        _vItems.emplace_back(Label, Active, Visible);

    }

    // ItemNumber starting from 1
    bool UpdateItem(size_t ItemNumber, const std::string& Label, bool Active = true, bool Visible = true){

        // Make it index suitable
        ItemNumber--;

        if (ItemNumber >= _vItems.size()) return false;

        _vItems.at(ItemNumber) = EasyMenuComponents::clsEasyMenuItem(Label, Active, Visible);

        return true;
    }

    // ItemNumber starting from 1
    bool RemoveItem(size_t ItemNumber){

        // Make it index suitable
        ItemNumber--;

        if (ItemNumber >= _vItems.size()) return false;

        _vItems.erase(_vItems.begin() + ItemNumber);

        return true;
    }

    // ItemNumber starting from 1
    bool SetVisibility(size_t ItemNumber, bool Visible){

        // Make it index suitable
        ItemNumber--;

        if (ItemNumber >= _vItems.size()) return false;

        _vItems.at(ItemNumber).SetVisibility(Visible);

        return true;
    }

    // ItemNumber starting from 1
    bool SetActivity(size_t ItemNumber, bool Active){

        // Make it index suitable
        ItemNumber--;

        if (ItemNumber >= _vItems.size()) return false;

        _vItems.at(ItemNumber).SetActivity(Active);

        return true;
    }

    void ClearItems(){

        _vItems.clear();

    }

    void ClearHeader(){

        _MenuHeader.ClearLines();

    }
    
    void ClearFooter(){

        _MenuFooter.ClearLines();

    }

    void ClearMenu(){

        ClearHeader();
        ClearItems();
        ClearFooter();

    }

    size_t GetNumberOfItems() const
    {
        return _vItems.size();
    }

    bool IsEmpty() const{

        return _vItems.empty();

    }

    // this has time complixity of O(n)
    bool CheckIfThereIsNavigableItems() const{

        for (const EasyMenuComponents::clsEasyMenuItem& Item : _vItems)
            if (Item.IsActive() && Item.IsVisible())
                return true;

        return false;
    }

    const EasyMenuComponents::clsEasyMenuItem& GetItem(size_t Index) const{

        return _vItems.at(Index);

    }

};