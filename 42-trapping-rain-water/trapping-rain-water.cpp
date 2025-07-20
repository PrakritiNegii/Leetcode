class Solution {
public:
    int trap(vector<int>& height) {
       int maxh = 0;
       int size = height.size()-1;
       for(int i=0; i<=size; i++)
        {
         maxh = max(maxh,height[i]);
        }
       int i=0, j=size;
       int lmax=0, rmax=0;
       int ans=0;

       while(height[i]!=maxh)
        {
         if(height[i]>lmax) lmax = height[i];
         else ans = ans + (lmax-height[i]);
         i++;
        } 
       while(height[j]!=maxh)
        {
         if(height[j]>rmax) rmax = height[j];
         else ans = ans + (rmax-height[j]);
         j--;
        }
       while(i!=j)
        {
         ans = ans + (maxh - height[i]);
         i++;
        }
      return ans;
    }
};