class Solution { //LEETCODE : SEARCH INSERT POSITION
public:            // BINARY SERARCH
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size();
        if(target>nums[r-1])
        {
            return r;
        }
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                r=mid-1;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
        }
        return l;
        

        
    }
};