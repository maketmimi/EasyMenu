# Functions

The public API exposed in the top-level headers is primarily class-based. There are no standalone utility functions intended for direct use by library consumers in the public headers — the `EasyMenu` class is the primary entrypoint.

If you need low-level helpers they may exist in internal headers; those are considered implementation details and are not supported as part of the public API.
