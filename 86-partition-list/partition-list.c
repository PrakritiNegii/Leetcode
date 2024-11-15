/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    if(head==NULL) return head;
    struct ListNode *ahead, *behind, *h = NULL, *temp = NULL;
    ahead = behind = head;
    
    while(ahead!=NULL)
     {
      if(ahead->val < x)
        {
         if(h==NULL) h = temp = ahead;
         else 
          {
            temp->next = ahead;
            temp = temp->next;
          }
         if(ahead==head) head = ahead = behind = head->next /*front->next*/;
         else
          {
            behind->next = ahead->next;
            ahead = ahead->next;
          }
        }
      else
        {
         behind = ahead;
         ahead = ahead->next;
        }
     }
    if(temp!=NULL)
      temp->next = head;
    if(h!=NULL)
      return h;
    else 
      return head;
}