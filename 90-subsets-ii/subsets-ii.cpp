class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        sort(nums.begin(),nums.end());
        generateSubsets(nums,ans,vec,0);
        return ans;
    }

    void generateSubsets(vector<int>& nums, vector<vector<int>>& ans, vector<int> vec, int i)
     {
      if(i==nums.size())
       {
        ans.push_back(vec);
        return;
       }
      int x = nums[i];
      vec.push_back(x);
      generateSubsets(nums,ans,vec,i+1);
      vec.pop_back();
      while(i<nums.size() && nums[i]==x)
       {
        i++;
       }
     generateSubsets(nums,ans,vec,i);
     }
};