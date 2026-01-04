class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); //row size
        int n = matrix[0].size(); //col size
        vector<char> zeroRow(m);
        vector<char> zeroCol(n);

        for(int i=0; i<m; i++)
         {
          for(int j=0; j<n; j++)
           {
            if(matrix[i][j]==0)
             {
              zeroRow[i]='1';
              zeroCol[j]='1';
             }
           }
         }

        for(int i=0; i<m; i++)
         {
          for(int j=0; j<n; j++)
           {
            if(zeroRow[i]=='1') matrix[i][j] = 0;
            else if(zeroCol[j]=='1') matrix[i][j] = 0;
           }
         }
    }
};