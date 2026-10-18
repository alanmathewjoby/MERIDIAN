# MERIDIAN — Initial Project Specification

## Purpose
MERIDIAN is a timetable optimization and scheduling system. The initial goal is a reliable, testable small-scale scheduling core, with room to add natural-language schedule changes later.

## Current baseline
The repository currently contains a small Java backtracking example in `filling_logic`. It fills a 3×3 grid with subject counts and prevents a subject from repeating in the same row. This is a learning prototype, **not yet a complete college timetable solver**.

## MVP
- Represent classes, subjects, teachers, rooms, periods, and fixed sessions in explicit data structures.
- Generate or validate a timetable for a small test case.
- Detect teacher/room/class clashes and report why a timetable is invalid.
- Preserve fixed sessions and required subject frequencies.
- Provide deterministic tests with known valid and invalid cases.
- Keep the core independent from any LLM or UI.

## Next stage (not required for the first MVP)
- Parse natural-language requests such as teacher absence or a period swap into a structured command.
- Validate the command and ask for clarification when date, teacher, class, or time is ambiguous.
- Ask the scheduler for a proposed change, validate all hard constraints, and show a preview before a person approves it.
- Add persistent storage and an interface.

## Non-goals for the first MVP
- Solving the entire college timetable immediately.
- Letting an LLM directly edit or apply a timetable without validation.
- Claiming a schedule is valid based only on visual inspection.
- Optimizing for speed before correctness and reproducible tests.

## Acceptance criteria for the first MVP
1. A documented sample input can be loaded.
2. The engine returns a valid schedule or a clear failure result.
3. Automated tests verify class, teacher, and room clash rules that are in scope.
4. Fixed sessions and subject counts are checked by code.
5. A new contributor can run the example and tests using the README instructions.
