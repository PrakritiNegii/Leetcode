class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size();

        unordered_set<int> st;
        for(int i=0; i<n1; i++)
         {
          string str = to_string(arr1[i]);
          for(int j=0; j<str.size(); j++)
           {
            int val = stoi(str.substr(0,j+1));
            st.insert(val);
           }
         }

        int maxLen = 0;
        for(int i=0; i<n2; i++)
         {
          string str = to_string(arr2[i]);
          for(int j=maxLen; j<str.size(); j++)
           {
            int val = stoi(str.substr(0,j+1));

            if(st.count(val)!=0) maxLen = j+1;
           }
         }

        return maxLen;
    }
};