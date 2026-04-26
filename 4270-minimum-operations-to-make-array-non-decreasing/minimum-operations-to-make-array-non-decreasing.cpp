class Solution {
public:
    long long minOperations(vector<int>& nums) {
       int n = nums.size();

        int mini = INT_MAX;
        long long allx = 0;
        for(int i=n-1; i>=0; i--)
            {
              if(nums[i]>mini) 
               {
                allx += (nums[i]-mini);
                mini = nums[i];
               }
              else
               {
                mini = min(mini,nums[i]);
               }              
            }
        return allx;
    }
};