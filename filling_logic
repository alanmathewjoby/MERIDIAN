import java.util.*;

public class CSAlphaTimetable {
    private static final String[] SUBJECTS = {"Maths", "DS", "Java", "Library"};
    private static final int[] COUNTS = {3, 2, 2, 2}; // Total 9 classes
    private static final int ROWS = 3;
    private static final int COLS = 3;

    public static void main(String[] args) {
        String[][] alphaGrid = new String[ROWS][COLS];
        Map<String, Integer> subjectsMap = new HashMap<>();
        
        for (int i = 0; i < SUBJECTS.length; i++) {
            subjectsMap.put(SUBJECTS[i], COUNTS[i]);
        }

        if (fillTimetable(alphaGrid, 0, 0, subjectsMap)) {
            System.out.println("--- CS ALPHA TIMETABLE ---");
            printMatrix(alphaGrid);
        } else {
            System.out.println("No valid timetable found matching constraints.");
        }
    }

    private static boolean fillTimetable(String[][] grid, int row, int col, Map<String, Integer> counts) {
        // foundation case: if we filled all rows, we are done
        if (row == ROWS) return true;
        
        // we basically move to the next row if the current row is fully filled, and only iffilled
        if (col == COLS) return fillTimetable(grid, row + 1, 0, counts);

        for (String subject : SUBJECTS) {
            if (counts.get(subject) > 0 && isValid(grid, row, col, subject)) {
                
                grid[row][col] = subject;
                counts.put(subject, counts.get(subject) - 1);

                // ivde we recurse to next cell
                if (fillTimetable(grid, row, col + 1, counts)) return true;

                // here....baacktrack if it fails down the line (simple backtracking without csp..to an extent)
                grid[row][col] = null;
                counts.put(subject, counts.get(subject) + 1);
            }
        }
        return false; // Trigger backtracking
    }

    private static boolean isValid(String[][] grid, int row, int col, String subject) {
        // this was kinda like.... one of the constraint 1: Can't match the immediate left neighbor (side-by-side)....
        if (col > 0 && subject.equals(grid[row][col - 1])) return false;
        
        // eda this part is like...constraint 2: can't repeat a class inside the same row....
        for (int c = 0; c < col; c++) {
            if (subject.equals(grid[row][c])) return false;
        }
        return true;
    }

    public static void printMatrix(String[][] grid) {
        for (int i = 0; i < ROWS; i++) {
            System.out.println("Day " + (i + 1) + ": " + Arrays.toString(grid[i]));
        }
    }
}
