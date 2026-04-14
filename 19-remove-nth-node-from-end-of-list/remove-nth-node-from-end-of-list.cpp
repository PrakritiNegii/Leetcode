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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;

        ListNode *temp = head;
        while(temp!=NULL)
         {
          size++;
          temp = temp->next;
         }

        if(n==size) return head->next;

        temp = head;
        n = (size - n); //position of node before the one to be removed
        int i = 1;
        while(i<n)
         {
          temp = temp->next;
          i++;
         }

        temp->next = temp->next->next;

        return head;
    }
};