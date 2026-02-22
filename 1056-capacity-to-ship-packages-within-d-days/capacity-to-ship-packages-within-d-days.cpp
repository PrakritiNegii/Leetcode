class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
       int n = weights.size();
       long long sum = 0;
       
       for(int i=0; i<n; i++)
         sum += (long long) weights[i];

       long long left = (long long) *max_element(weights.begin(),weights.end()); 
       long long right = sum;

       while(left<=right)
        {
         long long mid = (right-left)/2 + left;

         int minDaysForMid = 0;
         long long dayWeight = 0;
         int i=0;
         while(i<n)
          {
           dayWeight += weights[i];
           if(dayWeight>mid) 
            {
             minDaysForMid++;
             dayWeight = weights[i];
            }
            i++;
           if(minDaysForMid>days) 
            break;
          }
         minDaysForMid++;

         if(minDaysForMid<=days) //possible answer as this amount of weight can be carried each day but maybe less weight can also be carried each day.
           right = mid-1;
         else
           left = mid+1;
        }

      return (int) left;
    }
};