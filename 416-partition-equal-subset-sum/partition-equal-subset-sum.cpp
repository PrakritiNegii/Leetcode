class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for(int i=0; i<n; i++)
         {
          total += nums[i];
         }
        
        if(total%2==1) return false;
        
        total/=2;
        vector<vector<bool>> dp(n, vector<bool>(total+1,false));
        for(int i=0; i<n; i++)
         {
          dp[i][0] = true;
         }
        if(nums[0] <= total)
          dp[0][nums[0]] = true;

        for(int i=1; i<n; i++)
         {
          for(int j=1; j<=total; j++)
           {
            bool s1 = false;

            //picking for subset 1;
            if(nums[i]<=j)
              s1 = dp[i-1][j-nums[i]];

            //picking for subset 2 or not picking for subset 1;
            bool s2 = dp[i-1][j];

            dp[i][j] = s1 || s2;
           }
         }

        return dp[n-1][total];
    }
};