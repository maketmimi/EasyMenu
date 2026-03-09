# EasyMenu

EasyMenu is a lightweight, header-only C++ library for creating interactive console menus on Windows and POSIX terminals. It provides a minimal, dependency-free API for building menus with headers, footers, selectable items and automatic pagination.

Why use EasyMenu

- Minimal and header-only — drop the headers into your project and build.
- Cross-platform terminal handling via a small `IPlatform` abstraction.
- Built-in rendering, paging and navigation — no external UI dependencies.

Quick start

- Build (example, MinGW/GCC):

```bash
g++ Example.cpp -o Example.exe -I Include
```

- Minimal usage:

```cpp
#include "EasyMenu.h"
#include "EasyMenuComponents.h"
#include <iostream>

int main() {
    EasyMenu menu("Main Menu");
    menu.AddItem("Start");
    menu.AddItem("Settings");
    menu.AddItem("Exit");
    unsigned int selection = menu.RunMenu(); // returns 1-based index, or 0
    if (selection > 0) std::cout << "Selected: " << selection << '\n';
    return 0;
}
```

API highlights

- `AddItem(label, active=true, visible=true)` — add a menu item.
- `UpdateItem(index, label, active, visible)` — modify an existing item.
- `RemoveItem(index)` — remove an item by 1-based index.
- `RunMenu(startItem=1)` — shows the menu, handles navigation input, and returns the selected 1-based index (returns `0` when no navigable items).
- `SetHeader(...)`, `SetFooter(...)` — provide custom header/footer blocks.

Behavior notes

- Public item indices are 1-based; internal storage is zero-based.
- Rendering adapts to terminal size and will paginate items that do not fit the view.

Platform support

- `clsWindowsPlatform` — native Windows console handling.
- `clsPOSIXPlatform` — POSIX support using ANSI sequences and `termios`.

Documentation & examples

- See the full documentation at [EasyMenu-Documentation](https://maketmimi.github.io/EasyMenu/).
- Full documentation is also avalible in the `docs/` folder. Open `docs/index.html` locally for the user guide, API reference and examples.

Files of interest

- Public API: [Include/EasyMenu.h](Include/EasyMenu.h) and [Include/EasyMenuComponents.h](Include/EasyMenuComponents.h)
- Core implementation: [Include/Core/MenuUtils/clsMenu.h](Include/Core/MenuUtils/clsMenu.h), [Include/Core/MenuUtils/clsNavigator.h](Include/Core/MenuUtils/clsNavigator.h), [Include/Core/MenuUtils/clsRenderer.h](Include/Core/MenuUtils/clsRenderer.h)

License

- See the project license at [LICENSE](LICENSE).

Contributing

- Open issues with a short description and a minimal reproduction.
- Pull requests should be focused and include small, testable changes. See [EasyMenu-Documentation](https://maketmimi.github.io/EasyMenu/) for more contribution guidance.

Support

- For questions or feature requests open an issue in this repository.

---
This README provides a concise overview and quick-start; see the documentation at [EasyMenu-Documentation](https://maketmimi.github.io/EasyMenu/) for complete details and examples.
