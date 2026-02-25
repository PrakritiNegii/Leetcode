class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ans;

        for(int i=0; i<n; i++)
         {
          int x = arr[i];
          long long c = 0;
          while(x!=0)
           {
            if(x%2!=0) //lsb is 1 if no is odd
              c++;
            x = x >> 1;
           }
          pq.push({c,arr[i]});
         }

        for(int i=0; i<n; i++)
         {
          pair<int,int> val = pq.top();
          ans.push_back(val.second);
          pq.pop();
         }

        return ans;
    }
};