class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=1; i<=n; i++)
         {
          for(int prevIdx=0; prevIdx<=n; prevIdx++)
           {
            int take = 0;
            if(prevIdx==0 || nums[i-1]<nums[prevIdx-1])
                take = 1 + dp[i-1][i];
            int notTake = dp[i-1][prevIdx];

            dp[i][prevIdx] = max(take,notTake);
           }
         }

        return dp[n][0];
    }
};