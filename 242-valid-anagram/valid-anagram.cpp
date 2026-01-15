class Solution {
public:
    bool isAnagram(string s, string t) {
      unordered_map<char,int> hashmap;

      int sSize = s.size();
      int tSize = t.size();

      if(sSize!=tSize) return false;

      int i=0;
      while(i<sSize)
       {
        char sstr = s[i];
        hashmap[sstr]++;
        char tstr = t[i];
        hashmap[tstr]--;
        i++;
       }

       for(auto x : hashmap)
        {
         if(x.second!=0) return false;
        }

       return true;
    }
};