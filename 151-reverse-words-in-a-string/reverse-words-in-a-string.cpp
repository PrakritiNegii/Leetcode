class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";

        int left = 0, right = 0;
        string temp = "";
       
        reverse(s.begin(),s.end());
        while(right<n)
         {
          if(left==right && s[right]==' ') 
           {
            left++;
            right++;
            continue;
           }
          if(s[right]==' ')
           {
            reverse(s.begin()+left,s.begin()+right);
            right++;
            left = right;
           }
          else
           {
            right++;
           }
         }
        reverse(s.begin()+left,s.begin()+right);

       int i=0, j=0;
       while(i<n)
        {
         if(s[i]!=' ')
          {
           s[j] = s[i];
           j++; 
          }
         else if(j!=0 && s[i]==' ')
               {
                if(s[i-1]!=' ') 
                  s[j++] = ' ';
               }
          i++;
        }
      if(n>1 && s[j-1]==' ') j--;
    //  s.resize(j); 
    //   s = s.substr(0,j);
      s.erase(j); //Everything after index j including it is removed.
      //Remove characters from the end using pop_back() (loop required)
      return s;
    }
};