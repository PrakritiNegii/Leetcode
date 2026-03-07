class Solution {
public:
    int alternateRobbing(vector<int> &nums, int i, vector<int>& dp)
     {
      if(i<0) return INT_MIN;
      if(i<=1) return dp[i] = nums[i];

      if(dp[i]!=-1) return dp[i];

      int maxMoney = INT_MIN;
      for(int k=2; k<=i; k++)
       {
        int currMoney = nums[i]; 
        if(dp[i-k]!=-1)
          currMoney += dp[i-k];
        else 
          currMoney  += alternateRobbing(nums,i-k,dp);
        maxMoney = max(maxMoney,currMoney);
       }
      return dp[i] = maxMoney;
     }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        int startFirst = alternateRobbing(nums,n-1,dp);
        int startSecond = alternateRobbing(nums,n-2,dp);

        return max(startFirst,startSecond);
    }
};