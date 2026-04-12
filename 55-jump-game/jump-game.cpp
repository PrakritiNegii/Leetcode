class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int validIdx = n-1;

        for(int i=n-2; i>=0; i--)
          if(nums[i]>= (validIdx-i)) validIdx = i;

        return validIdx==0;
    }
};