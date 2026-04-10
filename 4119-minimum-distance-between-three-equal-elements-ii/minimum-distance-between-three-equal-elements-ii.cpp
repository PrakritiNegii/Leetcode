class Solution {
public:
    int minimumDistance(vector<int>& nums) {
      int n = nums.size();
      if(n<3) return -1;

      vector<vector<int>> indices(n+1);
      for(int i=0; i<n; i++)
        indices[nums[i]].push_back(i);

      int minDist = INT_MAX;
      /*
      The distance formula abs(i - j) + abs(j - k) + abs(k - i) simplifies to 
      2 * (max(i, j, k) - min(i, j, k)).
      */
      for(int i=0; i<=n; i++)
       {
        if(indices[i].size()<3) continue;
        
        for(int j=2; j<indices[i].size(); j++)
         {
          int maxIdx = max({indices[i][j],indices[i][j-1],indices[i][j-2]});
          int minIdx = min({indices[i][j],indices[i][j-1],indices[i][j-2]});
          minDist = min(minDist, maxIdx-minIdx);
         }
       }

      if(minDist==INT_MAX) return -1;
      return minDist*2;
    }
};