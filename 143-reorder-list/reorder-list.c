/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 //could use stack instead of reversal
void reorderList(struct ListNode* head) 
 {
   struct ListNode *slow, *fast, *head2;
   slow = fast = head; 
   while(fast->next && fast->next->next)
    {
     slow = slow->next;
     fast = fast->next->next;
    }  
   struct ListNode *curr = slow->next, *next, *prev = NULL;
   slow->next = NULL;
   while(curr!=NULL)
    {
     next = curr->next;
     curr->next = prev;
     prev = curr;
     curr = next;
    }
   head2 = prev;
   slow = head;
   fast = head;
   while(head2!=NULL)
    {
     fast = fast->next;
     slow->next = head2;
     head2 = head2->next;
     slow->next->next = fast;
     slow = fast;
    }
 }