class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int m1 = 0, m2 = 0;

        int i=0, j=0;
        int index = -1;
        bool is_i = false;
        while(i<n1 && j<n2)
         {
          if(nums1[i]<nums2[j])
           {
            i++;
            is_i = true;
           }
          else
           {
            j++;
            is_i = false;
           }

          index++;
          if(index==(n1+n2-1)/2)
           {
            if(is_i==true) m1 = nums1[i-1];
            else m1 = nums2[j-1];
           }  

          if(index-1==(n1+n2-1)/2)
           {
            if(is_i==true) m2 = nums1[i-1];
            else m2 = nums2[j-1];
           }
         }

        while(i<n1 && index-1<(n1+n2-1)/2)
         {
          i++;
          index++;
          if(index==(n1+n2-1)/2)
            m1 = nums1[i-1];
          if(index-1==(n1+n2-1)/2)
            m2 = nums1[i-1];
         }

        while(j<n2 && index<((n1+n2-1)/2)+1)
         {
          j++;
          index++;
          if(index==(n1+n2-1)/2)
            m1 = nums2[j-1];
          if(index-1==(n1+n2-1)/2)
            m2 = nums2[j-1];
         }

        if((n1+n2)%2==0) return ((double)m1 + (double)m2)/2.0;
        else return (double) m1;
    }
};