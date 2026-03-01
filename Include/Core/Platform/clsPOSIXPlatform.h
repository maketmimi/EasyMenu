#pragma once

#include <iostream>
#include "IPlatform.h"


class clsPOSIXPlatform : public IPlatform{

public:

    void ClearScreen() override{



    }

    enKey ReadKey() override{

        
    }

    void PrepareTerminal() override{


    }

    void RestoreTerminal() override{


    }

    stTerminalSize GetTerminalSize() override{

        
    }

    void ResetOutputToOriginalState() override{


    }

    void HighlightNextOutput() override{

        
    }

    void SetCursorVisibility(bool Visible) override{

        

    }

};