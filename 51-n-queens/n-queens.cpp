class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
      string s = "";
      for(int i=0; i<n; i++)
        s+=".";
      vector<string> vec(n,s);
      vector<char> col(n,'0');
      vector<vector<char>> visited (n, vector<char> (n,'0'));
      vector<vector<string>> ans;
      
      traverse(ans, vec, n, 0, col, visited);
      return ans;  
    }

    void traverse(vector<vector<string>>& ans, vector<string>& vec, int n, int r, vector<char>& col, vector<vector<char>> visited)
     {
      int size = vec.size();
      if(n==0)
       {
        ans.push_back(vec);
        return;
       }
      // if(vec.size()==n) return;
      for(int i=0; i<size; i++) // r is the row
       {
        if(col[i]=='1' || visited[r][i]=='1') continue;

        vec[r][i] = 'Q';
        col[i] = '1';

        vector<vector<char>> copyVisited (size, vector<char> (size));
        for(int x=0; x<size; x++)
         {
          for(int y=0; y<size; y++)
           {
            copyVisited[x][y] = visited[x][y];
           }
         }

        int p = r+1, q = i+1;
        while(p<size && q<size)
         {
          copyVisited[p++][q++] = '1';
         }

        p = r+1, q = i-1;
        while(p<size && q>=0)
         {
          copyVisited[p++][q--] = '1';
         }

        cout<<endl;
        traverse(ans, vec, n-1, r+1, col, copyVisited);
        vec[r][i] = '.';
        col[i] = '0';

       }
     } 
};