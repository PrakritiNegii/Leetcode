class Solution {
    public double findMedianSortedArrays(int[] num1, int[] num2) {
        
        int n = num1.length, m = num2.length;
    int size = n+m;
    int[] merged = new int[size];
    int i=0, j=0, k=0;
    while(i<n && j<m)
     {
      if(num1[i]<num2[j])
       {
        merged[k] = num1[i];
        k++;
        i++;
       }

      else
       {
        merged[k] = num2[j];
        k++;
        j++;
       }
     }

     while(i<n)
      {
       merged[k] = num1[i];
       k++;
       i++;
      }

     while(j<m)
      {
       merged[k] = num2[j];
       k++;
       j++;
      }

    if(size%2==0)
      return (merged[size/2-1]+merged[size/2])/2.0;
    else return merged[size/2];
    }
}