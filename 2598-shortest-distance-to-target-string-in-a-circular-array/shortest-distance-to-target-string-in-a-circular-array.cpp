class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
       if(target==words[startIndex]) return 0;

       int n = words.size();
       int i = (startIndex+1)%n;
       int j = (startIndex-1+n)%n; 
       int steps = 0;
       
       while(i!=startIndex)
        {
         if(target==words[i] || target==words[j]) return steps+1;
         
         i = (i+1)%n;
         j = (j-1+n)%n;

         steps++;
        }

       return -1;
    }
};