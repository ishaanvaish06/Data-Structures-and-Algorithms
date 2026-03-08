class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int min_index=-1;
        int min=INT_MAX;
        for(int i=0;i<capacity.size();i++)
        {
            if(itemSize<=capacity[i] && capacity[i]<min)
            {
                min_index=i;
                min=capacity[i];
            }
        }
        return min_index;

    }
};