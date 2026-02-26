#pragma once

#include <iostream>



class IPlatform {

public:

    enum class enKey{

        Enter,
        UpArrow,
        DownArrow,
        UnknownKey

    };

    virtual void ClearScreen() = 0;

    virtual enKey ReadKey() = 0;

    virtual void PrepareTerminal() = 0;

    virtual void RestoreTerminal() = 0;

    virtual ~IPlatform() = default;

};