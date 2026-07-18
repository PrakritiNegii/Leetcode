class Solution {
public:
    int lis(vector<int>& nums, int i, int prev, vector<vector<int>>& dp)
     {
      if(i<0) return 0;
      if(dp[i][prev]!=-1) return dp[i][prev];

      int notTake = lis(nums,i-1,prev,dp);
      int take = 0;
      if(prev==nums.size() || nums[i]<nums[prev]) 
          take = 1 + lis(nums,i-1,i,dp);

      return dp[i][prev] = max(notTake,take);
     }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return lis(nums,n-1,n,dp);
    }
};