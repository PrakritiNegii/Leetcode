class Solution {
public:
    int findMin(vector<int>& nums) {
       int left = 0; 
       int right = nums.size()-1;
       int minimum = nums[0];

       while(left<=right)
        {
         int mid = (right-left)/2 + left;
         //move towards unsorted            
         if(nums[mid]<nums[right]) //right half is sorted and left is unsorted
          {
             minimum = min(minimum,nums[mid]); //nums[mid] = min element in right half
             //search left
             right = mid - 1;
          }
         else //left half is sorted
          {
             minimum = min(minimum,nums[left]);
              //search right
              left = mid + 1; 
          }
        }
      return minimum;
    }
};