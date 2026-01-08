class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); //number of rows
        int n = matrix[0].size(); //number of columns

        vector<int> spiral;

        int r = m-1, c = n-1;
        int rs = 0, cs = 0; //rowStart and columnStart

        while(rs<=r && cs<=c)
        {
          int i=rs, j=cs;
          while(j<=c)
           {
            spiral.push_back(matrix[i][j]);
            cout<<"1 "<<matrix[i][j]<<endl;
            j++; 
           }
          j--; //j goes out of bound for the last increment of the loop
          i++; //last element in row will only be checked once
          while(i<=r)
           {
            spiral.push_back(matrix[i][j]);
                        cout<<"2 "<<matrix[i][j]<<endl;

            i++;
           }
          i--; //i goes out of bound for the last increment of the loop
          j--; //last element in column to be checked only once
          while(j>=cs && rs<r)
           {
            spiral.push_back(matrix[i][j]);
                        cout<<"3 "<<matrix[i][j]<<endl;

            j--;
           }
          j++; //j goes less than cs
          i--; //last element in row (right to left traversal) to be checked only once
          rs++;
          while(i>=rs && cs<c)
           {
            spiral.push_back(matrix[i][j]);
                        cout<<"4 "<<matrix[i][j]<<endl;

            i--;
           }
          cs++;
          c--; r--;
          cout<<"Loop end "<<r<<" "<<c<<" "<<rs<<" "<<cs<<endl;
        }
      return spiral;
    }
};