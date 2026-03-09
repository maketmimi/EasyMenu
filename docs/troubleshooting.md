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

3) Menu does not display correctly on the console

- Symptom: layout is broken, control characters appear, or input doesn't work as expected.
- Fixes:
  - Ensure your terminal supports ANSI escape sequences. On Windows, use a terminal that supports ANSI (Windows 10+ terminals or configure the console), or run under an environment (e.g., Git Bash, Windows Terminal).
  - Try running the example `docs/examples/SimpleMenu.cpp` to verify environment behavior.

4) Items not selectable or off-by-one selection

- Remember that `RunMenu()` returns a 1-based index. If you store items in a 0-based container, adjust accordingly when mapping selections to your data.

5) I want to customize headers/footers

- Include `EasyMenuComponents.h` to access header/footer types. These components are provided for customizing appearance. For most uses, the default header and footer are sufficient.

If you run into other issues, please open an issue with a minimal reproducer (the source file, compile command, and runtime environment details) so the problem can be investigated.
