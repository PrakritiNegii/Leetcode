class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size()-1;

        while(left<=right)
         {
          int mid = (right-left)/2 + left;

          int missing = arr[mid] - mid - 1;

          if(missing<k) //more missing numbers ahead
            left = mid + 1;
          else //find the no just before which missing nos exist (smallest no in array greater than the missing no)
            right = mid - 1;
         }

        if(left==0) //missing no exists before first no
          return k;
        //left is the index after the missing number, i.e., arr[left]>missing no
        int prevMissingNos = arr[left-1] - (left-1) - 1;
        return arr[left-1] + (k-prevMissingNos);
    }
};