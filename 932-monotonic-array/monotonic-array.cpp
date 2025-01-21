class Solution {
public:
  bool isMonotonic(vector<int>& nums) 
    {
     int a=0, d=0, i=0;
     while(i<nums.size()-1)
      {
       if(a>0 && d>0) break;
       if(nums[i]<nums[i+1]) a++;
       if(nums[i]>nums[i+1]) d++;
       i++;
      }
     if(a>0 && d>0) return false;
     else return true;
    }
};