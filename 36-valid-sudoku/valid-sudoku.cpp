class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++)
         { 
          for(int j=0; j<9; j++)
           {
            char val = board[i][j];
            if(val=='.') continue;
            cout<<"\n\nindices: "<<i<<" "<<j<<endl;
            int startr = i - i%3; //starting row of grid
            int startc = j - j%3; // starting column of grid
            for(int x=0; x<9; x++)
             {
              cout<<"x: "<<x<<endl;
              if(x!=j && board[i][x]==val)
                return false;
              else if(x!=i && board[x][j]==val)
                     return false;
                   else
                    {
                     int gridr = startr + x/3;
                     int gridc = startc + x%3;
                     if(gridr!=i && gridc!=j && board[gridr][gridc]==val)
                         return false;
                    }
             }
           }
         }
       return true;
    }
};