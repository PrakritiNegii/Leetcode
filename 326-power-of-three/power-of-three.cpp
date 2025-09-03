class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        double power = log10(n)/log10(3);
        int intPower = (int) power;

        if(power>intPower) return false;
        else return true;
    }
};