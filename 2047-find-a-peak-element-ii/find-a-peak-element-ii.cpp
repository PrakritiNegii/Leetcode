class Solution {
public:
    int maxInCol(vector<vector<int>>& mat, int c)
     {
      int n = mat.size();

      int max = mat[0][c];
      int r = 0;
      for(int i=1; i<n; i++)
        if(mat[i][c]>max) 
         {
          max = mat[i][c];
          r = i;
         }
      
      return r;
     }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();


        int low = 0, high = m-1;
        while(low<=high)
         {
          int mid = (low + high) >> 1; //mid

          int col = mid;
          int row = maxInCol(mat,mid);

          int curr = mat[row][col]; //max element so only check for columns
          bool peak = true;
          int colD[] = {1,-1};
          for(int i=0; i<2; i++)
           {
            int c = col + colD[i];
            
            if(c>=0 && c<m && mat[row][c]>curr)
             {
              peak = false;
              col = c;
             }
           }

          if(peak) return {row,col};

          if(col>mid) low = mid + 1; //low = col
          else high = mid - 1; //high = col
         }

        return {-1,-1};
    }
};