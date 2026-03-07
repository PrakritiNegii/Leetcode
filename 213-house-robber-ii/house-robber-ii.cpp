class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        vector<int> dp(n,-1);
        dp[0] = 0; dp[1] = nums[1];

        for(int i=2; i<n; i++) //robbing the last house but not the first one
         {
          int maxMoney = INT_MIN;
          for(int k=2; k<=i; k++)
           {               
            int currMoney = nums[i] + dp[i-k];
            maxMoney = max(currMoney,maxMoney);
           }
          dp[i] = maxMoney;
         }

        vector<int> dp2(n-1,-1);
        dp2[0] = nums[0]; dp2[1] = nums[1];

        for(int i=2; i<n-1; i++) //robbing the first house but not the last one
         {
          int maxMoney = INT_MIN;
          for(int k=2; k<=i; k++)
           {               
            int currMoney = nums[i] + dp2[i-k];
            maxMoney = max(currMoney,maxMoney);
           }
          dp2[i] = maxMoney;
         }

        int ans = max(dp2[n-3],dp2[n-2]); //max money when first house was robbed from 2nd last and 3rd last houses
        
        ans = max(ans,dp[n-1]);
        
        return ans;
    }
};