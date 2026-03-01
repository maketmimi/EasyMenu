#pragma once

#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <optional>

class clsAnsiCode {

public:

    struct stCurserPosition{

        int Row {}, Column{};

    };

    static void MoveCurser(stCurserPosition Pos){

        printf("\x1b[%i;%iH", Pos.Row, Pos.Column);

    }    

    static void HideCurser(){

        printf("\x1b[?25l");

    }

    static void ShowCurser(){

        printf("\x1b[?25h");

    }

    static void HighlightNextOutput(){

        printf("\x1b[7m"); // basicly invert background and font colors

    }

    static void Reset(){

        printf("\x1b[0m");

    }

    static void ClearCurrentLine(){

        printf("\x1b[2K");

    }

    static std::optional<stCurserPosition> GetCurserPosition(){

        std::string Response; 
        char temp {};
        
        // send request
        tcflush(STDIN_FILENO, TCIFLUSH); // to discard any pending keystrokes in the input queue
        printf("\x1b[6n\r"); // expected \x1b[ROW;COLR
        fflush(stdout);
        
        for (short i = 0; i < 32; ++i){

            read(STDIN_FILENO, &temp, 1);
            Response.push_back(temp);

            if (!Response.empty() && Response.front() == '\x1b' && Response.back() == 'R')
            {
                stCurserPosition CurrentCurserPos;

                std::sscanf(Response.c_str(), "\x1b[%i;%iR", &CurrentCurserPos.Row, &CurrentCurserPos.Column);

                ClearCurrentLine();
                return CurrentCurserPos;
            }
        }
        
        ClearCurrentLine();
        return std::nullopt; // undefined behavior
    }

    enum class enKeyStroke{

        UpArrow,
        DownArrow,
        Enter,
        UnknownKey

    };

    static enKeyStroke ReadKey(){

        char Key {};
        
        read(STDIN_FILENO, &Key, 1);
        switch (Key)
        {
        case '\x1b':
            read(STDIN_FILENO, &Key, 1);
            if (Key == '[')
            {
                read(STDIN_FILENO, &Key, 1);
                switch (Key)
                {
                case 'A':
                    return enKeyStroke::UpArrow;
                case 'B':
                    return enKeyStroke::DownArrow;
                }              
            }
            break;
        case '\n':
            return enKeyStroke::Enter;
        }
 
        return enKeyStroke::UnknownKey;
    }

    static termios InitConsole(){

        termios OriginalSettings;
        tcgetattr(STDIN_FILENO, &OriginalSettings);
        termios TempSettings {OriginalSettings};
        TempSettings.c_lflag &= ~(ECHO | ICANON);
        tcsetattr(STDIN_FILENO, TCSANOW, &TempSettings);
        clsAnsiCode::HideCurser();

        return OriginalSettings;
    }

};