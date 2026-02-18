class Solution {
public:
    bool allEaten(vector<int> &piles, double k, int h) 
     {
      int n = piles.size();
      long long hTaken = 0LL;
      for(int i=0; i<n; i++)
       {
        hTaken += ceil(piles[i]/k);
       }
      return hTaken<=h;
     }

    int minEatingSpeed(vector<int>& piles, int h) {
     int left = 1; //range is 1 to max value in piles
     int right = *max_element(piles.begin(), piles.end());
     while(left<=right)
      {
       int mid = (right-left)/2 + left;
       if(allEaten(piles,mid,h)) //if mid is valid value of k look for smaller one to get minimum
         right = mid-1;
       else
         left = mid+1;
      }
     return left;   
    }
};