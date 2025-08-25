class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) 
     {
      int size = board.size();
      solve(board,0);
     }
    bool solve(vector<vector<char>>&board, int r)
     {
      for(int i=0; i<9; i++)
       {
        for(int j=0; j<9; j++)
         {
          if(board[i][j]=='.')
           {
            for(int val=1; val<=9; val++)
             {
              if(isSafe(val,board,i,j))
               {
                board[i][j] = (char) (val + 48);
                if(solve(board,i))
                  return true;
                else
                 {
                  board[i][j] = '.';
                 } 
               }
             }
            return false;
           }
         }
       }
      return true;
     }

    bool isSafe(int val, vector<vector<char>>&board, int r, int c)
     {
      char ch = (char) (val + '0');
      int startRow = r - r % 3;
      int startCol = c - c % 3;
      for(int i=0; i<9; i++)
       {
        if(board[i][c]==ch) return false;
        if(board[r][i]==ch) return false;
        if(board[startRow + (i/3)][startCol + (i%3)]==ch) return false; 
       }
      return true;
     }
};