class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        //choosing row
        //finding the upper bound of target in column 1
        int row_upper=rows-1, row_lower=0;

        int left=0, right=rows-1;
        while(left<=right)
         {
          int mid = (right-left)/2 + left;
          if(matrix[mid][0]==target) return true;
          if(target>matrix[mid][0])
            left = mid + 1;
          else
            right = mid - 1;
         }
        row_upper = left;

       left=0, right=rows-1;
       while(left<=right)
         {
          int mid = (right-left)/2 + left;
          if(matrix[mid][cols-1]==target) return true;
          if(target>matrix[mid][cols-1])
            left = mid + 1;
          else
            right = mid - 1;
         }
        row_lower = left;

        //check columns in rows row_lower to row_upper = [row_lower,row_upper)
        for(int i=row_lower; i<row_upper; i++)
         {
          left = 0, right = cols-1;
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