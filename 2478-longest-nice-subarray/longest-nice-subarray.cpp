class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
     {
      int maxsize = 1;
      int left=0;
      int Xor=nums[0], sum=nums[0];
      for(int i=1; i<nums.size(); i++)
       {
        Xor=Xor^nums[i], sum+=nums[i];
          while(Xor!=sum)
           {
            Xor = Xor ^ nums[left];
            sum = sum - nums[left];
            left++;
           }
        maxsize = max(i-left+1,maxsize);
       }
          return maxsize;
     }
};