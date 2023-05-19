class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_size = s.length(), t_size = t.length();
        if(s_size != t_size)
        {
            return false;
        }
        int hash[26] = {0};
        for(int i = 0; i < s_size; ++i)
        {
            hash[s[i] - 97]++;
        }
        for(int i = 0; i < s_size; ++i)
        {
            hash[t[i] - 97]--;
            if(hash[t[i] - 97] < 0)
            {
                return false;
            }
        }
    return true;
    }
};