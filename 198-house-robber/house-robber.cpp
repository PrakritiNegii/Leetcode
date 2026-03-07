class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        vector<int> dp(n,-1);
        dp[0] = nums[0]; dp[1] = nums[1];

        for(int i=2; i<n; i++) //starting with index 0 so first jump is to index 2
         {
          int maxMoney = INT_MIN;
          for(int k=2; k<=i; k++)
           {
            int currMoney = nums[i] + dp[i-k];
            maxMoney = max(currMoney,maxMoney);
           }
          dp[i] = maxMoney;
         }

        for(int i=3; i<n; i++) //starting with index 1 so first jump is to index 3
         {
          int maxMoney = INT_MIN;
          for(int k=2; k<=i; k++)
           {
            int currMoney = nums[i] + dp[i-k];
            maxMoney = max(currMoney,maxMoney);
           }
          dp[i] = max(dp[i],maxMoney);
         }

        return max(dp[n-1],dp[n-2]);
    }
};