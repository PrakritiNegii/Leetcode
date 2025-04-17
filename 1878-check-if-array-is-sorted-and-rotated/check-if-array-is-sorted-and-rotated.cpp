class Solution {
public:
    bool check(vector<int>& nums) {
      int i=0;
      int pos=0;
      int c=0;
      do
       {
        int next = (i+1)%nums.size();
        if(nums[i]>nums[next]) c++;
        if(c>1)
         break;
        i=next;
       }while(pos!=i); 

      if(c<=1) return true;
      else return false;
    }
};