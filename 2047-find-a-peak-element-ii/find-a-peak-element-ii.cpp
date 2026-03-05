class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int rowD[] = {0,0,-1,1};
        int colD[] = {1,-1,0,0};

        int row = 0, col = 0;
        while(row<n && col<m)
         {
          bool peak = true;
          for(int i=0; i<4; i++)
           {
            int r = row + rowD[i];
            int c = col + colD[i];

            if(r>=0 && r<n && c>=0 && c<m && mat[r][c]>mat[row][col])
             {
              peak = false;
              row = r;
              col = c;
             }
           }
          
          if(peak) return {row,col};
         }

        return {-1,-1};
    }
};