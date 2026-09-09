# Project Notes

## Source

Migrated from `air-university-cybersecurity-projects/projects/competition-scheduler-cpp`
into this workspace as an independent project on 2026-09-07.

## Cleanup decisions

- `reformed/backend-cpp-dll/build/CompetitionSchedulerBackend.dll` and
  `libCompetitionSchedulerBackend.a` (compiled binaries) were **not**
  copied. Rebuild via `reformed/backend-cpp-dll/build.bat`.
- Everything else (three implementation variants, shared data, smoke-test
  output, docs) copied as-is.

## Assumptions

- `shared-data/Teams.txt` mixes real first names of classmates/friends into
  fictional bracket data. Per the user's decision to keep classmate
  attribution as-is in group-project docs, this was left unchanged — it's
  low-severity (first names only, used as placeholder team-roster data, not
  presented as real personal records).
- Group members in the course-info table are taken from `docs/Report.docx`.

## Remaining work

- The three implementation variants (`original/`, `Classes/`, `reformed/`)
  could eventually be consolidated; left as-is here since collapsing them
  would lose the visible progression from first draft to reformed
  architecture.

## 2026-09-08: Consolidated into bracketsched (deterministic bracket-generation library)

### What changed and why

The "remaining work" note above was acted on: all three variants are now
consolidated (archived unmodified under `archive/original/`)
into one library, generalized from a fixed 16 teams to any team count,
and reframed around a defensible library identity ("deterministic bracket
generation," not "yet another bracket app") following a research pass
that specifically corrected two assumptions from the original brief:
the seeding algorithm is "inner-outer" (recursive reflection), not
bit-reversal, and there is no single universal double-elimination
loser-drop algorithm across real tournament operators -- so the library
names and documents its policy (`alternating` cross-bracketing) instead
of hiding an implicit, unstated choice.

### Key engineering decisions and why

- **BST + Queue replaced with an immutable dependency graph.** A
  tournament bracket is a directed graph of match dependencies; a BST
  gives no advantage once entrants have unique seeds, and a queue doesn't
  model cross-round dependencies at all. `BracketGraph` (a flat list of
  `Match` records with typed slot sources) replaced both.
- **"Provably fair" was deliberately avoided** in favor of specific,
  testable invariants (top-seed separation, pair-sum, bye assignment) --
  the research surfaced a peer-reviewed impossibility result (Vu & Shoham
  2011) showing balanced knockout brackets can't satisfy every reasonable
  fairness definition simultaneously, so a narrower, provable claim is
  both more honest and more defensible.
- **A JSON-only C ABI, not a fully typed struct ABI**, to keep the
  cross-language boundary small and safe for v1 (documented trade-off,
  not a silent scope cut -- see README "Design decisions" and "Future
  Enhancements").
- **Reused the CMake + vcpkg (nlohmann-json, Catch2) toolchain** already
  set up for the other C++ projects in this workspace.

### A real bug found and fixed via the test suite

The first implementation of the losers-bracket builder assumed the
current losers-bracket population is always the same size as the next
incoming wave of winners-bracket losers. That's only true when the
bracket has no byes. With byes (any non-power-of-two team count), some
winners-bracket pairings are decided by a bye and produce no real loser
at all; the original code simply omitted those positions from the losers
-bracket population, which desynchronized it from the next wave's size
and silently dropped a match. The very first property test run (match
-count invariant across N=2..32 for double elimination) caught this
immediately for N=5 (7 matches generated instead of the required 8).
Fixed by making the internal `Source` representation a genuine three-way
type (participant / bye / prior-match-reference) and routing every single
pairing -- in both the winners and losers brackets, including
self-pairing and consolidation rounds -- through one shared bye-aware
`resolvePair` function, so an "empty" bracket position correctly keeps
propagating as a bye instead of vanishing. This is now a permanent
regression test (`tests/test_double_elimination.cpp`, the N=5 case).

### Verification performed

`cmake --build` and the full test suite (25 test cases / 391 assertions,
all passing) were actually run. The CLI was run against an 8-team
double-elimination example and its exact output (match-by-match) was
hand-compared against the research's own worked structural derivation --
it matches exactly, including the two conditional Grand Final matches.
The C ABI was independently verified by compiling and running a small
external C++ program that dynamically links `libbracketsched_capi.dll`
and calls `bracketsched_generate_json` across the DLL boundary -- this is
real, executed verification of the "embeddable" claim, not an assumption
based on the code compiling.

### Remaining work / honest limitations

See README "Limitations" and "Future Enhancements" -- notably: seeded
input only (no unseeded random-draw mode yet), JSON-only C ABI, only the
alternating cross-bracket policy, no differential testing against another
bracket library, and no CI pipeline run (not pushed to GitHub in this
task).
