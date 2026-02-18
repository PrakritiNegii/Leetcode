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

        // Derivation:
        // The answer is 'k' more than the number of non-missing elements found so far.
        // At the end of the loop, 'start' is the number of elements in the array smaller than the kth missing number.
        // Formula: Result = k + start
        return left + k;
    }
};