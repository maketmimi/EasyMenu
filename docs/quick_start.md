# Quick Start

This quick start shows the minimal code required to create and display a menu using EasyMenu.

1. Include the header(s):

```cpp
#include <EasyMenu.h>
```

2. Create a menu, add items, and run it:

```cpp
#include <iostream>
#include <EasyMenu.h>

int main() {
    EasyMenu menu("Main Menu");

    menu.AddItem("Create new file");
    menu.AddItem("Open existing file");
    menu.AddItem("Exit");

    unsigned int choice = menu.RunMenu();
    std::cout << "Selected item: " << choice << std::endl;

    return 0;
}
```

Notes
- `RunMenu()` returns the 1-based index of the selected item.
- Use `AddItem()` to append items. Methods are provided to update, remove, or change visibility/activity of items.
