class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s=nums.size();
        int sum=0;
        for(int i=0;i<s;i++)
        {
            sum=sum+nums[i];
        }
        return (((s*(s+1))/2) - sum);

    }
};