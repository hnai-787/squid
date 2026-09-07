# Competition Scheduler

## Course Information

| Field | Details |
|---|---|
| Course | Data Structures (CS216) |
| Semester | Semester 3 — Fall 2024 |
| University | Air University, Islamabad |
| Students | Syed Jazib Ali Rizvi (232145), Hussain Ali (232095), Muhammad Abdullah Haroon (232992) |

## Overview

Schedules a 16-team competition bracket (Preliminary → Round 2 →
Semi-Finals → Final, 15 matches total) using a binary search tree for team
ranking and a queue for match ordering. Exists in three implementations
that evolved over the project: an original C++/CLI + WinForms app, a
portable header-only C++ class library, and a "reformed" native
DLL + separate WinForms frontend architecture.

## Problem Statement

Apply core data structures (BST, queue) to a real scheduling problem —
ranking teams and generating a fair, ordered match schedule for a
bracket-style competition.

## Objectives

- Model teams and matches with a BST (ranking) and queue (scheduling).
- Generate a complete, correctly-ordered bracket for 16 teams.
- Explore a cleaner architecture (native backend + separate UI) as a second pass.

## Tools and Technologies

- C++/CLI (Managed C++ + WinForms) — `original/`
- Plain C++ headers — `Classes/`
- C++ native DLL + C# .NET WinForms UI via P/Invoke — `reformed/`

## Features

- BST-based team ranking.
- Queue-based match scheduling across 4 bracket stages.
- Three parallel implementations showing the same logic at increasing levels of architectural cleanliness.

## Methodology

1. Implement the core `bst`/`match`/`queue`/`scheduler`/`team` logic (`Classes/`).
2. Build an original CLI+WinForms app around it (`original/CompetitionScheduler/CompetitionScheduler.sln`).
3. Refactor into a portable native DLL (`reformed/backend-cpp-dll/`) with a separate C# WinForms frontend (`reformed/frontend-csharp-winforms/`) communicating via P/Invoke.
4. Smoke-test the scheduler and capture the generated bracket output.

## Repository Structure

```text
competition-scheduler-cpp/
  README.md
  PROJECT_NOTES.md
  Classes/                          (bst.h, match.h, queue.h, scheduler.h, team.h)
  original/CompetitionScheduler/    (Visual Studio C++/CLI + WinForms solution, Main.cpp)
  reformed/
    backend-cpp-dll/                (native C++ DLL, build.bat)
    frontend-csharp-winforms/       (C# WinForms UI, Program.cs, team logos, teams.csv)
  shared-data/Teams.txt
  output/                           (smoke-matches.csv, smoke-logs.csv, smoke-report.html)
  docs/Report.docx
  project.yaml
```

## Setup Instructions

```bash
# Original (Visual Studio, Windows only):
# open original/CompetitionScheduler/CompetitionScheduler.sln and build

# Reformed backend:
cd reformed/backend-cpp-dll && build.bat

# Reformed frontend:
dotnet build reformed/frontend-csharp-winforms/CompetitionScheduler.UI.csproj
```

## Usage

```bash
# Original: run the built CompetitionScheduler.exe (Main.cpp, [STAThread])
# Reformed: run the C# WinForms UI, which P/Invokes CompetitionSchedulerBackend.dll
```

## How to Review

1. Start with this README, then `docs/Report.docx` for the full write-up.
2. Read `Classes/*.h` for the core data-structure logic.
3. Check `output/smoke-matches.csv` for a real generated bracket.
4. Compare `original/` vs `reformed/` to see the architectural evolution.

## Screenshots

Team logos and UI assets are under `reformed/frontend-csharp-winforms/Resources/`.

## Results

`output/smoke-matches.csv` shows a real generated 16-team bracket (Team
Alpha … Team Phoenix) scheduled across 2026-07-07 through 2026-07-21,
correctly progressing through Preliminary → Round 2 → Semi-Finals → Final,
with "Team Hunter" winning the Final in the smoke-test run.

## Limitations

- `shared-data/Teams.txt` uses real classmates'/friends' first names as
  fictional "team member" placeholders — harmless but worth knowing if you
  reuse this dataset.
- The three implementations (`original/`, `Classes/`, `reformed/`) overlap
  in purpose; they're kept side by side deliberately to show the project's
  evolution, not because all three are needed to run it.

## Future Enhancements

- Consolidate around the `reformed/` architecture and retire `original/`.
- Add automated tests around the scheduling logic instead of relying on smoke-test CSV output.

## Safety and Privacy

- No real secrets, credentials, or private keys are included.
- Team member names in `shared-data/Teams.txt` are used as fictional bracket data, not personal records.

## Ethical Notice

Academic coursework exercise; no ethical concerns apply.
