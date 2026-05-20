class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
     int n = A.size();
     vector<int> count(n+1,0);
     vector<int> C(n,0);
     
     int cnt = 0;
     for(int i=0; i<n; i++)
      {
       int a = A[i], b = B[i];
       count[a] += 1;
       count[b] += 1;
       if(a==b && count[a]==2) cnt++;
       else
        { 
         if(count[a]==2) cnt++;
         if(count[b]==2) cnt++;
        }
       C[i] = cnt;
      }
     
     return C;
    }
};