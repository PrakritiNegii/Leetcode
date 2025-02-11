class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Allocate memory for the transposed matrix
        vector<vector<int>> m(cols, vector<int>(rows)); 
        for(int i=0; i<matrix[0].size(); i++)
         {
          for(int j=0; j<matrix.size(); j++)
           {
            m[i][j] = matrix[j][i];
           }
         }
      return m;
    }
};