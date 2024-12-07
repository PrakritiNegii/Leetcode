/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) 
  {
    if(head==NULL || head->next==NULL) 
      return head;
    int i = 1;
    struct ListNode* leftN = head, *beforeL = head;
    while(i!=left)
     {
      beforeL = leftN;
      leftN = leftN->next;
      i++;
     }
    struct ListNode *curr = leftN, *prev = NULL, *next;
    while(i!=right+1)
     {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      i++;
     }
    leftN->next = curr;
    if(left==1) return prev;
    beforeL->next = prev;
    return head;
  }