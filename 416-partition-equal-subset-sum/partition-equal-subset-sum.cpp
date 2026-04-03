class Solution {
public:
    bool partitioning(vector<int>& nums, int i, int sum1, int sum2, int target, vector<vector<int>>& dp)
     {
      if(sum1>target || sum2>target) return false;
      if(i==nums.size()) 
       {
        if(sum1==sum2) return true;
        return false;
       }

      if(dp[i][sum1]!=-1) return dp[i][sum1];
      //picking for subset 1;
      bool s1 = partitioning(nums,i+1,sum1+nums[i],sum2,target,dp);

      //picking for subset 2;
      bool s2 = partitioning(nums,i+1,sum1,sum2+nums[i],target,dp);

      return dp[i][sum1] = s1 || s2;
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

        return partitioning(nums,0,0,0,total,dp);
    }
};