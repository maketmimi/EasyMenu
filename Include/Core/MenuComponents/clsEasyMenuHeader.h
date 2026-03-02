#pragma once

#include <iostream>
#include "Core/MenuComponents/clsMenuBlock.h"


namespace EasyMenuComponents{

    class clsEasyMenuHeader : public clsMenuBlock{
    
    public:
    
        clsEasyMenuHeader(){}
    
        // returns default Header with a label
        static clsEasyMenuHeader GetDefaultHeader(const std::string& Label = "Easy Menu"){
    
            clsEasyMenuHeader DefaultHeader;
    
            DefaultHeader.AddLine("============================");
            DefaultHeader.AddLine("        " + Label);
            DefaultHeader.AddLine("============================");
    
            return DefaultHeader;
        }
    
    };

}
