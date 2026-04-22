class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
     int n = nums.size();
     int total = 0;

     for(int i=0; i<n; i++)
      {
       total += nums[i];
      }   

     int left = 0, right = total-nums[0];
     for(int i=0; i<n; i++)
      {
       if(left==right) return i;
       left += nums[i];
       if(i<n-1) right -= nums[i+1];
      }

     return -1;
    }
};