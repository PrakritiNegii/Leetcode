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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp1 = head;
        ListNode *temp2 = NULL;

        int i = 1;
        while(temp1!=NULL)
         {
          if(i>=n+1)
           {
            if(temp2==NULL) temp2 = head;
            else temp2 = temp2->next;
           }
          temp1 = temp1->next;
          i++;
         }

        if(temp2==NULL) return head->next;

        temp2->next = temp2->next->next;
        return head;
    }
};