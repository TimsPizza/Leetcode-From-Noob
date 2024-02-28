class Solution {
 public:
  unordered_set<char> row_set[9];
  unordered_set<char> col_set[9];
  unordered_set<char> grid_set[9];
  int pos_to_fill = 0;
  void solveSudoku(vector<vector<char>>& board) {
    // init set
    for (int r = 0; r < 9; ++r) {
      for (int c = 0; c < 9; ++c) {
        if (board[r][c] == '.') {
          pos_to_fill++;
          continue;
        }
        row_set[r].insert(board[r][c]);
        col_set[c].insert(board[r][c]);
        grid_set[getGridIndex(r, c)].insert(board[r][c]);
      }
    }
    // start backtracking
    backtracking(board);
  }

  bool backtracking(vector<vector<char>>& board) {
    // return true if found an answer
    if (pos_to_fill == 0) {
      return true;
    }
    for (int r = 0; r < 9; ++r) {
      for (int c = 0; c < 9; ++c) {
        if (board[r][c] != '.') {
          continue;
        }
        for (char k = '1'; k <= '9'; ++k) {
          if (isValidMove(r, c, k)) {
            board[r][c] = k;
            row_set[r].insert(k);
            col_set[c].insert(k);
            grid_set[getGridIndex(r, c)].insert(k);
            pos_to_fill--;
            if (backtracking(board)) {
              return true;
            }
            pos_to_fill++;
            board[r][c] = '.';
            row_set[r].erase(k);
            col_set[c].erase(k);
            grid_set[getGridIndex(r, c)].erase(k);
          }
        }
        return false;
      }
    }
    return true;
  }

  int getGridIndex(int r, int c) { return (r / 3) * 3 + (c / 3); }

  bool isValidMove(int r, int c, int val) {
    if (r < 0 || r >= 9 || c < 0 || c >= 9) {
      return false;
    }
    if (row_set[r].find(val) != row_set[r].end()) {
      return false;
    }
    if (col_set[c].find(val) != col_set[c].end()) {
      return false;
    }
    if (grid_set[getGridIndex(r, c)].find(val) !=
        grid_set[getGridIndex(r, c)].end()) {
      return false;
    }
    return true;
  }
};
