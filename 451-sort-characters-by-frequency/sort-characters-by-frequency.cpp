class Solution {
public:
    string frequencySort(string s) {
        int small[26] = {0};
        int capital[26] = {0};
        int nums[10] = {0};
        priority_queue <pair<int,char> > pq;
        for(int i=0; i<s.size(); i++)
         {
         if(s[i]<=57)
           nums[s[i]-'0']++;
         else if(s[i]<=90)
            capital[s[i]-'A']++;
          else 
            small[s[i]-'a']++;
         }
        for(int i=0; i<26; i++)
         {
          if(small[i]>0) 
            pq.push({small[i],i+'a'});
          if(capital[i]>0) 
            pq.push({capital[i],i+'A'});
          if(i>9 || nums[i]==0) continue;
            pq.push({nums[i],i+'0'});
         }
        s = "";
        while(!pq.empty())
         {
          int freq = pq.top().first;
          char ch = pq.top().second;
          pq.pop();
          while(freq!=0)
           {
            s += ch;
            freq--;
           }
         }
      return s;
    }
};