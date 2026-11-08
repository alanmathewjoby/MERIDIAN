```cpp
#include <iostream>
#include <string>
using namespace std;

const string SUBJECTS[] = {"Maths", "DS", "Java", "Library"};
int COUNTS[] = {3, 2, 2, 2};

const int ROWS = 3;
const int COLS = 3;


// Function to check whether placing a subject is valid
bool isValid(string grid[ROWS][COLS], int row, int col, string subject) {

    // Constraint 1: Cannot match the immediate left neighbour
    if (col > 0 && grid[row][col - 1] == subject)
        return false;

    // Constraint 2: Cannot repeat a subject in the same row
    for (int c = 0; c < col; c++) {
        if (grid[row][c] == subject)
            return false;
    }

    return true;
}


// Main recursive function to fill the timetable
bool fillTimetable(string grid[ROWS][COLS], int row, int col) {

    // Base case: All rows have been filled
    if (row == ROWS)
        return true;

    // Move to the next row if the current row is full
    if (col == COLS)
        return fillTimetable(grid, row + 1, 0);

    // Try every available subject
    for (int i = 0; i < 4; i++) {

        string subject = SUBJECTS[i];

        if (COUNTS[i] > 0 && isValid(grid, row, col, subject)) {

            // Place the subject
            grid[row][col] = subject;

            // Decrease its remaining count
            COUNTS[i]--;

            // Recursively move to the next cell
            if (fillTimetable(grid, row, col + 1))
                return true;

            // Backtracking: Undo the previous placement
            grid[row][col] = "";

            // Restore the subject count
            COUNTS[i]++;
        }
    }

    // No valid subject found, trigger backtracking
    return false;
}


// Function to print the timetable
void printMatrix(string grid[ROWS][COLS]) {

    for (int i = 0; i < ROWS; i++) {

        cout << "Day " << i + 1 << ": ";

        for (int j = 0; j < COLS; j++) {
            cout << grid[i][j] << " ";
        }

        cout << endl;
    }
}


// Main function
int main() {

    string grid[ROWS][COLS];

    if (fillTimetable(grid, 0, 0)) {

        cout << "--- CS ALPHA TIMETABLE ---" << endl;
        printMatrix(grid);

    } else {

        cout << "No valid timetable found matching constraints." << endl;
    }

    return 0;
}
```

**What I've preserved from your Java implementation:**

- All 4 subjects and their original counts.
- 3 × 3 timetable structure.
- Both original constraints.
- Recursive cell-by-cell filling.
- Backtracking (undoing placements and restoring counts).
- Base case and failure handling.
- Timetable printing.

**One implementation difference:** Java's `HashMap` has been replaced with a simple integer array (`COUNTS[]`). The subject at index `i` corresponds to its remaining count at index `i`. This is simpler and perfectly sufficient here.

This is functionally equivalent to your original Java algorithm, not a redesigned scheduler.
