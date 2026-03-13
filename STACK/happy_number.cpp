class Solution {
public:
    int sq(int n)
    {
        int x=0;
        while(n>0)
        {
            int y=(n%10)*(n%10);
            x=x+y;
            n=n/10;
        }
        return x;
    }

    bool isHappy(int n) {
        unordered_map<int,int> m;
        while(true)
        {
            if(m[n]==0 && n!=1)
            {
                m[n]=1;
                n=sq(n);
            }
            else if(m[n]!=0 && n!=1)
            {
                return false;
                break;
            }
            else if(n==1)
            {
                return true;
                break;
            }
        }



    }

};