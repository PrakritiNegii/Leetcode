class Solution {
public:
    long long minOperations(vector<int>& nums) {
       int n = nums.size();

        long long allx = 0;
        for(int i=n-2; i>=0; i--)
            {
              if(nums[i]>nums[i+1]) 
                allx += (nums[i] - nums[i+1]);
            }
        return allx;
    }
};