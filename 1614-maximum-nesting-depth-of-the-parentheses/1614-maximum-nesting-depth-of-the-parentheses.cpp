class Solution {
public:
   int maxDepth(string s)
    {
        int res = 0, ans = 0;
        auto it = s.begin();
        while(it != s.end()){
            if(*it == '('){
                ans = max(ans, ++res);
            }else if(*it == ')'){
                --res;
            }
            ++it;
        }
        return ans;
    }
};