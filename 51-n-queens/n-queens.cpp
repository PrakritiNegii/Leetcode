class Solution {
public:
    bool validPosition(vector<string> &board, int size, int r, int c)
     {
      int i = r-1, j = c;
      while(i>=0)
       {
        if(board[i][c]=='Q')
           return false;
        i--;
       } 

      i = r-1; j = c-1;
      while(i>=0 && j>=0)
       {
        if(board[i][j]=='Q')
           return false;
        i--; j--;
       }

      i = r-1; j = c+1;
      while(i>=0 && j<size)
       {
        if(board[i][j]=='Q')
           return false;
        i--; j++;
       }

      return true;
     }

    void traverse(vector<vector<string>>& ans, vector<string>& board, int r)
     {
      int size = board.size();
      if(r==size)
       {
        ans.push_back(board);
        return;
       }
      // if(vec.size()==n) return;
      for(int i=0; i<size; i++) // r is the row
       {
        board[r][i] = 'Q';
        bool check = validPosition(board,size,r,i);
        if(check==true)
           traverse(ans,board,r+1);
        board[r][i] = '.';
       }
     } 

    vector<vector<string>> solveNQueens(int n) {
      string s = "";
      for(int i=0; i<n; i++)
        s+=".";
      vector<string> board(n,s);
      vector<vector<string>> ans;
      
      traverse(ans, board, 0);
      return ans;  
    }
};