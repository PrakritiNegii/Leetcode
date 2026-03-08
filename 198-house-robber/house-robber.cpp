class Solution {
public:
    int alternateRobbing(vector<int> &nums, int i, vector<int>& dp)
     {
      if(i<1) return dp[i] = nums[i];

      if(dp[i]!=-1) return dp[i];

      int maxMoney = nums[i];
      for(int k=2; k<=i; k++)
       {
        int currMoney = nums[i]; 
        if(dp[i-k]!=-1)
          currMoney += dp[i-k];
        else 
          currMoney  += alternateRobbing(nums,i-k,dp);
        maxMoney = max(maxMoney,currMoney);
       }
      if(i==nums.size() - 1)
       {
        int currMoney = alternateRobbing(nums,i-1,dp);
        maxMoney = max(maxMoney,currMoney);
       }
      return dp[i] = maxMoney;
     }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];

        vector<int> dp(n,-1);
        int robbing = alternateRobbing(nums,n-1,dp);

        return robbing;
    }
};