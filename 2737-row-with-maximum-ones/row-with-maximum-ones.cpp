class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int maxC = -1;
        int maxInd = -1;

        for(int i=0; i<m; i++)
         {
          int c = 0;
          for(int j=0; j<n; j++)
           {
            c += mat[i][j];
           }
          if(c>maxC)
           {
            maxC = c;
            maxInd = i;
           }
         }
         
        return {maxInd,maxC};
    }
};