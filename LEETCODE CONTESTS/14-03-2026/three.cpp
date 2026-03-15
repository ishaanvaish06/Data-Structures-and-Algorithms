class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(int i=0;i<nums1.size();i++)
        {
            m[nums1[i]]+=1;
        }

        for(int j=0;j<nums2.size();j++)
        {
            m[nums2[j]]-=1;
        }

        int sw=0;
        for(auto &pair:m)
        {
            int v=pair.first;
            int i1=pair.second;
            bool o=i1%2!=0;

            if(o)
            {
                return -1;
                break;
            }
            else
            {
                int diff=sqrt(pow(i1,2));
                sw=sw+(diff/2);
            }
        }
        int ans=sw/2;
        return ans;

    }
};