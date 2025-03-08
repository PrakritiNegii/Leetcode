class Solution {
public:
    int trap(vector<int>& height) 
     {
        int water = 0;
        int left = 0, right = 0, min = 0;
        int i=0, j=height.size()-1;

        while(i<=j)
         {
          if(left<right)
            min = left;
          else 
            min = right;
          if(height[i]>=left)
           {
            left = height[i];
            i++;
           }
          else if(height[i]<left && left==min)
           {
            water = water + min - height[i];
            i++;
           }
          if(height[j]>=right)
           {
            right = height[j];
            j--;
           }
          else if(height[j]<right && right==min)
           {
            // if(left==min)
            //   continue;
            if(left!=min)
             { 
               water = water + min - height[j];
               j--;
             }
           }
         }
      return water;
    }
};