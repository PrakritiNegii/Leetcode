class Solution {
public:
    int alternateRobbing(vector<int> &nums, int i, vector<int>& dp)
     {
      if(i==0) return dp[i] = nums[i];
      if(i<0) return 0;

      if(dp[i]!=-1) return dp[i];

      int pick = nums[i] + alternateRobbing(nums,i-2,dp);
      int not_pick = alternateRobbing(nums,i-1,dp);

      return dp[i] = max(pick,not_pick);
     }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];

        vector<int> dp(n,-1);
        int robbing = alternateRobbing(nums,n-1,dp);

        return robbing;
    }
};