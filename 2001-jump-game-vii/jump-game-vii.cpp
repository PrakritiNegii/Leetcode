class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n-1]=='1') return false;

        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int maxIdx = 0;

        while(!q.empty()) 
         {
          int i = q.front();
          q.pop();

          for(int j=max(i+minJump,maxIdx); j<=min(i+maxJump,n-1); j++)
           {
            maxIdx = j;
            if(visited[j]==true) continue;

            if(s[j]=='1')
             {
              visited[j] = true;
              continue;
             } 
            
            if(j==n-1) return true;
            q.push(j);
            visited[j] = true;
           }
         }

        return false;
    }
};