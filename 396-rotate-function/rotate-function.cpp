class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
     int n = nums.size();
     int total = 0;

     for(int i=0; i<n; i++)
       total += nums[i];

     int maxSum = INT_MIN;
     int sum = 0;
     
     for(int i=0; i<n; i++)
       sum += nums[i] * i;

     maxSum = max(maxSum,sum);
     int maxIdx = n-1;

     for(int i=1; i<n; i++)
      {
       sum = (sum + total) - (nums[maxIdx]*n);
       maxSum = max(sum,maxSum);
       maxIdx--;
      }
     return maxSum;
    }
};