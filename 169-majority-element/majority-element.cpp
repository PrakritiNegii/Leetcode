class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int el;
      int c = 0;
      int n = nums.size();
      for(int i=0; i<n; i++)
       {
        if(c==0) 
         {
          el = nums[i];
         }
        if(nums[i]==el) c++;
        else c--;
       }
      return el;
    }
};