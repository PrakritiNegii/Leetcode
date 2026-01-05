class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); //row size
        int n = matrix[0].size(); //col size
        bool firstRow = false; //First row has no zero
        bool firstCol = false; //First col has no zero
        for(int i=0; i<m; i++)
         {
          for(int j=0; j<n; j++)
           {
            if(matrix[i][j]==0)
             {
              if(i==0 || j==0)
               {
                if(i==0) firstRow = true;
                if(j==0) firstCol = true;
                continue;
               } 
              matrix[i-i][j]=0; //setting the column's first element to 0
              matrix[i][j-j]=0; //setting the row's first element to 0
             }
           }
         }

        //Check for elements not in first row or first column
        //If these elements are in a row with first element zero or in a column with first element 0 turn them 0
        for(int i=1; i<m; i++)
         {
          for(int j=1; j<n; j++)
           {
            if(matrix[i-i][j]==0) matrix[i][j] = 0;
            else if(matrix[i][j-j]==0) matrix[i][j] = 0;
           }
         }

        if(firstRow==true) //if first row has a 0 every element in first row should be 0
         {
          for(int i=0, j=0; j<n; j++)
            matrix[i][j] = 0;
         }

        if(firstCol==true) //if first col has a 0 every element in first col should be 0
         {
          for(int j=0, i=0; i<m; i++)
            matrix[i][j] = 0;
         }
    }
};