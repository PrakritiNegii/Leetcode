class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        generate(nums,res,{},0);
        return res;
    }
//O(N*2^N)
    void generate(vector<int>& nums, vector<vector<int>>& res, vector<int> vec, int len) 
     {
      if(len==nums.size())
       {
        res.push_back(vec);
        return;
       }
      vec.push_back(nums[len]);
      generate(nums,res,vec,len+1);
      vec.pop_back();
      generate(nums,res,vec,len+1);
     }
};