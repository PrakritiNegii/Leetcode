class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n,vector<int>(n+1,0));

        for(int prev=0; prev<=n; prev++)
         {
          if(prev==n || nums[0]<nums[prev])
            dp[0][prev] = 1;
          else
            dp[0][prev] = 0;
         }

        for(int i=1; i<n; i++)
         {
          for(int prev=0; prev<=n; prev++)
           {
            int notTake = dp[i-1][prev];
            int take = 0;
            if(prev==n || nums[i]<nums[prev])
                take = 1 + dp[i-1][i];

            dp[i][prev] = max(notTake,take);
           }
         }
        return dp[n-1][n];
    }
};