class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int prevMissingCount, currMissingCount;
        prevMissingCount = currMissingCount = arr[0]-1;

        int kthMissing = 0;

        if(currMissingCount>=k) //In the case that kth missing no exists exists before first element of the array.
           {
            return k;
           }

        for(int i=0; i<n-1; i++)
         {
          if(arr[i+1]>arr[i]+1) //there is a missing number
           {
            prevMissingCount = currMissingCount;
            currMissingCount += arr[i+1]-arr[i]-1;
           }

          if(currMissingCount>=k)
           {
            kthMissing = arr[i] + (k-prevMissingCount);
            break;
           }
         }

        if(kthMissing==0)
         {
          //There is no missing no less than max element in array
          kthMissing = arr[n-1] + (k-currMissingCount);
         } 

        return kthMissing;
    }
};