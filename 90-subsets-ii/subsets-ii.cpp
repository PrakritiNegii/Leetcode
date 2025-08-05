class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec = {};
        sort(nums.begin(),nums.end());
        generateSubsets(nums,ans,vec,0);
        return ans;
    }

    void generateSubsets(vector<int>& nums, vector<vector<int>>& ans, vector<int> vec, int i)
     {
      ans.push_back(vec);
      if(i==nums.size())
       {
        return;
       }
      for(int j=i; j<nums.size(); j++)
       {
        if(j>i && nums[j]==nums[j-1]) continue;
        vec.push_back(nums[j]);
        generateSubsets(nums,ans,vec,j+1);    
        vec.pop_back();
       }
     }
};