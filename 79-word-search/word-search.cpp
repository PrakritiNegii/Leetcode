class Solution {
public:
    int rows[4] = {0,0,-1,1}; //cannot declare array without size here
    int cols[4] = {-1,1,0,0};

    void check(vector<vector<char>>& board, int r, int c, string& word, int x, bool &res)
     {
      if(x==word.size())
        res = true;
      for(int k=0; k<4; k++)
       {
        if(res == true) break;
        int nr = r + rows[k];
        int nc = c + cols[k];
        bool found = false;
        if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size())
         {
          if(board[nr][nc]==word[x])
            {
             board[nr][nc] = '0';
             check(board,nr,nc,word,x+1,res);
             board[nr][nc] = word[x];
            }
         }
       }
     }

    bool exist(vector<vector<char>>& board, string word) 
     {
      int row = board.size();
      int col = board[0].size();
    
      bool res = false;

      for(int i=0; i<row; i++)
       {
        for(int j=0; j<col; j++)
         {
          if(board[i][j]==word[0])
           {
            board[i][j] = '0';
            check(board,i,j,word,1,res);
            board[i][j] = word[0];
           }
          if(res==true)
            return true;
         }
       }   

      return res;
     }
};