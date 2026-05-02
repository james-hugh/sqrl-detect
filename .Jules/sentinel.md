# Sentinel Security Journal

This journal tracks critical security learnings and vulnerability patterns discovered in the STNM3K project.

## 2026-05-02 - Secure Memory Hygiene for Sensitive Inputs
**Vulnerability:** Sensitive user input (authentication prayer) remained in memory buffers after processing, potentially exposing credentials to memory-dump attacks or cold boot attacks.
**Learning:** Standard memory clearing can be optimized away by modern compilers if the buffer is not used after the wipe. Using a `volatile` pointer ensures the compiler performs the write operation.
**Prevention:** Implement a `secure_memzero` utility using `volatile` and ensure all sensitive buffers are wiped on every exit path, including errors and EOF.
