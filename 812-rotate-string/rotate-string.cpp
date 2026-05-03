class Solution {
public:
    bool rotateString(string s, string goal) {
      if(s.size()!=goal.size())  return false;
      vector<int> start;
      for(int i=0; i<s.size(); i++)
       {
        if(s[i]==goal[0]) start.push_back(i);
       }  

       for(int i=0; i<start.size(); i++)
        {
         int idx = (start[i]+1)%s.size();
         int j = 1;
         bool matches = true;
         while(j<s.size())
          {
           if(goal[j]!=s[idx])
            {
             matches = false;
             break;
            }
           j++;
           idx = (idx+1)%s.size();
          }
         if(matches) return true;
        }
       return false;
    }
};