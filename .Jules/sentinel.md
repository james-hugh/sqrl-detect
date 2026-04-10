## 2026-04-08 - Defensive Directory and File Creation
**Vulnerability:** Default file permissions can lead to sensitive log data leakage to other users on the same system.
**Learning:** Using `umask(0077)` before creating directories or files ensures that they are restricted to the owner by default, providing a "secure by default" environment.
**Prevention:** Always set a restrictive umask or use explicit permissions during file and directory creation for sensitive data.
