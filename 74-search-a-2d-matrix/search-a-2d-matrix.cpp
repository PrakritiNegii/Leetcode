class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int rows = matrix.size();
      int cols = matrix[0].size();

      //select the row:
      int left = 0, right = rows-1;
      int r = -1;
      while(left<=right)  
       {
        int mid = (right-left)/2 + left;

        if(matrix[mid][0]==target || matrix[mid][cols-1]==target) 
          return true;

        if(target>matrix[mid][0] && target<matrix[mid][cols-1])
         {
          r = mid;
          break;
         }
        else if(target<matrix[mid][0])
               right = mid - 1;
             else
               left = mid + 1;
       }
 
      if(r==-1) return false;

      cout<<r<<endl;
      //search in row r
      left = 0, right = cols-1;
      while(left<=right)
       {
        int mid = (right-left)/2 + left;

        if(matrix[r][mid]==target) 
          return true;
        else if(target<matrix[r][mid])
               right = mid - 1;
             else
               left = mid + 1;
       }
      cout<<left<<"  "<<right<<endl;
      return false;
    }
};