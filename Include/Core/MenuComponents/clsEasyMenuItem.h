#pragma once

#include <iostream>


namespace EasyMenuComponents{

    class clsEasyMenuItem{
    
        std::string _Label {};
        bool _Active {true}, _Visible {true}; 
    
    public:
    
        clsEasyMenuItem(const std::string& Label, bool Active = true, bool Visible = true)
        : _Label(Label), _Active(Active), _Visible(Visible)
        {}
    
        void SetLabel(const std::string& label) { _Label = label; }
        const std::string& GetLabel() const { return _Label; }
    
        void SetActivity(bool active) { _Active = active; }
        bool IsActive() const { return _Active; }
    
        void SetVisibility(bool visible) { _Visible = visible; }
        bool IsVisible() const { return _Visible; }
    
        bool IsNavigable() const {

            return _Visible && _Active;

        }

    };

}

