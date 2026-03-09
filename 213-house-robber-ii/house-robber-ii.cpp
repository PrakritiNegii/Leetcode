class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];

        int with0prev = nums[0]; 
        int with0prev2 = 0;

        int without0prev = 0;
        int without0prev2 = 0;

        for(int i=1; i<n; i++)
         {
          int pick1 = nums[i] + with0prev2;
          int not_pick1 = with0prev;

          with0prev2 = with0prev;
          with0prev = max(pick1,not_pick1);

          int pick2 = nums[i] + without0prev2;
          int not_pick2 = without0prev;

          without0prev2 = without0prev;
          without0prev = max(pick2,not_pick2);
         }
        
        return max(with0prev2, without0prev);
    }
};