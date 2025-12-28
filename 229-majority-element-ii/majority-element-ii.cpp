class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1 = 0, el2 = 0, c1 = 0, c2 = 0;

        // Step 1: Find candidates
        for (int x : nums) {
            if (x == el1) c1++;
            else if (x == el2) c2++;
            else if (c1 == 0) {
                el1 = x;
                c1 = 1;
            }
            else if (c2 == 0) {
                el2 = x;
                c2 = 1;
            }
            else {
                c1--;
                c2--;
            }
        }

        // Step 2: Verify
        c1 = c2 = 0;
        for (int x : nums) {
            if (x == el1) c1++;
            else if (x == el2) c2++;
        }

        vector<int> ans;
        int n = nums.size();
        if (c1 > n / 3) ans.push_back(el1);
        if (c2 > n / 3) ans.push_back(el2);

        return ans;
    }
};
