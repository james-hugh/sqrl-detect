# Bolt's Performance Journal

## 2026-04-20 - Initial Entry
**Learning:** Performance in terminal applications can be significantly impacted by the number of system calls, especially `write` calls triggered by `printf`.
**Action:** Consolidate multiple small `printf` calls into fewer, larger ones using formatted strings or buffers.
