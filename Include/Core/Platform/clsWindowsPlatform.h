#pragma once

#if defined(_WIN32)

#include <iostream>
#include <windows.h>
#include "Core/Platform/IPlatform.h"
#include <conio.h>
#include "Core/GeneralHelpers/clsValidate.h"

class clsWindowsPlatform : public IPlatform{

    enum enWindowsKeys {

        eUpArrow = 72,
        eDownArrow = 80,
        eEnter = 13,
        eSpecialKeyPrefix = 224

    };

    // initially we will handle this like this but maybe this will be changed in the future
    const WORD _OriginalConsoleAttributes {_GetCurrentTextAttributes()};

    WORD _GetCurrentTextAttributes(){

        CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleInfo);

        return ConsoleInfo.wAttributes;
    }

public:

    // this should be refactored
    void ClearScreen() override{

        system("cls");

    }

    enKey ReadKey() override{

        switch (_getch())
        {
        case enWindowsKeys::eEnter:
            return enKey::Enter;
        case enWindowsKeys::eSpecialKeyPrefix:
            switch (_getch())
            {
            case enWindowsKeys::eUpArrow:
                return enKey::UpArrow;                
            case enWindowsKeys::eDownArrow:
                return enKey::DownArrow;                
            }
        }
    
        return enKey::UnknownKey;
    }

    void PrepareTerminal() override{

        SetCursorVisibility(false);

    }

    void RestoreTerminal() override{

        SetCursorVisibility(true);
        ResetOutputToOriginalState();

    }

    stTerminalSize GetTerminalSize() override{

        stTerminalSize CurrentTerminalSize;

        CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleInfo);

        CurrentTerminalSize.Rows = ConsoleInfo.srWindow.Bottom - ConsoleInfo.srWindow.Top + 1; 
        CurrentTerminalSize.Columns = ConsoleInfo.srWindow.Right - ConsoleInfo.srWindow.Left + 1; 

        return CurrentTerminalSize;
    }

    void ResetOutputToOriginalState() override{

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _OriginalConsoleAttributes);

    }

    void HighlightNextOutput() override{

        WORD CurrentTextAttributes {_GetCurrentTextAttributes()};
        
        WORD ForeColor = CurrentTextAttributes & 0x0F;
        WORD BackGroundColor = CurrentTextAttributes & 0xF0;

        WORD InvertedAttrs {(short unsigned int) ((ForeColor << 4) | (BackGroundColor >> 4))};

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), InvertedAttrs);

    }

    void SetCursorVisibility(bool Visible) override{

        CONSOLE_CURSOR_INFO CursorInfo;
        HANDLE hSTDOutput {GetStdHandle(STD_OUTPUT_HANDLE)};

        GetConsoleCursorInfo(hSTDOutput, &CursorInfo);

        if (!clsValidate::IsNumberBetween((int) (CursorInfo.dwSize), 1, 100))
            CursorInfo.dwSize = 25; // this is hardcoded default value in case the value was wrong

        CursorInfo.bVisible = (BOOL) Visible;

        SetConsoleCursorInfo(hSTDOutput, &CursorInfo);

    }

    ~clsWindowsPlatform(){

        RestoreTerminal();

    }

};


#endif