
class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
    {
        for (int row = mat.size() - 1; row > 0; --row) {
            auto arr = get_arr(mat, 0, row);
            apply_change(mat, arr, 0, row);
        }
        for (int col = 0; col < mat[0].size();++col) {
            // sorting the disgonal line starts at mat[0][i]
            auto arr = get_arr(mat, col, 0);
            apply_change(mat, arr, col, 0);
        }
        return mat;
    }
    void apply_change(vector<vector<int>>& orig, vector<int> sorted_arr, int col_index, int row_index) {
        int col = col_index;
        // for (int row = row_index; row < orig.size() && col < orig[0].size(); ++row, ++col) {
        //     orig[row][col] = sorted_arr[row];
        // }
        for(auto num : sorted_arr){
            orig[row_index][col_index] = num;
            ++col_index, ++row_index;
        }
    }
    vector<int> get_arr(vector<vector<int>>& mat, int col_orig, int row_orig) {
        auto res = new vector<int>();
        for (int row = row_orig; col_orig < mat[0].size() && row < mat.size(); ++row, ++col_orig) {
            res->push_back(mat[row][col_orig]);
        }
        sort(res->begin(), res->end());
        return *res;
    }
};