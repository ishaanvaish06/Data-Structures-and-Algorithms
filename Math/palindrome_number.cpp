class Solution {
public:
    int reverse(int x) {
        int rev=0;
        while(x!=0) {
            if(rev <= INT_MAX/10 && rev >= INT_MIN/10)
            {
                rev=rev*10 + (x%10);
                x=x/10;
            }
            else
            {
                return 0;
            }
        }
        return rev;
    }
};