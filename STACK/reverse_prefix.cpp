class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> s;
        string res;
        for(int i=0;i<word.size();i++)
        {
            if(s.size()==0)
            {
                s.push(word[i]);
            }
            else if(s.size()>0 && s.top()==ch)
            {
                break;
            }
            else if(s.size()>0 && s.top()!=ch)
            {
                s.push(word[i]);
            }
        }
        if(s.top()==ch) {
            for(int i=0;i<word.size();i++)
            {
                if(s.size()!=0)
                {
                    res.push_back(s.top());
                    s.pop();
                }
                else
                {
                    res.push_back(word[i]);
                }
            }
            return res;
        }
        return word;




    }
};