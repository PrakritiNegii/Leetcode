class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        frequency[0] = 1;   // IMPORTANT
        //Assuming 0 has frequency 1 for cases where k is an element itself

        int sum = 0;
        int count = 0;

        for (int x : nums) {
            sum += x;

            if (frequency.count(sum - k))
                count += frequency[sum - k];

            frequency[sum]++;
        }
        return count;
    }
};
