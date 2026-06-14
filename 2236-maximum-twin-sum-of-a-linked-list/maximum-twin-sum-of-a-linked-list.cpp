/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
       int twins = 0;
       ListNode *temp = head;

       while(temp!=NULL)
        {
          temp=temp->next->next;
          twins++;
        } 

       vector<int> store(twins,0);
       int i=0;
       temp = head;

       while(temp!=NULL)
        {
         int idx = i;
         if(i>=twins) idx = (twins*2)-i-1;
         store[idx] += temp->val;
         temp = temp->next;
         i++;
        }

       int maxVal = 0;
       for(int i=0; i<twins; i++)
         maxVal = max(maxVal,store[i]);

       return maxVal;
    }
};