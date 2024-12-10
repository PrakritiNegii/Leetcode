/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) 
 {
   struct ListNode *slow = head, *fast = head;  
   bool f = true;  
   while(fast->next && fast->next->next)
    {
      fast = fast->next->next;
      slow = slow->next;
    }

   struct ListNode *curr = slow->next, *prev = NULL, *next;
   while(curr)
    {
     next = curr->next;
     curr->next = prev;
     prev = curr;
     curr = next;
    }  
   fast = head;
   while(prev)
    {
     if(prev->val != fast->val)
      {
       f = false;
       break;
      }
     prev = prev->next;
     fast = fast->next;
    }
   return f;
}