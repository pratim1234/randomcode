// intializing a circular linked list in c prog.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
  struct node *next;
};

void insertAtBeg(struct node **head, int data){
   struct node *current = *head;
   struct node *newnode = (struct node*)malloc(sizeof(struct node);

   if(!newnode){
       printf("memory error");
      }
   newnode->data=data;
  while(current->next!=*head)
      current = current=>next;
 newnode->next=newnode;
   
   if(*head == NULL)
       *head = newnode;
   else{

      newnode->next = *head;
       current->next = newnode;
       }