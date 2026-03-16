class Solution {
public:
    int converge(int r1, int c1, int r2, int c2, vector<vector<int>>& grid)
     {
      int n = grid.size();
      int m = grid[0].size();
      int sum = 0;
      while(r1!=r2 || c1!=c2)
       {
        sum += grid[r1][c1] + grid[r2][c2];
        r1++; c1++;
        r2++; c2--;
       }
      sum += grid[r1][c1];
      return sum;
     }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        set<int, greater<int>> sums;

        for(int i=0; i<n; i++)
         {
          for(int j=0; j<m; j++)
           {
            int sum = grid[i][j];
            sums.insert(sum);

            int r1=i+1, c1=j-1, r2=i+1, c2=j+1;
            int rowLimit = (i+(n-1)) / 2;
            while(r1<=rowLimit && c1>=0 && r2<=rowLimit && c2<m) //diverge
             {
               sum += grid[r1][c1] + grid[r2][c2];
               int converged = sum + converge(r1+1,c1+1,r2+1,c2-1,grid);
               r1++; c1--;
               r2++; c2++;
               sums.insert({converged});
             }
           }
         }

        vector<int> ans;
        for(auto val : sums)
         {
          ans.push_back(val);
          if(ans.size()==3) break;
         }

        return ans;
    }
};