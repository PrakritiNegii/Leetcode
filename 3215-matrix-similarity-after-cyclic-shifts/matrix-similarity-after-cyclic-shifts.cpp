class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> temp(n);

        for(int i=0; i<n; i++)
         {
          for(int j=0; j<m; j++)
           {
            temp[i].push_back(mat[i][j]);
           }
         }

        k = k % m;

        for(int i=0; i<n; i++)
         {
          if(i%2==0) //left shift
           {
            reverse(temp[i].begin(), temp[i].begin()+k);
            reverse(temp[i].begin()+k, temp[i].end());
            reverse(temp[i].begin(), temp[i].end());
           }
          else //right shift
           {
            int rightShift = m - k;
            reverse(temp[i].begin(), temp[i].begin()+rightShift);
            reverse(temp[i].begin()+rightShift, temp[i].end());
            reverse(temp[i].begin(), temp[i].end());
           }

          for(int j=0; j<m; j++)
           {
            if(mat[i][j] != temp[i][j]) return false;
           }
         }

        return true;
    }
};