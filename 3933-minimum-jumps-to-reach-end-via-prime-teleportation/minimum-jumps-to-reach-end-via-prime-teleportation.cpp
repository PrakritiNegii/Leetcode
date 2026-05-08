class Solution {
public:
    bool isPrime(int n)
     {
      if(n<=1) return false;
      for(int i=2; i<=sqrt(n); i++)
       {
        if(n%i==0) return false;
       }
      return true;
     }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,vector<int>> mp;
        for(int i=0; i<n; i++)
         {
          for(int k=1; k<=sqrt(nums[i]); k++)
          //starting from 1 because see this test case
          /*
          [7,5,7]
          Output = 1
          */
           {
            if(nums[i]%k==0)
             {
              int f1 = k;
              int f2 = nums[i]/k;
              if(isPrime(f1)) mp[f1].push_back(i);
              if(f1!=f2 && isPrime(f2)) mp[f2].push_back(i);
             }
           }
         }
        queue<pair<int,int>> q; //index, jump
        q.push({0,0});

        vector<int> visited(n,0);
        visited[0] = 1;

        while(!q.empty())
         {
          int idx = q.front().first;
          int jump = q.front().second;
          q.pop();

          if(idx==n-1) return jump;

          if(!mp[nums[idx]].empty())
           {
            auto &arr = mp[nums[idx]];  //using & does not copy entire vector every time
            for(int i=0; i<arr.size(); i++)
             {
              int jumpTo = arr[i];
              if(!visited[jumpTo])
               {
                q.push({jumpTo,jump+1});
                visited[jumpTo] = 1;
               }
             }
            mp[nums[idx]].clear();
            /*Suppose many indices contain prime 2.
              Then every time you visit another 2, you traverse the whole vector again.*/
           }

          if(idx>0 && visited[idx-1]==0) 
              {
                q.push({idx-1,jump+1});
                visited[idx-1] = 1;
              }
          if(idx<n-1 && visited[idx+1]==0) 
              {
                q.push({idx+1,jump+1});
                visited[idx+1] = 1;
              }
         }

        return -1;
    }
};