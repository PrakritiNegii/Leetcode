class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        generate(nums,res,{},0,0);
        res.push_back(nums);
        return res;
    }

    void generate(vector<int>& nums, vector<vector<int>>& res, vector<int> vec, int len, int pos) //pos is vector vec's last element's position in nums +1
     {
      if(len==nums.size()-1)
        return;
      for(int i=pos; i<nums.size(); i++)
       {
        vec.push_back(nums[i]);
        res.push_back(vec);
        vec.pop_back();
       }
      for(int i=pos; i<nums.size(); i++)
       {
        vec.push_back(nums[i]);
        generate(nums,res,vec,len+1,i+1);
        vec.pop_back();
       }
     }
};