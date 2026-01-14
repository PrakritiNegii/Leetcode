class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<int> ans;

       ans.push_back(1);
       long long val = 1;
       for(int i=1; i<=rowIndex; i++)
        {
         val *= (rowIndex-i+1);
         val /= i;
         ans.push_back(val);
        } 

       return ans;
    }
};