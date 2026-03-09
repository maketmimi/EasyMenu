#include <iostream>
#include <EasyMenu.h>

int main() {
    // Create a menu with a label
    EasyMenu menu("Simple Menu");

    // Add a few items
    menu.AddItem("Say hello");
    menu.AddItem("Show version");
    menu.AddItem("Exit");

    // Run the menu. RunMenu returns a 1-based index of the selected item.
    unsigned int choice = menu.RunMenu();

    switch (choice) {
        case 1:
            std::cout << "Hello!" << std::endl;
            break;
        case 2:
            std::cout << "EasyMenu version: header-only" << std::endl;
            break;
        case 3:
            std::cout << "Goodbye." << std::endl;
            break;
        default:
            std::cout << "No selection or canceled." << std::endl;
    }

    return 0;
}
