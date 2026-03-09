# Troubleshooting

This page covers common issues when using EasyMenu and how to resolve them.

1) Compiler cannot find `EasyMenu.h`

- Symptom: the compiler outputs an error like `fatal error: EasyMenu.h: No such file or directory` or `cannot open source file "EasyMenu.h"`.
- Cause: the compiler's include path does not point to the `include/` folder of the library.
- Fix: add the include path.

  - g++: compile with `-I` pointing to the `include/` folder:

    ```bash
    g++ main.cpp -I path/to/EasyMenu/include
    ```

  - Visual Studio: either copy the `include/` folder into your project or add it under `Project → Properties → C/C++ → General → Additional Include Directories`.

2) Linker errors (undefined references)

- Symptom: unresolved externals at link time.
- Cause: EasyMenu is header-driven; unresolved externals typically come from other sources (e.g., mixing declaration-only headers with missing .cpp files). Ensure you are compiling all project source files and not omitting required translation units. EasyMenu itself does not require additional library linking.

3) Console Layout Issues

If the menu layout appears broken, misaligned, or does not render correctly, the problem is usually related to the **terminal environment**, not the library itself.

**EasyMenu has been tested in the following environments:**

* Windows **CMD** terminal (Windows 7 and Windows 10)
* **Windows Terminal**
* **PowerShell**
* Linux terminal environments (bash, etc.)
* macOS Terminal

These environments render the interface correctly.

On Windows, the library **does not rely on ANSI escape codes**, which helps maintain compatibility with older systems such as Windows 7.

However, the **VS Code integrated terminal** may sometimes display incorrect layout or cursor behavior when running console UI programs. Because of this, EasyMenu may not behave reliably inside the VS Code internal terminal on Windows.

If you encounter rendering issues, run your program in a **dedicated terminal window**, such as:

* CMD
* PowerShell
* Windows Terminal
* Linux terminal
* macOS Terminal

**Note:** The VS Code integrated terminal works correctly when running inside a **Linux environment**, where it has been tested and verified to function properly.


4) Items not selectable or off-by-one selection

- Remember that `RunMenu()` returns a 1-based index. If you store items in a 0-based container, adjust accordingly when mapping selections to your data.

5) I want to customize headers/footers

- Include `EasyMenuComponents.h` to access header/footer types. These components are provided for customizing appearance. For most uses, the default header and footer are sufficient.

If you run into other issues, please open an issue with a minimal reproducer (the source file, compile command, and runtime environment details) so the problem can be investigated.
