class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> PascalTri; //Matrix with numRows

       for(int i=0; i<numRows; i++)
        {
         vector<int> iRow(i+1);
         iRow[0] = 1; //Firt element of the row is 1
         iRow[i] = 1; //Last element of the row is 1
         for(int j=1; j<i; j++)
          {
           iRow[j] = PascalTri[i-1][j] + PascalTri[i-1][j-1];
          }
         PascalTri.push_back(iRow);
         for(int k=0; k<=i; k++)
          {
           cout<<PascalTri[i][k]<<" ";
          }
         cout<<endl;
        } 

      return PascalTri;
    }
};