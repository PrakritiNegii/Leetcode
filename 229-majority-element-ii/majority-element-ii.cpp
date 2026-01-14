class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        pair<int,int> majority;
        pair<int,int> count;

        for(int i=0; i<n; i++)
         {
          if(nums[i]==majority.first)
           {
            count.first++;
           }
          else if(nums[i]==majority.second)
                {
                 count.second++;
                }
               else if(count.first==0) 
                     {
                      majority.first = nums[i];
                      count.first = 1;
                     }
                    else if(count.second==0)
                          {
                           majority.second = nums[i];
                           count.second = 1;
                          }
                         else
                           {
                            count.first--;
                            count.second--;
                           }
         }
        
        count.first=0; count.second=0;
        for(int i=0; i<n; i++)
         {
          if(majority.first==nums[i]) count.first++;
          if(majority.second==nums[i]) count.second++;
         }

        vector<int> ans;
        if(count.first>n/3) ans.push_back(majority.first);
        if(count.second>n/3 && majority.first!=majority.second) ans.push_back(majority.second);

        return ans;
    }
};