class Solution {
public:
    void permutations(vector<int>& nums, vector<bool>& visited, vector<int> &arr, vector<vector<int>>& res)
     {
      if(arr.size()==nums.size())
       {
        res.push_back(arr);
        return;
       }

      for(int i=0; i<nums.size(); i++)
       {
        if(visited[i]==0)
         {
          arr.push_back(nums[i]);
          visited[i] = 1;
          
          permutations(nums,visited,arr,res);

          visited[i] = 0;
          arr.pop_back();
         }
       }
     }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        vector<bool> visited(n,0);
        vector<int> arr;
        permutations(nums,visited,arr,res);

        return res;
    }
};