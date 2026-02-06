class Solution {
public:
    int countMonobit(int n) {
        int count = 1;   // counts 0
        long long curr = 1;

        while (curr <= n) {
            count++;
            curr = (curr << 1) | 1;
        }

        return count;
    }
};