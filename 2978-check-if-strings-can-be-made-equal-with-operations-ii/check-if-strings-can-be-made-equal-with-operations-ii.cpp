class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<int> even(26);
        vector<int> odd(26);
        
        for(int i=0; i<n; i++)
         {
          char one = s1[i]-97;
          char two = s2[i]-97;

          if(i%2==0)
           {
            even[one]++;
            even[two]--;
           }
          else
           {
            odd[one]++;
            odd[two]--;
           }
         }

        for(int i=0; i<26; i++)
         {
          if(odd[i]!=0 || even[i]!=0) return false;
         }

      return true;       
    }
};