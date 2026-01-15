class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        
        int i=0;
        int len = s.size();

        vector<string> zigzag(numRows);

        int j=0;
        int increment = true;
        while(i<len) 
         {
          zigzag[j] += s[i];
          i++;
          if(increment) j++;
          else j--;
          if(j==numRows-1) increment = false;
          if(j==0) increment = true;
         }

        string ans = "";
        for(int i=0; i<numRows; i++)
         {
          ans+=zigzag[i];
         }

        return ans;
    }
};