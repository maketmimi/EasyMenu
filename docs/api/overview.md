# API Overview

Public headers
- `EasyMenu.h` — Primary API class `EasyMenu` used to create and run menus.
- `EasyMenuComponents.h` — Convenience header that exposes optional UI components (header/footer). These components are provided for customization; consult the header for names and inclusion.

The public API is intentionally small. The recommended headers to include in your application are:

```cpp
#include <EasyMenu.h>
#include <EasyMenuComponents.h> // optional, only if you need custom headers/footers
```

Use `EasyMenu` for the common menu lifecycle: create, add items, run.
