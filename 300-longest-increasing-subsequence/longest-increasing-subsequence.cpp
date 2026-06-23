class Solution {
public:
    int length(vector<int>& nums, int i, int prevIdx, vector<vector<int>>& dp)
     {
      if(i<=0) return 0;

      if(dp[i][prevIdx]!=-1) return dp[i][prevIdx];

      int take = 0;
      if(prevIdx==0 || nums[i-1]<nums[prevIdx-1]) take = 1 + length(nums,i-1,i,dp);
      int notTake = length(nums,i-1,prevIdx,dp);

      return dp[i][prevIdx] = max(take,notTake);
     }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return length(nums,n,0,dp);
    }
};