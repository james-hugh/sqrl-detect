## 2026-03-18 - TOCTOU and Insecure Defaults in Directory Initialization
**Vulnerability:** Use of a `stat` then `mkdir` check is susceptible to TOCTOU race conditions. Additionally, default permissions were too permissive.
**Learning:** Checking for directory existence with `stat` before calling `mkdir` can be exploited by an attacker who creates the directory between the two calls.
**Prevention:** Use an atomic `mkdir` call with a restrictive `umask` (e.g., 0077) and check the `errno` for `EEXIST`.
