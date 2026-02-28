#pragma once

#include <iostream>


class clsStringHelpers {

public:

    static std::string RemoveAllOccurencesOfSubString(std::string str, const std::string& SubStringToRemove){

        size_t Pos {std::string::npos};

        while ((Pos = str.find(SubStringToRemove)) != std::string::npos)
            str.erase(Pos, SubStringToRemove.size());
        
        return str;
    }
    

};