class Solution {
public:
    int longestPalindrome(string s) {
        int odd=0;
        unordered_map<int,int> m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
            if(m[s[i]]%2==1)
            {
                odd++;
            }
            else
            {
                odd--;
            }
        }
        if(odd>1) return s.size()-odd+1;
        return s.size();
    }
};