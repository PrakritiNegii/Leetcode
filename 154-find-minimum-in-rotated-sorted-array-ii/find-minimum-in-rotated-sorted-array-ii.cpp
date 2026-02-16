class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int minimum = nums[0];

        while(left<=right)
         {
          int mid = (right-left)/2 + left;

          if(nums[left]==nums[mid] && nums[mid]==nums[right])
           {
            left++;
            right--;
            minimum = min(minimum,nums[mid]);
            continue;
           }

          if(nums[left]<=nums[mid]) //left half is sorted
           {
            minimum = min(minimum,nums[left]);
            cout<<minimum<<endl;
            //move towards the right
            left = mid+1;
           }
          else
           {
            minimum = min(minimum,nums[mid]);
            //move towards the left
            right = mid-1;
           }
         }

        return minimum;
    }
};