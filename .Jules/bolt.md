# Bolt's Journal - Critical Performance Learnings

## 2026-03-29 - Initializing Journal
**Learning:** Initializing the journal for the STNM3K project to track performance optimizations.
**Action:** Follow the Bolt's process for identifying and implementing performance improvements.

## 2026-03-29 - Reducing `printf` Overhead in CLI Rendering
**Learning:** Replacing a nested character-by-character `printf` loop with bulk output using static filler strings and the `%.*s` format specifier significantly reduces system call overhead. In a benchmark of 100,000 iterations, this optimization yielded approximately a 7.4% reduction in execution time.
**Action:** Prioritize bulk output techniques (like `%.*s`) over character loops when rendering repeating symbols in CLI tools to improve both performance and code readability.
