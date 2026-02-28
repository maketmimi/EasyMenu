#pragma once

#include <iostream>



class IPlatform {

public:

    struct stTerminalSize{

        short Rows {}, Columns {};  

    };

    enum class enKey{

        Enter,
        UpArrow,
        DownArrow,
        UnknownKey

    };

    virtual void ClearScreen() = 0;

    virtual enKey ReadKey() = 0;

    // this returns a known key 
    enKey ReadValidKey(){

        enKey Key {enKey::UnknownKey};

        while (Key == enKey::UnknownKey)
            Key = ReadKey();
        
        return Key;
    }

    virtual void PrepareTerminal() = 0;

    virtual void RestoreTerminal() = 0;

    virtual stTerminalSize GetTerminalSize() = 0;

    virtual void HighlightNextOutput() = 0;

    virtual void ResetOutputToOriginalState() = 0;

    virtual ~IPlatform() = default;

};