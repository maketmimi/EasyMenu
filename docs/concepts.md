# Concepts

EasyMenu focuses on a small set of concepts to keep console menus simple and portable.

- Menu: the logical container for items, header and footer. The `EasyMenu` class is the primary entry point.
- Item: a selectable entry in the menu. Items are ordered and indexed starting from 1.
- Header/Footer: optional visible UI blocks shown above or below the list of items. The `EasyMenuComponents` header exposes these components; they can be set on a menu if you need custom text or metadata.
- Visibility / Activity: items can be hidden (not shown) or made inactive (shown but not selectable).
- Platform abstraction: EasyMenu uses an internal platform layer to render and read input; you do not need to change platform-specific code to use the public API.

Typical flow

1. Create an `EasyMenu` instance (optionally with a label).
2. Add items with `AddItem()`.
3. Optionally customize header/footer (via `EasyMenuComponents`).
4. Call `RunMenu()` to run the interactive menu and get a selected item index.
