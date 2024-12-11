/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) 
{
 struct ListNode *fast = head, *slow = head;
 while(fast && fast->next)
  {
   slow = slow->next;
   fast = fast->next->next;
   if(fast==slow)
       return true;
  } 
 return false;   
}
/*
bool hasCycle(struct ListNode *head) 
{
 struct ListNode *fast = head, *slow = head;
 while(fast && fast->next)
  {
   if(fast->next==slow)
       return true;
   slow = slow->next;
   fast = fast->next->next;
   if(fast==slow)
       return true;
  } 
 return false;   
}
*/
