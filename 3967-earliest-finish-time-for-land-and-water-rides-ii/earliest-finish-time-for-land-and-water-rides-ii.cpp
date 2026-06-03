class Solution {
public:
    int earliestFinishTime(vector<int>& lt, vector<int>& ld, vector<int>& wt, vector<int>& wd) {
        int l = lt.size();
        int w = wt.size();
        int time = INT_MAX;

        int minL = INT_MAX;
        for(int i=0; i<l; i++)
         {
          minL = min(minL,lt[i]+ld[i]);
         }

        int minW = INT_MAX;
        for(int i=0; i<w; i++)
         {
          minW = min(minW,wt[i]+wd[i]);
          time = min(time,max(wt[i],minL)+wd[i]); //min(time,minL+max(wt[i],minL)-minL+wd[i])
         }

        for(int i=0; i<l; i++)
         {
          time = min(time,max(lt[i],minW)+ld[i]);
         }

        return time;
    }
};