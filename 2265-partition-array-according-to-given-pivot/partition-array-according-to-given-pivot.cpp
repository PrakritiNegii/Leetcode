class Solution {
public:
    vector<int> pivotArray(vector<int>& num, int pivot) {
        int n = num.size();
        vector<int> nums = num;
        stack<int> st;

        int i=0, j=0;
        while(j<n)
         {
          if(nums[j]<pivot) 
           {
            swap(nums[i],nums[j]);
            i++; 
           }
          else if(nums[j]>pivot)
                 {
                  st.push(nums[j]);
                 }
          j++;
         }

        j=n-1;
        while(!st.empty())
         {
          nums[j] = st.top();
          st.pop();
          j--;
         }
        while(j>=i)
         {
          nums[j] = pivot;
          j--;
         }

        return nums;
    }
};