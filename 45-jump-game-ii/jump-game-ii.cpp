class Solution {
public:
    int minSteps(vector<int>& nums, int i, vector<int>& dp)
     {
      if(i>=nums.size()-1) return 0;

      if(dp[i]!=-1) return dp[i];
      if(nums[i]==0) return 1e8;
      int minS = 1e8;

      for(int j=i+nums[i]; j>i; j--)
       {
        int currSteps = 1 + minSteps(nums,j,dp);
        minS = min(minS,currSteps);
       }

      return dp[i] = minS;
     }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return minSteps(nums,0,dp);
    }
};