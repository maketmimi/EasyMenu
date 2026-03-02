#pragma once

#if defined(__unix__) || defined(__linux__) || defined(__APPLE__)

#include <iostream>
#include <unistd.h>
#include "termios.h"
#include "Core/Platform/IPlatform.h"
#include "sys/ioctl.h"
#include "Core/AnsiCodeHelpers/clsAnsiCode.h"


class clsPOSIXPlatform : public IPlatform{

    const termios OriginalTerminalAttrs {_GetCurrentTerminalAttrs()};

    termios _GetCurrentTerminalAttrs(){

        termios CurrentTerminalAttrs;

        tcgetattr(STDIN_FILENO, &CurrentTerminalAttrs);

        return CurrentTerminalAttrs;
    }

    void _EnableTerminalRawMode(){

        termios RawTerminalAttrs {OriginalTerminalAttrs};

        RawTerminalAttrs.c_lflag &= ~(ECHO | ICANON);

        tcsetattr(STDIN_FILENO, TCSANOW, &RawTerminalAttrs);

    }

    void _ResetTerminalAttrs(){

        tcsetattr(STDIN_FILENO, TCSANOW, &OriginalTerminalAttrs);

    }

public:

    void ClearScreen() override{

        clsAnsiCode::ClearScreen();

    }

    // this should be called after configuring the terminal
    enKey ReadKey() override{

        char Key {};
        
        read(STDIN_FILENO, &Key, 1);
        switch (Key)
        {
        case '\x1b': // special key prefix 
            read(STDIN_FILENO, &Key, 1);
            if (Key == '[')
            {
                read(STDIN_FILENO, &Key, 1);
                switch (Key)
                {
                case 'A':
                    return enKey::UpArrow;
                case 'B':
                    return enKey::DownArrow;
                }              
            }
            break;
        case '\n':
            return enKey::Enter;
        }
 
        return enKey::UnknownKey;
    }

    void PrepareTerminal() override{

        _EnableTerminalRawMode();
        SetCursorVisibility(false);

    }

    void RestoreTerminal() override{

        _ResetTerminalAttrs();
        SetCursorVisibility(true);

    }

    stTerminalSize GetTerminalSize() override{

        winsize TerminalSize;

        ioctl(STDOUT_FILENO, TIOCGWINSZ, &TerminalSize);

        return stTerminalSize{(short) TerminalSize.ws_row, (short) TerminalSize.ws_col};        
    }

    void ResetOutputToOriginalState() override{

        clsAnsiCode::ResetOutputAttrs();

    }

    void HighlightNextOutput() override{

        clsAnsiCode::HighlightNextOutput();
        
    }

    void SetCursorVisibility(bool Visible) override{

        if (Visible)
            clsAnsiCode::ShowCurser();
        else
            clsAnsiCode::HideCurser();

    }

};


#endif
