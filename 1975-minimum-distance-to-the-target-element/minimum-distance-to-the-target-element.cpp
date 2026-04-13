class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int idx = -1;
        int minDiff = INT_MAX;

        for(int i=0; i<nums.size(); i++)
         {
          if(nums[i]!=target) continue;

          int diff = abs(i-start);

          if(diff<minDiff)
           {
            idx = i;
            minDiff = diff;
           }
         }

        return minDiff;
    }
};