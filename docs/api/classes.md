# Classes

This section documents the primary public classes exposed by EasyMenu.

EasyMenu

- Purpose: High-level class that represents a console menu. Create an instance, add items, optionally customize header/footer, and call `RunMenu()` to present the menu to the user.
- Header file: `EasyMenu.h`
- Constructors:
  - `EasyMenu()` — creates an empty menu with no default header or footer.
  - `EasyMenu(const std::string& MenuLabel)` — creates a menu pre-configured with a default header showing `MenuLabel` and a default footer.
- Important public methods:
  - `unsigned int RunMenu(unsigned int ItemToStartFrom = 1)`
    - Shows the menu and returns the 1-based index of the selected item.
    - `ItemToStartFrom` controls which item will be highlighted when the menu opens.

  - `void AddItem(const std::string& Label, bool Active = true, bool Visible = true)`
    - Append a new item with label text. By default the item is active and visible.

  - `bool UpdateItem(size_t ItemNumber, const std::string& Label, bool Active = true, bool Visible = true)`
    - Update the item at index `ItemNumber` (1-based). Returns `true` if the item was updated.

  - `bool RemoveItem(size_t ItemNumber)`
    - Remove the item at index `ItemNumber`. Returns `true` on success.

  - `bool SetVisibility(size_t ItemNumber, bool Visible)`
    - Show or hide an item.

  - `bool SetActivity(size_t ItemNumber, bool Active)`
    - Make an item selectable (`Active=true`) or not.

  - `void ClearItems()` — remove all items.
  - `void ClearHeader()` — remove any header.
  - `void ClearFooter()` — remove any footer.
  - `void ClearMenu()` — clear header, footer and items.

  - `void SetHeader(const EasyMenuComponents::clsEasyMenuHeader& Header)`
    - Set a custom header object. The `EasyMenuComponents` header exposes component types used for customization.

  - `const EasyMenuComponents::clsEasyMenuHeader& GetHeader() const`
    - Retrieve the current header instance (read-only reference).

  - `void SetFooter(const EasyMenuComponents::clsEasyMenuFooter& Footer)`
    - Set a custom footer object.

  - `const EasyMenuComponents::clsEasyMenuFooter& GetFooter() const`

  - `size_t GetNumberOfItems() const` — returns the number of items (including hidden/inactive items).
  - `bool IsEmpty() const` — `true` if there are no items.

Typical usage example

```cpp
#include <iostream>
#include <EasyMenu.h>

int main() {
    EasyMenu menu("Main Menu");
    menu.AddItem("New");
    menu.AddItem("Open");
    menu.AddItem("Exit");

    unsigned int selected = menu.RunMenu();
    std::cout << "User selected: " << selected << std::endl;
}
```

Notes
- The class returns selection indices starting at 1.
- Header/footer objects are available through `EasyMenuComponents` if you need to present custom header/footer content. The library ships component headers under `include/` but those components are primarily UI helpers — for simple use you do not need to construct headers or footers.
