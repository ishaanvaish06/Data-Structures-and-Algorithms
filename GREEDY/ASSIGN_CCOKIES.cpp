class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int x=min(g.size(),s.size());
        int l=0;
        int r=0;
        int count=0;
        while(l<s.size() && r<g.size())
        {
            if(g[r]<=s[l])
            {
                count++;
                r=r+1;
            }
            l=l+1;
        }
        return count;


    }
};