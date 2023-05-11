#include<malloc.h>
#include<stdio.h>
int top;
struct node{
 int data;
 struct node *next;
 struct node *prev;
};
int main()
{
 int choice,n;
 char choice2;
 printf("Enter the value");
 scanf("%d",&n);
 struct node *curr;
 struct node *curr2;
 struct node *new;
 struct node *top;
 new=(struct node*)malloc(sizeof(struct node));
 curr=new;
 curr->data=n;
 top=curr;
 curr->prev=NULL;
do{
 printf("Do you want to push or pop(1/2): ?");
 scanf("%d",&choice);
 switch(choice) {
 case 1: printf("Enter the value: ");
 scanf("%d",&n);
 new=(struct node*)malloc(sizeof(struct node));
 new->data=n;
 new->prev=curr;
 curr=new;
 top=curr;
 printf("The no. pushed inside is %d\n",n);
 break;
 case 2: printf("The no. popped out is %d\n",top->data);
 top=top->prev;
 free(curr);
 curr=top;
 break;
 }
 curr2=top;
 while(curr2!=NULL) {
 printf("%d",curr2->data);
 if(curr2->prev!=NULL) {
 printf("->");
 }
 curr2=curr2->prev;
 }
 printf("Do you want to continue?(y/n): ");
 scanf("%c%c",&choice2,&choice2);
 }while(choice2=='y');
return 0;
}
