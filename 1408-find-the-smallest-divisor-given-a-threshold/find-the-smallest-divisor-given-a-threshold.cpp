class Solution {
public:
    bool checkResultThreshold(vector<int>& nums, double mid, int threshold)
     {
      int sum = 0;
      for(int i=0; i<nums.size(); i++)
       {
        sum += ceil(nums[i]/mid);
        if(sum>threshold) return false;
       }
      return true;
     }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int left = 1; //smallest divisor is 1
        int right = *max_element(nums.begin(),nums.end()); //smallest divisor that can give the minimum result is the maximum number in the array. All numbers greater than it will return the same result and ceil of quotient is to be calculated.

        while(left<=right)
         {
          int mid = (right-left)/2 + left;
          bool valid = checkResultThreshold(nums,mid,threshold);

          if(valid) //valid answer found but can be smaller
            right = mid - 1;
          else
            left = mid + 1;
         }

        return left;
    }
};