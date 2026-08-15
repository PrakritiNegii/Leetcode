class Solution {
public:
    void permutations(vector<int>& nums, int i, int c, unordered_set<int>& visited, vector<int>& arr, vector<vector<int>> &res) {
        // cout<<c<<"\tThis is n and i\t"<<i<<"\n\n";
      if(c==0) 
       {
        res.push_back(arr);
        // cout<<"Pushing\n";
        // for(int x=0; x<arr.size(); x++)
        //   cout<<arr[x]<<"\t";
        // cout<<endl<<endl;
        return;
       }
    
      for(int j=1; j<nums.size(); j++)
       {
        int idx = (i+j)%(nums.size());
        // cout<<i<<"\t"<<idx;
        if(visited.count(nums[idx]) == 0)
         {
            // cout<<"\t selected"<<endl;
            // cout<<"\nis there\n\n";
          visited.insert(nums[idx]);
          arr.push_back(nums[idx]);

          permutations(nums,idx,c-1,visited,arr,res);

          visited.erase(nums[idx]);
          arr.pop_back();
         }
       }
    }

    vector<vector<int>> permute(vector<int>& nums) {
      int n = nums.size();

      vector<vector<int>> res;
      for(int i=0; i<n; i++)
       {
        // cout<<i<<" first index"<<endl<<endl<<endl;

        unordered_set<int> visited;
        visited.insert(nums[i]);

        vector<int> arr;
        arr.push_back(nums[i]);

        permutations(nums,i,n-1,visited,arr,res);

        // visited.erase(nums[idx]);
        //   arr.pop_back;
       }

      return res; 
    }
};