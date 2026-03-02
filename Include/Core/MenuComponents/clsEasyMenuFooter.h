#pragma once

#include <iostream>
#include "Core/MenuComponents/clsMenuBlock.h"


namespace EasyMenuComponents {

    class clsEasyMenuFooter : public clsMenuBlock{
    
    public:
    
        clsEasyMenuFooter(){}
    
        static clsEasyMenuFooter GetDefaultFooter(){
    
            clsEasyMenuFooter DefaultFooter;
    
            DefaultFooter.AddLine("============================");
    
            return DefaultFooter;
        }
    
    };

}
