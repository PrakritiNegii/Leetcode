class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
       int n = weights.size();
       long long sum = 0;
       
       for(int i=0; i<n; i++)
         sum += (long long) weights[i];

       long long left = 1LL, right = sum;
       long long minWeight = left;

       while(left<=right)
        {
         long long mid = (right-left)/2 + left;

         int minDaysForMid = 0;
         long long dayWeight = 0;
         int i=0;
         while(i<n)
          {
           dayWeight += weights[i];
           if(dayWeight<=mid) 
            {
             i++;
             if(i==n) //for last weight
              minDaysForMid++;
            }
           else
            {
             minDaysForMid++;
             dayWeight = 0;
            }
           if(minDaysForMid>days) 
            break;
          }

         if(minDaysForMid<=days) //possible answer as this amount of weight can be carried each day but maybe less weight can also be carried each day.
          {
           minWeight = mid;
           right = mid-1;
          }
         else
          {
           left = mid+1;
          }
        }

      return (int) minWeight;
    }
};