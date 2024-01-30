class Solution {
public:
    vector<string> ans;
    vector<string> map = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    string s;
    vector<string> letterCombinations(string digits) {
        ans.clear();
        s.clear();
        if (digits.size() == 0) {
            return ans;
        }
        backtracking(digits, 0);
        return ans;
    }

    void backtracking(string &digits, int level) {
        if (level == digits.size()) {
            ans.push_back(s);
            return;
        }
        for (auto &c : map[digits[level] - '0']) {
            s.push_back(c);
            backtracking(digits, level + 1);
            s.pop_back();
        }
    }

};