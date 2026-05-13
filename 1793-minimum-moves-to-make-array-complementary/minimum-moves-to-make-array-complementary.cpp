class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
      int n = nums.size();

      vector<int> diff(limit*2+2,0);
      //range of no of operations for each pair is 0, 1, 2 for every possible value of sum in range [2,limit*2]

      for(int i=0; i<n/2; i++)
       {
        int a = nums[i];
        int b = nums[n-i-1];

        int sum = a + b;

        diff[2] += 2; //initially taking number of operations = 2 as if index 2 doesn't fall in range of 1 operation or 0 it is always 2

        //range of 1 operation
        int low = min(a,b) + 1;
        int high = max(a,b) + limit; //included in 1 operation

        diff[low] -= 1;
        diff[high+1] += 1;

        diff[sum] -= 1; //if required sum == sum then number of operations to be made is 0
        diff[sum+1] +=1; //because only the exact value of sum should be made 0
       }  

      //finding minimum value in limit after giving accurate values to obtain the min number of operations

      int minimum = INT_MAX;
      for(int i=2; i<limit*2 + 2; i++) // not <= as the last value in diff array is 1 more than the max possible value of sum in range
       {
        diff[i] += diff[i-1];
        if(minimum>diff[i]) minimum = diff[i];
       }
       
      return minimum;
    }
};