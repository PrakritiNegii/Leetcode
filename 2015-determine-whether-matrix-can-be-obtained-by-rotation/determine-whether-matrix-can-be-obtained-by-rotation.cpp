class Solution {
public:
    bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target)
     {
      int n = mat.size();
      for(int i=0; i<n; i++)
       {
        for(int j=0; j<n; j++)
         {
          if(mat[i][j]!=target[i][j])
            return false;
         }
       }
      return true;
     }

    void rotate90Degree(vector<vector<int>>& mat) {
        int n = mat.size();

        for(int i=0; i<n; i++) //Transpose matrix
         {
          for(int j=i+1; j<n; j++)
           {
            swap(mat[i][j],mat[j][i]);
           }
         }
        for(int i=0; i<n; i++) //Reversing each row
         {
          reverse(mat[i].begin(),mat[i].end());
         }     
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    //Rotate 0 degree (already equal) or 360 degree
    //check if equal
        if(isEqual(mat,target)) return true;

        for(int i=1; i<=3; i++)
         {
          rotate90Degree(mat);
          if(isEqual(mat,target)) return true;
         }

        return false;
    }
};