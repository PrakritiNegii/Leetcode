class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int value2 = target - nums[i];
            if (hashTable.find(value2) != hashTable.end()) //or hashTable.count(value2) , returns 1 or 0
            /*hashTable.find(value2) does not return a bool.

It returns an iterator pointing either to the element (if found) or hashTable.end() (if not found).*/
            {
                return {hashTable[value2], i};
            }
            hashTable[nums[i]] = i;
        }

        return {}; // No solution found
    }
};