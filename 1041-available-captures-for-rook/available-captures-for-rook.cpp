class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rookCol=0;
        int i=0;
        for(; i<8; i++)
         {
          for(int j=0, k=7; j<k; j++,k--)
           {
            if(board[i][j]=='R')
             {
              rookCol = j;
              break;
             }
            if(board[i][k]=='R')
             {
              rookCol = k;
              break;
             }
           }
          if(board[i][rookCol]=='R')
            break;
         }
        
        int pawn = 0;

        //Checking top
        for(int row = i-1; row>=0; row--)
         {
          if(board[row][rookCol]=='B') break;
          if(board[row][rookCol]=='p') { pawn++; break; }
         }

        //Checking bottom
        for(int row = i+1; row<8; row++)
         {
          if(board[row][rookCol]=='B') break;
          if(board[row][rookCol]=='p') { pawn++; break; }
         }

        //Checking left
        for(int col = rookCol-1; col>=0; col--)
         {
          if(board[i][col]=='B') break;
          if(board[i][col]=='p') { pawn++; break; }
         }

        //Checking right
        for(int col = rookCol+1; col<8; col++)
         {
          if(board[i][col]=='B') break;
          if(board[i][col]=='p') { pawn++; break; }
         }

        return pawn;
    }
};