 # EasyMenu

 Lightweight, header-only C++ console menu library (Windows / POSIX).

 EasyMenu provides a minimal, dependency-free API to create interactive console menus with headers, footers, and selectable items. It uses a small platform abstraction so it works on Windows and POSIX terminals.

 ## Features
 - Simple programmatic API: create menus, add/update/remove items.
 - Default header/footer generators for quick setup.
 - Paginated rendering that adapts to terminal size.
 - Cross-platform terminal handling via a small `IPlatform` abstraction.

 ## Quick Start

 1. Include the headers from the `Include` folder in your project.
 2. Build with your usual C++ toolchain. Example (MinGW/GCC):

 ```bash
 g++ Example.cpp -o Example.exe -I Include
 ```

 3. Minimal usage example:

 ```cpp
 #include "EasyMenu.h"
 #include "EasyMenuComponents.h"
 #include <iostream>

 int main() {
     EasyMenu menu("Main Menu");

     menu.AddItem("Option 1");
     menu.AddItem("Option 2");
     menu.AddItem("Quit");

     unsigned int selection = menu.RunMenu(); // returns 0 if empty / not navigable

     if (selection > 0) std::cout << "Selected item: " << selection << '\n';
     else std::cout << "No selection (menu empty or not navigable)." << '\n';

     return 0;
 }
 ```

 ## API Overview

 - `EasyMenu` — High-level facade. Common methods:
   - `AddItem(Label, Active = true, Visible = true)`
   - `UpdateItem(number, Label, Active, Visible)`
   - `RemoveItem(number)`
   - `RunMenu(startItem = 1)` — Shows menu and returns selected item index (1-based), or `0` when empty/not navigable.

 - `EasyMenuComponents` namespace — Visual components:
   - `clsEasyMenuHeader` — header block; use `GetDefaultHeader(label)` to get a default header.
   - `clsEasyMenuFooter` — footer block; `GetDefaultFooter()` for a default footer.
   - `clsEasyMenuItem` — individual item with `IsActive()` / `IsVisible()` / `IsNavigable()`.

 - `clsMenu` — Internal menu model: holds label, header/footer, and items. Methods for modifying items and blocks.

 - `clsNavigator` / `clsRenderer` — Navigation and rendering engines used by `EasyMenu::RunMenu`.

 - `IPlatform` and platform implementations:
   - `IPlatform` — abstract terminal interface (`ReadKey`, `ClearScreen`, `GetTerminalSize`, etc.).
   - `clsWindowsPlatform` — Windows console implementation (uses `SetConsoleTextAttribute`, `_getch`, etc.).
   - `clsPOSIXPlatform` — POSIX implementation (uses `termios`, `ioctl`, ANSI escape sequences).

 For the full set of headers see the `Include` folder: [Include](Include).

 ## Behavior & Notes
 - Item numbering: public API uses 1-based item numbers. Internally zero-based indices are used.
 - Navigation returns `0` when the menu is empty or contains no navigable items.
 - Rendering adapts to terminal size and pages items when they don't fit.
 - ANSI sequences are used on POSIX for cursor visibility and highlighting; Windows uses native console APIs.

 ## Files of interest
 - [Include/EasyMenu.h](Include/EasyMenu.h) — public facade.
 - [Include/EasyMenuComponents.h](Include/EasyMenuComponents.h) — re-exports components used by callers.
 - [Include/Core/MenuUtils/clsMenu.h](Include/Core/MenuUtils/clsMenu.h) — menu model.
 - [Include/Core/MenuUtils/clsNavigator.h](Include/Core/MenuUtils/clsNavigator.h) — input loop and navigation.
 - [Include/Core/MenuUtils/clsRenderer.h](Include/Core/MenuUtils/clsRenderer.h) — rendering logic.
 - [Include/Core/Platform/PlatformFactory.h](Include/Core/Platform/PlatformFactory.h) — platform selection.

 ## Extending & Customization
 - You can replace the header/footer or build custom `clsEasyMenuHeader` / `clsEasyMenuFooter` content and assign it via `SetHeader` / `SetFooter`.

 ## Contributing
 - Open an issue with a short description and a minimal repro.
 - Pull requests should be focused and include small, testable changes.

 ## License


 ---
