#pragma once

#include <iostream>



class clsValidate {

public:

    template <typename T> static bool IsNumberBetween(T Number, T From, T To){

        return (Number >= From) && (Number <= To);

    }

};