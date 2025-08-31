class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
     int maxc = 0;
     int c = 0;
     for(int i=0; i<nums.size(); i++)
      {
       if(nums[i]==1) c++;
       else c = 0;
       maxc = max(maxc,c);
      }   
     return maxc;
    }
};