class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int n = arr.size();
        
        int up = lower_bound(arr.begin(),arr.end(),target) - arr.begin();
        return up;
    }
};