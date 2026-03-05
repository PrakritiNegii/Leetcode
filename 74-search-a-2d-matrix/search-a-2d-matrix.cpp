class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int rows = matrix.size();
      int cols = matrix[0].size();

      //Interpret given 2D matrix as a 1D array
      int left = 0, right = rows*cols - 1;
      while(left<=right)  
       {
        int mid = (right-left)/2 + left;

        int r = mid / cols;
        int c = mid % cols;

        if(matrix[r][c]==target) return true;
        if(matrix[r][c]<target) left = mid + 1;
        else right = mid - 1;        
       }

      return false;
    }
};