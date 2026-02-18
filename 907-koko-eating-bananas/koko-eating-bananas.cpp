class Solution {
public:
    bool allEaten(vector<int> &piles, int k, int h) 
     {
      int n = piles.size();
      long long hTaken = 0LL;
      for(int i=0; i<n; i++)
       {
        int div = piles[i]/k;
        int rem = piles[i]%k;

        hTaken += (long long) div;
        if(rem) 
          hTaken++;
       }
      return hTaken<=h;
     }

    int minEatingSpeed(vector<int>& piles, int h) {
     int n = piles.size();

     int max = piles[0];
     for(int i=1; i<n; i++)
       if(max<piles[i]) max = piles[i];

     if(n==h) return max; //if no of hours is equal to number of piles the min eating speed is max pile

     int k = 1;
     int left = 1, right = max; //range is 1 to max value in piles
     while(left<=right)
      {
       int mid = (right-left)/2 + left;

       if(allEaten(piles,mid,h)) //if mid is valid value of k look for smaller one to get minimum
        {
         k = mid;
         right = mid-1;
        }
       else
        {
         left = mid+1;
        }
      }
     return k;   
    }
};