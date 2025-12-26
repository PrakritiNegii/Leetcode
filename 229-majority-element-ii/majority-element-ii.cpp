class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      vector<int> ans;
      int n = nums.size();

      if(n==1) return nums;
      int s = (n/3)+1;  
      int c = 1;
      for(int i=0; i<n; i++)
       {
        if(i<n-1 && nums[i]==nums[i+1]) c++;
          else
             {
              if(c>=s) 
                ans.push_back(nums[i]);
              c = 1;
             }
       }

      return ans;
    }
};