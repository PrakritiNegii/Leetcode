class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        sort(citations.rbegin(),citations.rend());

        //sort(citations.begin(),citations.end(),greater<int>());

        int hIndex = 0;
        for(int i=0; i<n; i++) //i+1 is temp value of hIndex which at max can be n 
         {
          if(citations[i]>=(i+1))
            hIndex = i+1;
          else 
            break;
         }
        return hIndex;
    }
};