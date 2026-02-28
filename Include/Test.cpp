#include <iostream>
#include "EasyMenu.h"
#include "EasyMenuComponents.h"

int main(){

    EasyMenu Menu1("Menu Test");

    EasyMenuComponents::clsEasyMenuHeader Header;
    EasyMenuComponents::clsEasyMenuFooter Footer;
    
    Footer.AddLine("+++++++++++++++++++++++++");
    Footer.AddLine("2/28/2026®");


    Header.AddLine("+++++++++++++++++++++++++");
    Header.AddLine("        Working");
    Header.AddLine("+++++++++++++++++++++++++");

    Menu1.SetHeader(Header);
    Menu1.SetFooter(Footer);

    Menu1.AddItem("Play");
    Menu1.AddItem("Settings");
    Menu1.AddItem("Exit");
   

    printf("\nItems number is : %i\n", Menu1.RunMenu());

    std::cin.get();
    return 0;
}