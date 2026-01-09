class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); //number of rows
        int n = matrix[0].size(); //number of columns

        vector<int> spiral;
        
        int top=0, bottom=m-1;
        int left=0, right=n-1;
        while(top<=bottom && left<=right)
          {
            //left to right
            for(int j=left; j<=right; j++)
             {
              spiral.push_back(matrix[top][j]);
             }
            //top to bottom
            top++;
            for(int i=top; i<=bottom; i++)
             {
              spiral.push_back(matrix[i][right]);
             }
            right--;
            //right to left
            for(int j=right; j>=left && top<=bottom; j--) //not executed when only 1 row left
             {
              spiral.push_back(matrix[bottom][j]);
             }
            bottom--;
            //bottom to top
            for(int i=bottom; i>=top && left<=right; i--) //not executed when only 1 col left
             {
              spiral.push_back(matrix[i][left]);
             }
            left++;
          }
      return spiral;
    }
};