class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int base = triangle[m-1].size();

        vector<int>prev(base,0);

        for(int i=0; i<m; i++)
         {
          int n = triangle[i].size();
          vector<int> curr(n,0);

          for(int j=0; j<n; j++)
           {
            if(i==0 && j==0) 
             {
              curr[j] = triangle[i][j];
              continue;
             }

            int sameCol = INT_MAX, lesserCol=INT_MAX;
            
            if(j<n-1)
             sameCol = triangle[i][j] + prev[j];
            if(j>0)
             lesserCol = triangle[i][j] + prev[j-1];

            curr[j] = min(sameCol,lesserCol);
           }

          prev = curr;
         }

        int minPath = prev[0];
        for(int i=1; i<base; i++)
          minPath =  min(minPath,prev[i]);

        return minPath;
    }
};