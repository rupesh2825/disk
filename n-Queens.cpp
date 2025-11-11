#include <bits/stdc++.h>
using namespace std;
// Check if it's safe to put a queen at (row, col)
// given current placements in `pos` where pos[i] = column of queen in row i or -1 if
none.
bool isSafe(const vector<int>& pos, int row, int col, int n) {
for (int r = 0; r < n; ++r) {
int c = pos[r];
if (c == -1) continue; // no queen in that row yet
if (c == col) return false; // same column
if (abs(r - row) == abs(c - col)) return false; // same diagonal
}
return true;
}
// Backtracking to place queens row by row.
// Returns true when a solution is found (first solution).
bool solveNQueens(int row, vector<int>& pos, int n, int fixed_row) {
if (row == n) {
// All rows processed -> solution found
return true;
}
// If this row already has a fixed queen, skip placing and move to next row
if (pos[row] != -1) {
return solveNQueens(row + 1, pos, n, fixed_row);
}
// Try all columns in this row
for (int col = 0; col < n; ++col) {
if (isSafe(pos, row, col, n)) {
pos[row] = col;
if (solveNQueens(row + 1, pos, n, fixed_row)) return true;
pos[row] = -1; // backtrack
}
}
// No column worked in this row -> backtrack
return false;
}
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n;
cout << "Enter n (board size): ";
if (!(cin >> n) || n <= 0) {
cerr << "Invalid n\n";
return 1;
}
int r, c;
cout << "Enter row and column (1-based) for the already placed first queen: ";
cin >> r >> c;
// convert to 0-based
int fixed_row = r - 1;
int fixed_col = c - 1;
if (fixed_row < 0 || fixed_row >= n || fixed_col < 0 || fixed_col >= n) {
cerr << "Invalid fixed queen position\n";
return 1;
}
// pos[row] = column index of queen in that row, or -1 if none
vector<int> pos(n, -1);
pos[fixed_row] = fixed_col;
// Quick validation: ensure fixed queen alone is not contradictory (trivial)
// Now try to solve
bool found = solveNQueens(0, pos, n, fixed_row);
if (!found) {
cout << "No solution exists with the first queen at (" << r << "," << c << ").\n";
return 0;
}
// Print final n-queen matrix: 1 for queen, 0 for empty
cout << "\nFinal " << n << "x" << n << " n-Queens matrix (1 = queen):\n";
for (int i = 0; i < n; ++i) {
for (int j = 0; j < n; ++j) {
cout << (pos[i] == j ? 1 : 0) << (j + 1 == n ? "" : " ");
}
cout << '\n';
}
return 0;
}
