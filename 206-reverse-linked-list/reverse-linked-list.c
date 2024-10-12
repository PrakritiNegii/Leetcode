/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    
    if (head == NULL) {
        return NULL; // Return NULL if the list is empty
    }

    struct ListNode *last = head, *temp = NULL;
    while(last->next!=NULL) 
      last = last->next;
    
    last->next = head;
    while(head->next!=last)
     {
      temp = last->next;
      last->next = head->next;
      head->next = head->next->next;
      last->next->next = temp;
     }
    head->next = NULL;

  return last;
}