class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int n = nums.size();
        int sum = 0;
        int maxStart = 0;
        int maxEnd = 0;
        int start = 0;
        for(int i=0; i<n; i++)
         {
          sum += nums[i];
          if(sum>maxSum)
           {
            maxSum = sum;
            maxStart = start;
            maxEnd = i;
           }
          if(sum<0)
           { 
            sum = 0;
            start = i+1;
           }
         }
        
        cout<<"Max Subarray:"<<endl;
        for(int i=maxStart; i<=maxEnd; i++) 
         {
          cout<<nums[i]<<endl;
         }
       return maxSum;
    }
};