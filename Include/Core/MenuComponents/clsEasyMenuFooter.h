#pragma once

#include <iostream>
#include "clsMenuBlock.h"


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
