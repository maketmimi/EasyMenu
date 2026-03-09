# Installation

This page explains how to include and link the EasyMenu headers in common development setups. EasyMenu exposes its public API through the `include/` folder. The library is header-centric; you include the provided headers and compile your application normally.

GCC / g++ (Linux, Windows with MinGW, macOS)

- Basic compiler invocation (when your project file is `main.cpp`):

```cpp
g++ main.cpp -I path/to/EasyMenu/include
```

- Explanation: the `-I` flag tells the compiler to add `path/to/EasyMenu/include` to the search path for `#include` directives. This allows `#include <EasyMenu.h>` to find the header files shipped with EasyMenu.

- Minimal example:

```cpp
#include <EasyMenu.h>

int main() {
    EasyMenu menu("My Menu");
    menu.AddItem("Option 1");
    menu.AddItem("Option 2");
    unsigned int selection = menu.RunMenu();
    return 0;
}
```

- Typical project layout when cloning the repository:

```
MyProject/
  src/
    main.cpp
  include/         <-- copy or reference EasyMenu/include here (optional)
  libs/
  build/
```

Visual Studio (Windows)

Method 1 — Copy the `include/` folder into your project

- Place the `include/` folder inside your project directory. Example structure:

```
Project/
  main.cpp
  include/
    EasyMenu.h
    EasyMenuComponents.h
    ...
```

- Then include headers from your code using a relative path:

```cpp
#include "Include/EasyMenu.h"
```

Visual Studio automatically searches the project directory for headers.

Method 2 — Add the EasyMenu `include` folder to Additional Include Directories

1. Right-click your project and choose **Properties**.
2. Navigate to `C/C++ → General → Additional Include Directories`.
3. Add the path to the EasyMenu `include` folder (for example `C:\Libraries\EasyMenu\include`).

After adding the include path you can use:

```cpp
#include <EasyMenu.h>
```

When to use each method
- Copying `include/` into the project is simple and self-contained.
- Adding an include path is preferable if you share the library between multiple projects or keep it outside project folders.
