class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        int arr[255] = {0};
        int start=0, end=0;
        int i=1;
        int maxlen = 1, len = 1;
        arr[s[0]]++;
        while(i<s.size())
         {
          if(arr[s[i]]==0)
           {
            arr[s[i]]++;
            end = i;
           }
          else if(arr[s[i]]==1)
           {
            while(start<=end)
             {
              arr[s[start]]--;
              start++;
              if(arr[s[i]]==0) 
               {
                arr[s[i]]++; 
                end = i;
                break;
               }
             }
            if(end<start)
             {
              end = start;
             }
           }
          i++;
          len = end-start+1;
          maxlen = max(maxlen,len);
         }
        return maxlen;
    }
};