/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) 
{
 struct ListNode *p=head,*t=NULL; 

 while(p!=NULL)
  {
    if(p->val==val)
     {
      if(t==NULL)  //First node to be deleted.
        {
         head = head->next;
         p = head;
        }
        else
         {
          t->next = p->next;
          p=p->next;
         }
     }
    else
    {
      t=p;
      p=p->next;
    }
  }   
  return head;
}