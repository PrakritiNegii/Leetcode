class Solution {
public:
   void generate(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& vec, int i, int sum)
    {
     if(sum>=target || i>=candidates.size())
      {
       if(sum==target)
         ans.push_back(vec);
       return;
      }
     int x = candidates[i];
     vec.push_back(x);
     generate(candidates,target,ans,vec,i+1,sum+x);
     vec.pop_back();
     while(i<candidates.size() && candidates[i]==x)
      {
       i++;
      }
     generate(candidates,target,ans,vec,i,sum);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> vec;
        generate(candidates,target,ans,vec,0,0);
        return ans;
    }
};