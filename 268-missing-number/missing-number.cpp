class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int _xor = 0;
        //Finding xor of all array elements and all n whole numbers.
        //xor of same element even times is zero
        //Hence, the xor of all elements except the one occuring one time will be zero.
        //So at the end xor will store the value of missing element, that is, the one that occurs only once.
        for(int i=0; i<n; i++)
         {
          _xor = _xor ^ nums[i] ^ (i+1);
         }

        return _xor;
    }
};