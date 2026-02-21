class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i=0; i<rows; i++)
         {
          int left = 0, right = cols-1;
          while(left<=right)
           {
            int mid = (right-left)/2 + left;
            if(matrix[i][mid]==target) return true;
            if(target<matrix[i][mid])
              right = mid - 1;
            else 
              left = mid + 1;
           }
         }

        return false;
    }
};