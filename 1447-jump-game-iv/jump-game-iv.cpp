class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> mp;

        for(int i=0; i<n; i++)
         {
          mp[arr[i]].push_back(i);
         }

        queue<pair<int,int>> q; //index and step
        q.push({0,0});

        vector<bool> visited(n,false); 
        visited[0] = true;

        int minStep = n-1;

        while(!q.empty())
         {
          int idx = q.front().first;
          int step = q.front().second;
          q.pop();

          if(idx==n-1) minStep = min(minStep,step);

          if(idx-1>=0 && !visited[idx-1]) 
            {
             q.push({idx-1,step+1});
             visited[idx-1] = true;
            }
          if(idx+1<n && visited[idx+1]==false) 
            {
             q.push({idx+1,step+1});
             visited[idx+1] = true;
            }

          auto a = mp[arr[idx]];
          for(int j=0; j<a.size(); j++)
           {
            if(idx==arr[j]) continue;
            if(!visited[a[j]])
              {
                q.push({a[j],step+1});
                visited[a[j]] = true;
              }
           }
          mp.erase(arr[idx]);
         }

       return minStep;
    }
};