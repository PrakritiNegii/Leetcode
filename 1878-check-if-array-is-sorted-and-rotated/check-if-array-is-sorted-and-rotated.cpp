class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();
        int points = 0;
        int i=0, j=-1;
        while(j!=0)
         {
          j=(i+1)%size;
          if(nums[i]>nums[j]) //if there is a point where any number is greater than the next number (can also do it for lesser)
          //In a sorted array with duplicates there should only be 1 or 0 such points
           {
            points++;
           }
          i = j;
         }
        if(points>1)
          return false;
        else 
          return true;
    }
};