class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int l = landStartTime.size();
        int w = waterStartTime.size();
        int time = INT_MAX;

        for(int i=0; i<l; i++)
         {
          int tt = landStartTime[i] + landDuration[i];
          for(int j=0; j<w; j++)
           {
            int t = 0;
            if(waterStartTime[j]>tt) t += waterStartTime[j] - tt;
            t += waterDuration[j];

            time = min(time,tt+t);
           }
         }

        for(int i=0; i<w; i++)
         {
          int tt = waterStartTime[i] + waterDuration[i];
          for(int j=0; j<l; j++)
           {
            int t = 0;
            if(landStartTime[j]>tt) t += landStartTime[j] - tt;
            t += landDuration[j];

            time = min(time,tt+t);
           }
         }
        return time;
    }
};