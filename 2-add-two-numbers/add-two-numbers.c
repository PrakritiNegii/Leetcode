/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
 {
  struct ListNode *l3=NULL, *p=NULL, *r=NULL;
  int sum, carry = 0;
  
  while(l1 != NULL || l2 != NULL)
   {
    if(l1==NULL)
      sum = 0 + l2->val + carry;
    else if(l2==NULL)
           sum = l1->val + 0 + carry;
         else
             sum = l1->val + l2->val + carry;

    carry = 0;
    if(sum/10 != 0)
      {
        carry = sum / 10;
        sum = sum % 10;
      }

    p = (struct ListNode*) malloc(sizeof(struct ListNode));

    p->val = sum;

    if(l3==NULL && r==NULL) 
      {
        r = l3 = p;
      }
    else
      {
        r->next = p; 
        r = p;
      }
    if(l1!=NULL)
      l1 = l1->next;
    if(l2!=NULL)
      l2 = l2->next;
   }

  if(carry!=0)
   {
    p = (struct ListNode*) malloc(sizeof(struct ListNode));
    if(p!=NULL)
    {
      p->val = carry;
      r->next = p; 
      r = p;
    }
   }  
  r->next = NULL;

  return l3;
 }