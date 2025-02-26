class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int size = nums.size();
        int currMaxSum = 0, currMinSum = 0;
        for(int i=0; i<size; i++)
         {
           //Kadance Algorithm
           currMaxSum = currMaxSum + nums[i];
           maxSum = max(maxSum,currMaxSum);
           if(currMaxSum<0)
            {
             currMaxSum = 0;
            }
           //Reverse Kadance Algorithm
           currMinSum = currMinSum + nums[i];
           minSum = min(minSum,currMinSum);
           if(currMinSum>0)
            {
             currMinSum = 0;
            }
         }
        minSum *= -1;
        if(minSum > maxSum)
          return minSum;
        else 
          return maxSum;
    }
};