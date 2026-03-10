class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> x;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(x.empty())
            {
                x.push(s[i]);
            }
            else
            {
                if(x.top()==s[i])
                {
                    x.pop();
                }
                else
                {
                    x.push(s[i]);
                }
            }
        }
        string z="";
        while(x.size()!=0)
        {
            z.push_back(x.top());
            x.pop();
        }
        return z;

    }
};