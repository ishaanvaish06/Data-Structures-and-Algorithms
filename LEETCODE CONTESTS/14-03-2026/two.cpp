class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long> p;
        int ma=nums[0];
        p.push_back(gcd(ma,nums[0]));
        for(int i=1;i<nums.size();i++)
        {
            ma=max(nums[i],ma);
            p.push_back(gcd(ma,nums[i]));

        }
        sort(p.begin(),p.end());
        int l=0;
        int r=p.size()-1;
        long long sum=0;
        while(l<r)
        {
            sum += gcd(p[l],p[r]);
            l=l+1;
            r=r-1;
        }
        return sum;
    }
};