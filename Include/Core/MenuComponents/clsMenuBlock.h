#pragma once

#include <iostream>
#include <vector>


namespace EasyMenuComponents{

    class clsMenuBlock{
    
        std::vector<std::string> _Lines {};
    
    public:
    
        void AddLine(const std::string& Line){
    
            _Lines.emplace_back(Line);
    
        }
    
        // Line number starting from 1    
        bool UpdateLine(size_t LineNumber, const std::string& NewLine){
    
            LineNumber--;
    
            if (LineNumber >= _Lines.size()) return false;
    
            _Lines.at(LineNumber) = NewLine;
    
            return true;
        }
    
        // Line number starting from 1
        bool RemoveLine(size_t LineNumber){
    
            LineNumber--;
    
            if (LineNumber >= _Lines.size()) return false;
    
            _Lines.erase(_Lines.begin() + LineNumber);
    
            return true;
        }
    
        void ClearLines(){
    
            _Lines.clear();
    
        }
    
        const std::vector<std::string>& GetVLines() const{

            return _Lines;

        }
    
        size_t GetNumberOfLines() const {

            return _Lines.size();

        }

    };

}
