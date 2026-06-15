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
    ListNode* deleteMiddle(ListNode* head) {
       ListNode *slow = head, *fast = head;
       ListNode *temp = NULL;

       while(fast!=NULL && fast->next!=NULL)
        {
         temp = slow;
         fast = fast->next->next;
         slow = slow->next;
        } 

       if(temp==NULL) return NULL;

       temp->next = temp->next->next;

       return head;
    }
};