/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head)
{
   if (head == NULL || head->next == NULL)
        return NULL; 

    bool flag = false;
    int c=1, j;
    struct ListNode *slow = head;
    struct ListNode *fast = head->next;
    struct ListNode *temp = NULL;

    while (slow->next != NULL && fast->next != NULL && fast->next->next != NULL ) 
     {
        slow = slow->next;
        fast = fast->next->next;
        if(flag==true && slow!=temp)
          c++;
        else if(flag==true && slow==temp)
                break;
        if (slow == fast) 
         {
           flag = true; 
           temp = slow;
         }    
     }
    if(flag==false)
      return NULL;

    while(head!=temp)
     {
      j=1;
      while(j!=c)
       {
        if(head==temp)
          break;
        temp = temp->next;
        j++;
       }
      if(head==temp)
        break;
      head = head->next;
     }
    return head;
}
