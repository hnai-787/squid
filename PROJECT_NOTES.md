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
