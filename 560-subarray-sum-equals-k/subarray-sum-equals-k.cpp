class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> frequency;
        int n = nums.size();
        
        frequency[0]=1;
        int c = 0;
        int preSum = 0;
        for(int i=0; i<n; i++)
         {
          preSum += nums[i];        
          int remove = preSum-k;

          c = c + frequency[remove];
        
          frequency[preSum]++;
         }        
        return c;
    }
};