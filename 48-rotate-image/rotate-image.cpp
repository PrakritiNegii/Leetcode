class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<n; i++)
         {
          for(int j=i+1; j<m; j++)
           {
            swap(matrix[i][j],matrix[j][i]);
           }
         }

        for(int c1=0, c2=m-1; c1<c2; c1++, c2--)
         {
          for(int r=0; r<n; r++)
           {
            swap(matrix[r][c1],matrix[r][c2]);
           }
         }
    }
};