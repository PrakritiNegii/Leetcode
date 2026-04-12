class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIdxReached = 0;

        for(int i=0; i<n-1; i++)
         {
          maxIdxReached = max(maxIdxReached, i+nums[i]);
          if(maxIdxReached==i) return false;
         }

        return true;
    }
};