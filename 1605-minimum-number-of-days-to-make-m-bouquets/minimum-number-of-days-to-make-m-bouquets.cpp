class Solution {
public:
    bool possible(vector<int>& bloomDay, int days, int m, int k)
     {
      int bouquets = 0;
      int flowers = 0;
      for(int i=0; i<bloomDay.size(); i++)
       {
        if(bloomDay[i]<=days) 
          flowers++;
        else
         {
          bouquets += flowers/k;
          flowers = 0;
         }
       }
      bouquets += flowers/k;
      return bouquets>=m;
     }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
      int n = bloomDay.size();

      long long totalFlowersReq = (long long) m*k;
      if(totalFlowersReq>n) return -1;

      int left = *min_element(bloomDay.begin(),bloomDay.end());
      int right = *max_element(bloomDay.begin(),bloomDay.end());

      while(left<=right)
       {
        int mid = (right-left)/2 + left;

        if(possible(bloomDay,mid,m,k)) //valid answer, can check for shorter wait time
         {
          right = mid - 1;
         }
        else //wait longer for flowers to bloom
         {
          left = mid + 1;
         }
       }  

      return left;
    }
};

