/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) 
  {
    if(head==NULL) return head;
    struct ListNode *head2 = head->next, *odd = head, *even = head->next;
    while(odd->next!=NULL && odd->next->next!=NULL)
     {
        odd->next = even->next;
        odd = even->next;

        even->next = odd->next;
        even = odd->next;
     }
    odd->next = head2;
    return head;
}