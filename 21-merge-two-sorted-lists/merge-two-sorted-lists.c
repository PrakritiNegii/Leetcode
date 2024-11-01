// #include<stdio.h>
// #include<stdlib.h>

// typedef struct ListNode
//  {
//   int val;
//   struct ListNode *next;
//  }sl;
 
//  void create(sl**, sl**);
//  struct ListNode* mergeTwoLists(struct ListNode*, struct ListNode*);
//  void display(sl*);
 
//  int main()
//   {
//    sl *f1=NULL, *r1=NULL, *f2 = NULL, *r2 = NULL;
//    int ch, c;
//    do
//     {
//      printf("\nEnter: 1 to CREATE a node in LIST 1.\n       2 to CREATE a node in LIST 2.\n");
//      printf("       3 to MERGE two lists.\n       4 to DISPLAY list.\n");
//      printf("\nEnter your choice:\n");
//      scanf("%d",&ch);
//      switch(ch)
//       {
//        case 1:
//          create(&f1,&r1);  //Input data in ascending order.
//         break;
//        case 2:
//          create(&f2,&r2);  //Input data in ascending order.
//         break;
//        case 3:
//           f1 = mergeTwoLists(f1,f2);
//         break; 
//        case 4:
//          display(f1);
//         break;
//        default:
//          printf("\nInvalid Operation.\n");
//       }
//     }while(ch<=7);
//    return 0;
//   }

// void create(sl **F, sl **R)
//  {
//   sl *p = (sl*) malloc(sizeof(sl));
//   int val;
//   if(p==NULL)
//     printf("\nMemory not allocated.\n");
//   else 
//    {
//     printf("\nInput a value.\n");
//     scanf("%d",&val);
//     p->val = val;
//     if(*F==NULL && *R==NULL)
//       *F = *R = p;
//     else
//      {
//       (*R)->next = p;
//       *R = p;
//      }
//     (*R)->next = NULL;
//    }
//  }

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode *head = NULL, *finalList = NULL;

    while(list1 != NULL && list2 != NULL)
     {
      if(list1->val <= list2->val)
       {
        if(head==NULL)
          head = finalList = list1;
        else
         {
          head->next = list1;
          head = head->next;
         }
        list1 = list1->next;
       }
      else 
       {
        if(head==NULL)
          head = finalList = list2;
        else
         {
          head->next = list2;
          head = head->next;
         }
        list2 = list2->next;
       }
     }
    if(list1!=NULL)
     {
      if(head==NULL)
        head = finalList = list1;
      else
        head->next = list1;
     }
    if(list2!=NULL)
     {
      if(head==NULL)
        head = finalList = list2;
      else
        head->next = list2;
     }
  return finalList;
}

//  void display(sl *F)
//   {
//    if(F==NULL) printf("\nNo list to display.\n");
//    else
//     {
//      int i=1;
//      printf("\nAll nodes are: \n");
//      while(F!=NULL)
//       {
//        printf("Node %d: %d\n",i,F->val);
//        F = F->next;
//        i++;
//       }  
//     }
//   }