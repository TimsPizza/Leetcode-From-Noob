#define QUEEN 'Q'
#define FREE '.'
class Solution {
 public:
  bool row[9]              = {false};
  bool col[9]              = {false};
  bool checker_board[9][9] = {{false}};
  int n;
  int queens = 0;
  vector<vector<string>> ans;
  vector<vector<string>> solveNQueens(int n) {
    this->n = n;
    for (int i = 0; i < n; ++i) {
      row[0]              = 1;
      col[i]              = 1;
      checker_board[0][i] = 1;
      queens++;
      backtracking(0, i);
      queens--;
      // row[0]              = 0;
      col[i]              = 0;
      checker_board[0][i] = 0;
    }
    return ans;
  }

  void backtracking(int start_row, int start_col) {
    if (this->queens == n) {
      ans.push_back(generateAns());
      return;
    }
    if (start_row > n || start_col > n) {
      return;
    }
    auto new_row = start_row + 1;
    for (int new_col = 0; new_col < n; ++new_col) {
      if (isValidMove(new_row, new_col)) {
        this->row[new_row]                    = 1;
        this->col[new_col]                    = 1;
        this->checker_board[new_row][new_col] = 1;
        this->queens++;
        backtracking(new_row, new_col);
        this->queens--;
        this->row[new_row]                    = 0;
        this->col[new_col]                    = 0;
        this->checker_board[new_row][new_col] = 0;
      }
    }
  }

  bool isValidMove(int row_, int col_) {
    if (row_ < 0 || row_ >= this->n || col_ < 0 || col_ >= this->n) {
      return false;
    }
    // check col, row
    if (this->row[row_] || this->col[col_]) {
      return false;
    }
    // check diagonal
    int row_orig = row_;
    int col_orig = col_;
    --row_;
    --col_;
    for (; row_ >= 0 && col_ >= 0; --row_, --col_) {
      if (this->checker_board[row_][col_]) {
        return false;
      }
    }
    row_ = row_orig + 1;
    col_ = col_orig + 1;
    for (; row_ < n && col_ < n; ++row_, ++col_) {
      if (this->checker_board[row_][col_]) {
        return false;
      }
    }
    row_ = row_orig - 1;
    col_ = col_orig + 1;
    for (; row_ >= 0 && col_ < n; --row_, ++col_) {
      if (this->checker_board[row_][col_]) {
        return false;
      }
    }
    row_ = row_orig + 1;
    col_ = col_orig - 1;
    for (; row_ < n && col_ >= 0; ++row_, --col_) {
      if (this->checker_board[row_][col_]) {
        return false;
      }
    }
    return true;
  }
  vector<string> generateAns() {
    vector<string> vs;
    string s;
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < n; ++col) {
        if (checker_board[row][col]) {
          s.push_back(QUEEN);
          continue;
        }
        s.push_back(FREE);
      }
      vs.push_back(s);
      s.clear();
    }
    return vs;
  }
};