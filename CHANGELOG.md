# Changelog

All notable changes to this project are documented here.
Format loosely follows [Keep a Changelog](https://keepachangelog.com/).

## [Unreleased]

### Added

### Changed

### Fixed

## [1.0.0] - 2026-09-08

### Added

- Rebuilt as **bracketsched**, a deterministic bracket-generation library,
  consolidating the three original parallel implementations (preserved
  unmodified under `archive/academic-original/`).
- Generalized from a fixed 16 teams to any team count >= 2.
- Real "inner-outer" (recursive reflection) seed placement algorithm,
  with automatic, mathematically-correct top-seed byes for
  non-power-of-two team counts (no separate bye-placement logic needed).
- Double elimination: winners/losers bracket topology with a named,
  documented "alternating" cross-bracketing policy, and a configurable
  Grand Final policy (`ResetIfNecessary` / `SingleMatch`).
- `BracketGraph` domain model: an immutable dependency graph of `Match`
  records with typed slot sources (participant / prior-match-winner /
  prior-match-loser / bye), replacing the original's BST + queue design.
- Deterministic structural match IDs and canonical (byte-identical for
  identical input) JSON serialization.
- A stable, JSON-based C ABI (`capi/bracketsched_capi.h`, built as
  `libbracketsched_capi.dll`), verified by compiling and running an
  independent external consumer program against it.
- A thin CLI (`bracket generate teams.json`).
- 25 Catch2 test cases / 391 assertions: seeding-sequence exactness,
  pair-sum and top-seed-separation invariants across many team counts,
  bye-assignment correctness, exact double-elimination round structure
  (hand-verified against a worked 8-team example), Grand Final
  conditional-match semantics, and a permanent regression test for the
  bye-propagation bug described below.

### Fixed

- The first version of the losers-bracket builder assumed each wave of
  winners-bracket losers is always the same size as the current
  losers-bracket population, which only holds when there are no byes.
  With byes present, some winners-bracket pairings produce no real loser
  at all, and the original code silently dropped those positions instead
  of letting them propagate as empty slots -- desynchronizing population
  sizes and losing a match entirely for any non-power-of-two team count
  under double elimination (caught immediately by the match-count
  invariant test for N=5). Fixed by making the internal `Source` type a
  true three-way case (participant / bye / prior-match-reference) and
  routing every pairing, in both brackets, through one shared bye-aware
  resolution function.
