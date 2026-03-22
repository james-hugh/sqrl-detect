## 2026-03-21 - Unexpected Overhead in printf Formatting
**Learning:** Using `printf("%.*s")` for high-frequency rendering of small buffers (e.g., < 20 characters) can be significantly slower than a manual character loop or `fwrite`. This is due to the overhead of parsing the format string and dynamic precision in `printf`.
**Action:** Prefer `fwrite` or `fputs` for block writes of known lengths to bypass the `printf` formatting engine in hot paths.
