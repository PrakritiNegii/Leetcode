class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
      vector<string> s;
      int start;
      if(nums.size()>=1)
        start = nums[0];
      for(int i=1; i<=nums.size(); i++)
       {
        if(i==nums.size() || nums[i-1]!=nums[i]-1)
         {
          if(start!=nums[i-1])
            s.push_back(to_string(start)+"->" + to_string(nums[i-1]));
          else
            s.push_back(to_string(start)); //s.push_back(to_string(nums[i]));
          
          if(i<nums.size())
             start = nums[i];
         }
       }  
      return s;
    }
};