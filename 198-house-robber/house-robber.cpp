class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size()-1;
        vector<int> dp(size+1,-1);
        int moneyA = getMoney(nums,size,dp);
        int moneyB = INT_MIN;
        if(size>0)
          moneyB = getMoney(nums,size-1,dp);
        return max(moneyA,moneyB);
    }
    int getMoney(vector<int>& nums, int n, vector<int>&dp)
     {
      if(n<=1) return nums[n];
      if(dp[n]!=-1) return dp[n];
      int maxMoney = INT_MIN;
      for(int i=2; i<=n; i++)
       {
        cout<<"\nindex: "<<n<<"\tvalue: "<<nums[n];
        int money = nums[n] + getMoney(nums,n-i,dp);
        cout<<"\tmoney: "<<money;
        maxMoney = max(money,maxMoney);
        cout<<"\tMaxmoney: "<<maxMoney;
       }
      return dp[n] = maxMoney;
     }
};