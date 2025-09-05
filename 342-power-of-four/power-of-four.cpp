class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        double power = log10(n)/log10(4);
        int intPower = (int) power;

        if(power>intPower) return false;
        else return true;        
    }
};

