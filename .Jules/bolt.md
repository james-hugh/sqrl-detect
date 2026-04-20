## 2026-04-20 - [Optimizing ASCII Visualizations and Array Initialization]
**Learning:** Reducing the number of `printf` calls in loops by using static character buffers and precision specifiers (`%.*s`) can lead to measurable performance gains (~20% improvement in micro-benchmarks). Additionally, declaring local constant arrays as `static const` prevents unnecessary stack allocation and initialization on every function call.
**Action:** Always prefer batching output when possible and use the `static` keyword for local lookup tables or constant arrays that are frequently accessed.
