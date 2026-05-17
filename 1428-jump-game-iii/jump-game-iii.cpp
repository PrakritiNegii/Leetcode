class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
       int n = arr.size();
       queue<int> q; 
       q.push(start);
       vector<bool> visited(n,false);
       visited[start] = true;

       while(!q.empty())
        {
         int idx = q.front();
         q.pop();

         if(arr[idx]==0) return true;

         int j1_idx = idx + arr[idx];
         int j2_idx = idx - arr[idx];

         if(j1_idx>=0 && j1_idx<n && !visited[j1_idx]) 
          {
            q.push(j1_idx);
            visited[j1_idx] = true;
          }
         if(j2_idx>=0 && j2_idx<n && !visited[j2_idx]) 
          {
            q.push(j2_idx);
            visited[j2_idx] = true;
          }
        }

      return false;
    }
};