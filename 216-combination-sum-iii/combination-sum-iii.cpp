class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
     vector<vector<int>> ans;  
     vector<int> vec;
     generate(ans,k,n,vec,1);
     return ans; 
    }

    void generate(vector<vector<int>> &ans, int k, int n, vector<int> &vec, int i)
     {
      if(k==0)
       {
        if(n==0)
          ans.push_back(vec);
        return;
       }
      for(int j=i; j<10; j++)
       {
        if(n-j < 0) return;
        vec.push_back(j);
        generate(ans, k-1, n-j, vec, j+1);
        vec.pop_back();
       }
     }
};