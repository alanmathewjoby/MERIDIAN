# MERIDIAN — Architecture and Module Contracts

## High-level flow
```text
Input / UI
   |
   v
Optional natural-language parser
   |  structured command + validation
   v
Scheduling engine <---- timetable + constraints
   |
   v
Candidate schedule
   |
   v
Independent validator
   |
   v
Preview -> human approval -> apply and record change
```

The parser is optional for the first MVP. The scheduling engine and validator must work without an LLM.

## Three parallel workstreams

### A — Scheduling engine
Owns the timetable representation, constraints, generation/search strategy, and solver tests. Start with a small, explicit problem instance. Avoid naive exhaustive search over the full college timetable.

### B — Command parsing and validation
Owns natural-language examples, parser interface, structured command validation, and clarification cases. Initially use a stub/mock parser if no model is ready. Do not make the solver depend on a particular LLM provider.

### C — App, data and integration
Owns sample data, input/output, timetable display, serialization, and the integration path. Provide mock inputs and outputs early so the other workstreams can integrate without waiting.

## Shared contract (initial draft)
Keep this contract small until the team agrees to it.

**Scheduling request**
- `requestId`: stable identifier
- `operation`: e.g. `GENERATE`, `VALIDATE`, `TEACHER_UNAVAILABLE`, `SWAP_PERIODS`
- `date`: ISO date when the operation is date-specific
- `parameters`: operation-specific validated fields
- `constraintsToPreserve`: named hard constraints

**Scheduling result**
- `status`: `SUCCESS`, `NO_SOLUTION`, or `INVALID_REQUEST`
- `proposedChanges`: list of proposed changes; empty when none
- `violations`: machine-readable constraint violations
- `explanation`: human-readable result

Do not treat this draft as a final API until the team agrees and adds examples/tests. Prefer typed Java classes/enums if the team stays with Java; do not duplicate the same contract in multiple inconsistent forms.

## Hard constraints vs preferences
- **Hard constraints:** must never be violated (e.g. a teacher cannot teach two classes in the same period; fixed labs cannot move).
- **Preferences:** desirable but negotiable (e.g. fewer gaps, balanced workload).
- If no valid schedule exists, return a clear failure or conflict explanation. Never silently violate a hard constraint to force an answer.

## Testing and integration
- Each module has unit tests.
- Integration tests use a small shared fixture checked into the repository.
- Every proposed schedule is run through an independent validator.
- Test impossible inputs, missing fields, duplicates, and edge cases—not only happy paths.
