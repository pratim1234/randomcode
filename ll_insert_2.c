#include<stdio.h>
#include<stdlib.h>
struct Node{
   int data;
   struct Node* next;
};
struct Node* head = NULL;
void insert_at_begin(int data){
  struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
   if(head == NULL){
     ptr->data = data;
     ptr->next = NULL;
     head = ptr;
}
else{
   ptr->data = data;
   ptr->next = head;
   head = ptr;
}
}

void insert_at_end(int data){
struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
struct Node* new_ptr = (struct Node*)malloc(sizeof(struct Node));
if(head == NULL){
ptr->data = data;
ptr->next = NULL;
head = ptr;
}
else{
new_ptr = head;
while(new_ptr->next!=NULL){
new_ptr = new_ptr->next;
}
ptr->data = data;
new_ptr->next = ptr;
ptr->next = NULL;
}
}

void display(){
struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
ptr = head;
while(ptr!=NULL){
printf("%d->", ptr->data);
ptr = ptr->next;
}
printf("NULL");
}

void del_at_end(){
struct Node *prev = NULL;
struct Node *curr = head;
while(curr->next!=NULL){
prev = curr;
curr = curr->next;
}
prev->next = NULL;
free(curr);
}
void del_at_beg(){
    struct Node* tmp = head;

    head = tmp->next;

    free(tmp);

}

int main(){
head = NULL;
int n;
printf("Enter numbers to insert at begin ");
scanf("%d", &n);
for(int i=0;i<n;i++){
int x;
scanf("%d", &x);
insert_at_begin(x);
}
display();
printf("\n");
int m;
printf("Enter numbers to insert at end ");
scanf("%d", &m);
for(int i=0;i<m;i++){
int x;
scanf("%d", &x);
insert_at_end(x);
}
printf("\n");
display();
printf("\n");
printf("After one node delete at beg--------");
printf("\n");
del_at_beg();
display();
printf("\n");
printf("After one node delete at end--------");
printf("\n");
del_at_end();
display();
return 0;
}
