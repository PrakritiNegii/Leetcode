class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];

        vector<int> dp(n,-1);
        int prev = nums[0]; 
        int prev2 = 0;

        for(int i=1; i<n; i++)
         {
          int pick = nums[i] + prev2;
          int not_pick = prev;

          prev2 = prev;
          prev = max(pick,not_pick);
         }
        
        return prev;
    }
};