class Solution {
public:
    int alternateRobbing(vector<int> &nums, int i, bool firstStart, vector<int>& dp)
     {
      if(i==0)
       {
        if(firstStart) return dp[0] = 0;
        return dp[0] = nums[0];
       }
      if(i==1) return dp[i] = nums[i];

      if(dp[i]!=-1) return dp[i];

      int maxMoney = INT_MIN;
      for(int k=2; k<=i; k++)
       {
        int currMoney = nums[i] + alternateRobbing(nums,i-k,firstStart,dp); 
        maxMoney = max(maxMoney,currMoney);
       }
      return dp[i] = maxMoney;
     }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        int startFirst = alternateRobbing(nums,n-1,true,dp1);
        int startSecond = alternateRobbing(nums,n-2,false,dp2);
        int startThird = INT_MIN;
        if(n>=3)
          startThird = alternateRobbing(nums,n-3,false,dp2);

        int ans = max(startFirst,startSecond);
        ans = max(ans,startThird);

        return ans;
    }
};