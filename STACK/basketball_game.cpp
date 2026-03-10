class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> res;
        for(string x: operations)
        {
            
            
            if(x=="C")
            {
                res.pop_back();
            }
            else if(x=="D")
            {
                if(res.size()>0)
                {
                    res.push_back((res[res.size()-1])*2);
                }
                else
                {
                    res.push_back(0);
                }
            }
            else if(x=="+")
            {
                if(res.size()>=2)
                {
                    res.push_back(res[res.size()-1] + res[res.size()-2]);

                }
                else
                {
                    if(res.size()==0)
                    {
                        res.push_back(0);
                    }
                    else
                    {
                        res.push_back(res[res.size()-1]);
                    }
                }
            }
            else
            {
                res.push_back(stoi(x));
            }
        }
        int sum=0;
        for(int i=0;i<res.size();i++)
        {
            sum=sum+res[i];
        }
        return sum;
        
    }
};