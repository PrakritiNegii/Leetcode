class Solution {
public:
    void rotate(vector<int>& nums, int k) {
     int size = nums.size();
     int r=0;
     //right rotations is equal to size - left rotations
     //so the number of left rotations to be done are:
     int lrots = k%size; 
     vector<int> help(size);
     int c=0, j=0, q=0;
     while(c<size)
      {
        int p = -1;
        j = q;
        int temp = nums[j];
        while(p!=q)
         {
          int jump = (j + lrots) % size;
          int temp2 = nums[jump];
          nums[jump] = temp;
          temp = temp2;

          j = jump;
          p = j;
          c++;
         } 
        
        q++;
      }
    }
};