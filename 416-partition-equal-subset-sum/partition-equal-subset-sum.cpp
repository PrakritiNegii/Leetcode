class Solution {
public:
    bool partitioning(vector<int>& nums, int i, int sum, vector<vector<int>>& dp)
     {
      if(sum<0) return false;
      if(sum==0) return true;
      if(i==0) return false;

      if(dp[i][sum]!=-1) return dp[i][sum];
      //picking for subset 1;
      bool s1 = partitioning(nums,i-1,sum-nums[i],dp);

      //picking for subset 2;
      bool s2 = partitioning(nums,i-1,sum,dp);

      return dp[i][sum] = s1 || s2;
     }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++)
         {
          total += nums[i];
         }
        
        if(total%2==1) return false;
        
        total/=2;

        vector<vector<int>> dp(n, vector<int>(total+1,-1));

        return partitioning(nums,n-1,total,dp);
    }
};