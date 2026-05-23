class Solution {
public:
    bool check(vector<int>& nums) {
       int n = nums.size();
       int drops = 0;

       for(int i=1; i<n; i++)
        {
         if(nums[i-1]>nums[i]) drops++;
         if(drops>1) return false;
        }

       if(nums[n-1]>nums[0]) drops++;
       if(drops>1) return false;

       return true;
    }
};