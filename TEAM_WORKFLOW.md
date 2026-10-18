# MERIDIAN — Three-Person Development Workflow

## Goal
Build MERIDIAN in small, testable increments without everyone editing the same files or waiting for one person to finish everything.

## Team roles (assign names in the first sync)
- **Person A — Scheduling engine:** timetable model, constraints, solver, validity checks.
- **Person B — Natural-language command layer:** turn a request into a validated, structured command; handle ambiguity and ask clarification questions.
- **Person C — App, data and integration:** input/output, timetable display, storage/import/export, and connecting the modules.
- **Integrator (rotates weekly):** reviews PRs, runs integration tests, and keeps `main` working. This is a duty, not a fourth person.

Everyone owns tests for their work. Roles can rotate, but every issue must have one owner.

## Rules of work
1. **Do not commit directly to `main`.** Use a short-lived feature branch and a pull request.
2. Keep PRs small and focused. One PR should solve one issue.
3. Agree on function signatures and data shapes before implementing modules in parallel.
4. Keep the default branch runnable. Merge only after review and relevant tests pass.
5. Never commit passwords, API keys, tokens, personal data, or large datasets.
6. AI-generated code is a draft: the author must understand it, run it, and test it.
7. If a task is blocked, write the exact blocker and a minimal reproducible example in the issue.

## Branch names
- `feat/<short-name>` — feature
- `fix/<short-name>` — bug fix
- `test/<short-name>` — tests
- `docs/<short-name>` — documentation

## Daily loop
- **Start (10 min):** each person states today's deliverable, files/interfaces touched, and blockers.
- **Build:** work independently against the agreed interfaces and mock data.
- **Integration checkpoint (15 min):** run tests and resolve contract mismatches early.
- **End (5 min):** report PR/commit, tests run, what works, what's blocked, and next step.

## Definition of done
A task is done only when:
- acceptance criteria are met;
- tests are added or updated and pass;
- no known hard-constraint violation is introduced;
- assumptions and user-visible behavior are documented;
- the PR has been reviewed and merged.

## First working session
1. Each teammate accepts one role and confirms availability.
2. Read `PROJECT_SPEC.md` and `ARCHITECTURE.md`.
3. Agree on the first MVP and freeze the shared command/timetable contracts.
4. Create one issue per deliverable, with a single owner and acceptance criteria.
5. Each person implements against mock data so parallel work can start immediately.
6. Integrate daily; do not wait until all three modules are "finished."

## Suggested MVP boundary
Start with one small class timetable and deterministic input data. Prove that the engine can create or validate a timetable and explain failure. Add natural-language rescheduling and a UI only after the engine contract and tests are stable. Expand to more classes after the small case is reliable.
