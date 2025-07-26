class Solution {
public:
    void generate(vector<int>& candidates, int target, vector<vector<int>>&res, vector<int> &vec, int i, int sum)
     {
      if(sum>=target || i>=candidates.size())
       {
        if(sum==target)
          res.push_back(vec);
        return;
       }
      vec.push_back(candidates[i]);
      generate(candidates,target,res,vec,i,sum+candidates[i]);
      vec.pop_back();
      generate(candidates,target,res,vec,i+1,sum);
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
     {
      vector<vector<int>> res;
      vector<int> vec;
      generate(candidates,target,res,vec,0,0);
      return res;
     }  
};