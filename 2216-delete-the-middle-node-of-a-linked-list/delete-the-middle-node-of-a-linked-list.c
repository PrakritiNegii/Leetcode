/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) 
{
  struct ListNode *t = NULL, *slow = head, *fast = head;
  while(fast->next != NULL && fast->next->next != NULL)
   {
    t = slow;   //finds the node before the middle node
    fast = fast->next->next;
    slow = slow->next;   //finds the middle node
   }

  if(fast->next!=NULL) //Assuming head is never NULL
    {
      t = slow;
      slow = slow->next;
    }
  if(t!=NULL) 
   {
    t->next = slow->next;
   }
  else 
    head = slow->next;
  free(slow);
  return head;
}