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
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    //Rotate 0 degree (already equal) or 360 degree
    //check if equal
        if(isEqual(mat,target)) return true;

        int n = mat.size();

        //Rotate 90 degree clockwise once
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
    //check if equal
        if(isEqual(mat,target)) return true;
        
    //Rotate 180 degree clockwise once
        for(int i=0; i<n; i++) //Reversing each row
         {
          reverse(mat[i].begin(),mat[i].end());
         }
        for(int j=0; j<n; j++) //Reversing each column
         {
          int i=0, k=n-1;
          while(i<k)
           {
            swap(mat[i][j],mat[k][j]);
            i++;
            k--;
           }
         }
    //check if equal
        if(isEqual(mat,target)) return true;

        //Rotate 270 degree clockwise once (90 degree counter-clockwise)
        for(int i=0; i<n; i++) //Transpose matrix
         {
          for(int j=i+1; j<n; j++)
           {
            swap(mat[i][j],mat[j][i]);
           }
         }
        for(int j=0; j<n; j++) //Reversing each column
         {
          int i=0, k=n-1;
          while(i<k)
           {
            swap(mat[i][j],mat[k][j]);
            i++;
            k--;
           }
         }
    //check if equal
        if(isEqual(mat,target)) return true;

        return false;
    }
};