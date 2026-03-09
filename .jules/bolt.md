## 2025-05-15 - Graph Rendering Optimization
**Learning:** Replacing character-by-character loops with precision specifiers (%.*s) and static template strings in CLI-based visualizations significantly reduces CPU overhead by minimizing the number of 'printf' calls and internal buffering operations.
**Action:** Always look for nested loops that perform repetitive character output and replace them with single formatted string operations for measurable performance gains in CLI environments.

## 2025-05-15 - Environment Hygiene
**Learning:** Running 'make' and benchmarking scripts in the development environment can lead to compiled binaries and log files being automatically staged if not careful.
**Action:** Always verify 'git status' and manually unstage/remove build artifacts (e.g., binaries, temporary logs) before final submission to maintain repository cleanliness.
