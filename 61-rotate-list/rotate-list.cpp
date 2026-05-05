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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *temp = head;
        int size = 0;

        while(temp!=NULL)
         {
          temp=temp->next;
          size++;
         }

        if(size<=1 || k==0) return head;

        k = k%size;
        if(k==size) return head;

        temp = head;

        int i=0;
        while(i<k)
         {
          temp = temp->next;
          i++;
         }

        ListNode *newLast = head;
        while(temp->next!=NULL)
         {
          newLast = newLast->next;
          temp = temp->next;
         }

        if(newLast==temp) return head;
        
        ListNode *newHead = newLast->next;
        newLast->next = NULL;

        temp->next = head;

        return newHead;
    }
};