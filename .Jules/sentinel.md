## 2026-04-08 - Secure Directory Creation and Umask
**Vulnerability:** Race conditions (TOCTOU) and overly permissive file permissions.
**Learning:** stat followed by mkdir is a race condition. Direct mkdir with errno == EEXIST check is safer. umask ensures all new files have safe default permissions.
**Prevention:** Use direct system calls and handle errors; set process-wide umask early.
