/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    if(head==NULL) return head;
    struct ListNode *slow, *fast;
    slow = fast = head;
    while(fast->next && fast->next->next)
     {
      slow = slow->next;
      fast = fast->next->next;
     }
    if(fast->next==NULL) return slow;
    else return slow->next;
}