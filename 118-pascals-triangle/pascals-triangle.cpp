class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> PascalTri;
        for(int i=0; i<numRows; i++)
         {
          vector<int> temp(i+1);
          temp[0] = 1;
          temp[i] = 1;
          for(int j=1; j<i; j++)
           {
            temp[j] = temp[j-1] * (i-j+1) / j;
           }
          PascalTri.push_back(temp);
         }
        return PascalTri;
     }
};