#pragma once

#include <iostream>

class clsAnsiCode {

public:

    static void HideCurser(){

        std::cout << "\x1b[?25l";

    }

    static void ShowCurser(){

        std::cout << "\x1b[?25h";

    }

    static void HighlightNextOutput(){

        std::cout << "\x1b[7m"; // basicly invert background and font colors

    }

    static void ResetOutputAttrs(){

        std::cout << "\x1b[0m";

    }

    static void ClearScreen(){

        std::cout << "\033[3J\033[2J\033[H";

    }

};