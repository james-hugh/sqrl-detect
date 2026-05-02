## 2026-05-02 - Printf Consolidation in C Rendering Loops
**Learning:** Consolidating multiple `printf` calls into a single call with precision specifiers (`%.*s`) and static buffers significantly reduces formatting overhead and system call frequency in high-frequency rendering loops.
**Action:** Use `%.*s` with pre-allocated static buffers for ASCII bar/graph rendering instead of per-character loops.

## 2026-05-02 - Static Const Array for Constant String Data
**Learning:** Declaring local string arrays as `static const char* const` moves the data to the read-only section of the binary, preventing redundant stack initialization on every function call.
**Action:** Always use `static const` for fixed lookup tables or message arrays in C.
