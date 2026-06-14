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
       ListNode *temp = head;
       ListNode *head2 = head;

       while(temp!=NULL)
        {
          temp=temp->next->next;
          head2 = head2->next;
        } 

       ListNode *prev = NULL, *curr = head2, *nxt = NULL;
       while(curr!=NULL)
        {
         nxt = curr->next;
         curr->next = prev;
         prev = curr;
         curr = nxt;
        }

       head2 = prev;
       
       int maxVal = 0;
       while(head2!=NULL)
        {
         int sum = head->val + head2->val;
         maxVal = max(maxVal,sum);
         head = head->next;
         head2 = head2->next;
        }

       return maxVal;
    }
};