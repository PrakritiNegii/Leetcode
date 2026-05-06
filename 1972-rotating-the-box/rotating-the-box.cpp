class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
      int n = boxGrid.size();
      int m = boxGrid[0].size();
      vector<vector<char>> ans(m,vector<char>(n));

      for(int i=0; i<n; i++)
       {
        for(int j=0; j<m; j++)
         {
          ans[j][n-i-1] = boxGrid[i][j];
         }
       }

      for(int i=0; i<n; i++)
       {
        int base = m-1, j=m-1;
        while(j>=0)
         {
          if(ans[j][i]=='#')
           {
            ans[j][i] = '.';
            ans[base][i] = '#';
            base = base-1;
           }
          else if(ans[j][i]=='*')
                 {
                  base = j-1;
                 }
          j--;
         }
       }

      return ans;
    }
};