#include <stdio.h>
#include <stdlib.h>
typedef struct n_list
{
	int data;
	struct n_list* link;
}node;
node * head;
node * createNode()
{
	node * tmp;
	tmp=(node *)malloc(sizeof(node));
	return tmp;
}

void Insert_at_beginning(int data)
{
	node * newnode=createNode();
	newnode->data=data;
	newnode->link=NULL;
	if (head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->link=head;
		head=newnode;
	}
}

void Insert_at_end(int data)
{
	node * newnode=createNode();
	newnode->data=data;
	newnode->link=NULL;
	if (head==NULL)
	{
		head=newnode;
	}
	else
	{
		node * tmp;
		tmp=head;
		while(tmp->link!=NULL)
		{
			tmp=tmp->link;
		}
		tmp->link=newnode;
	}
}

void Insert_Before(int data,int before)
{
	node * newnode=createNode();
	newnode->data=data;
	newnode->link=NULL;
	if (head==NULL)
	{
		printf("The linked list is already empty\n");
	}
	else if (head->data==before)
	{
		node * tmp;
		tmp=head;
		head=newnode;
		newnode->link=tmp;
	}
	else
	{
		node * tmp;
		node * prev;
		tmp=head;
		prev=head;
		while (tmp->link!=NULL && tmp->data!=before)
		{
			prev=tmp;
			tmp=tmp->link;
		}
		if (tmp->data!=before)
		{
			printf("%d element is not present in any of the nodes! Sorry !\n",before);
		}
		else
		{
			newnode->link=tmp;
			prev->link=newnode;
		}
	}
}

void Insert_After(int data,int after)
{
	node * newnode=createNode();
	newnode->data=data;
	newnode->link=NULL;
	if (head==NULL)
	{
		printf("The linked list is already empty\n");
	}
	else
	{
		node * tmp;
		tmp=head;
		while (tmp->link!=NULL && tmp->data!=after)
		{
			tmp=tmp->link;
		}
		if (tmp->data!=after)
		{
			printf("%d element is not present in any of the nodes! Sorry !\n",after);
		}
		else
		{
			newnode->link=tmp->link;
			tmp->link=newnode;
		}
	}
}

void Insert_Nth_Position(int data,int position)
{
	int c=1;
	node * newnode=createNode();
	newnode->data=data;
	newnode->link=NULL;
	if (head==NULL && position!=1)
	{
		printf("The linked list is already empty\n");
	}
	else if (position==1)
	{
		node * tmp;
		tmp=head;
		head=newnode;
		newnode->link=tmp;
	}
	else
	{
		node * tmp;
		node * prev;
		tmp=head;
		prev=head;
		while (tmp->link!=NULL && c<position)
		{
			c++;
			prev=tmp;
			tmp=tmp->link;
		}
		if (c!=position)
		{
			printf("No nodes are present at %dth position in the linked list! Sorry!\n",position);
		}
		else
		{
			newnode->link=tmp;
			prev->link=newnode;
		}
	}
}

node * Del_Start()
{
	if (head==NULL)
	{
		printf("The linked List is already empty\n");
		return head;
	}
	if (head->link==NULL)
	{
		free(head);
		head=NULL;
	}
	else
	{
		node * tmp;
		tmp=head;
		head=tmp->link;
		free(tmp);
	}
}

node * Del_End()
{
	if (head==NULL)
	{
		printf("The linked list is already empty\n");
		return head;
	}
	if (head->link==NULL)
	{
		free(head);
		head==NULL;
	}
	else
	{
		node * tmp;
		node * prev;
		prev=head;
		tmp=head;
		while(tmp->link!=NULL)
		{
			prev=tmp;
			tmp=tmp->link;
		}
		prev->link=NULL;
		free(tmp);
	}
}

void Del_Before(int before)
{
	node * tmp;
	node * prev;
	if (head==NULL)
	{
		printf("The linked list is already empty\n");
	}
	else if (head->data==before)
	{
		printf("There is no data before this\n");
	}
	else if (head->link==NULL)
	{
		printf("There is no data after this\n");
	}
	else if (head->link->data==before)
	{
		tmp=head;
		head=tmp->link;
		free(tmp);
	}
	else
	{
		tmp=head;
		prev=head;
		while (tmp->link->link != NULL && tmp->link->data != before)
		{
			prev = tmp;
			tmp = tmp->link;
		}

		if (tmp->link->data != before)
		{
			printf("%d element is not present in any of the nodes! Sorry !\n",before);
		}
		else
		{
			prev->link = tmp->link;
			free(tmp);
		}	
	}
}


void Del_After(int after)
{
	node * tmp;
	node * prev;
	if (head==NULL)
	{
		printf("The linked list is already empty\n");
	}
	else if (head->data==after)
	{
		if (head->link==NULL)
		{
			printf("There is no data after this\n");
		}
		else
		{
			tmp=head;
			tmp=tmp->link;
			head->link=tmp->link;
			free(tmp);
		}
	}
	else
	{
		tmp=head;
		while (tmp->link!=NULL && tmp->data!=after)
		{
			tmp=tmp->link;
		} 	
		if (tmp->data!=after)
		{
			printf("%d element is not present in any of the nodes! Sorry!\n",after);
		}
		else
		{
			prev=tmp;
			tmp=tmp->link;
			prev->link=tmp->link;
			free(tmp);
		}
	}
}

node * Del_Nth_Position(int position)
{
	int c = 1;
	node *tmp, *prev;
	if (head==NULL)
	{
		printf("The linked list is already empty\n");
		return head;
	}
	if (position == 1)
	{
		tmp = head;
		head = tmp->link;
		free(tmp);
	}
	else
	{
		prev=head;
		tmp=head;
		while (tmp->link != NULL && c<position)
		{
			c++;
			prev = tmp;
			tmp = tmp->link;
		}
		if (c != position)
		{
			printf("No nodes are present at %dth position in the linked list! Sorry!\n",position);
		}
		else
		{
			prev->link = tmp->link;
			free(tmp);
		}
	}
}

node * Del_Nth_Data(int key)
{
	node *tmp, *prev;
	if (head==NULL)
	{
		printf("The linked list is already empty\n");
		return head;
	}
	if (head->data == key)
	{
		if (head->link == NULL)
		{
			free(head);
			head = NULL;
		}
		else
		{
			tmp = head;
			head = tmp->link;
			free(tmp);
		}
	}
	else
	{
		prev=head;
		tmp=head;
		while (tmp->link != NULL && tmp->data != key)
		{
			prev = tmp;
			tmp = tmp->link;
		}
		if (tmp->data != key)
		{
			printf("%d element is not present in any of the nodes! Sorry !\n",key);
		}
		else
		{
			prev->link = tmp->link;
			free(tmp);
		}	
	}
}

void Reverse_List()
{
	node *tmp = NULL, *next;
	while (head != NULL)
	{
		next = head->link;
		head->link = tmp;
		tmp = head;
		head = next;
	}
	head = tmp;
}

void Display_List()
{
	node * tmp;
	tmp=head;
	while (tmp!=NULL)
	{
		printf("%d ",tmp->data);
		tmp=tmp->link;
	}
	printf("\n");
}

int main()
{
	int i,j,l,d,cre_choice,del_choice,after,before,position,key,counter;
	while(1)
	{
		printf("------USER MENU------\n");
		printf("1. Insert from the beginning\n");
		printf("2. Insert from the end\n");
		printf("3. Insert after some element\n");
		printf("4. Insert before some element \n");
		printf("5. Insert at nth position in the list\n");
		printf("6. Reverse list\n");
		printf("7. Delete menu\n");
		printf("8. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&cre_choice);
		
		if (cre_choice == 1)
		{
		
				printf("Enter the length of the list: ");
	        	scanf("%d",&l);
	        	for(i = 0; i<l; i++)
	        	{
		        	printf("Enter the data: ");
				scanf("%d",&d);
				Insert_at_beginning(d);
			}
			printf("List is created\n");
			Display_List();
			
		}
		
		else if (cre_choice == 2)		
	    {	
	    	
	    
			printf("Enter the length of the list: ");
		    scanf("%d",&l);
	        for(i = 0; i<l; i++)
	        {
		        printf("Enter the data: ");
				scanf("%d",&d);
				Insert_at_end(d);
			}
			printf("List is created\n");
			Display_List();
			
		}
				
		else if (cre_choice == 3)
		{
			printf("Enter the data: ");
			scanf("%d",&d);
			printf("Enter the value after: ");
			scanf("%d",&after);
			Insert_After(d,after);
			Display_List();
		
		}
		
		else if (cre_choice == 4)
		{
			printf("Enter the data: ");
			scanf("%d",&d);
			printf("Enter the value before: ");
			scanf("%d",&before);
			Insert_Before(d,before);
			Display_List();
			
		}

		else if (cre_choice == 5)
		{
			printf("Enter the data: ");
			scanf("%d",&d);
			printf("Enter the position: ");
			scanf("%d",&position);
			Insert_Nth_Position(d,position);
			Display_List();
		
		}
		
		else if (cre_choice == 6)
		{
			Reverse_List();
			Display_List();
		}

		else if (cre_choice == 7)
		{
			while(1)
			{
				printf("------Delete Menu------\n");
				printf("1. From the beginning\n");
				printf("2. From the end\n");
				printf("3. Delete after\n");
				printf("4. Delete before\n");
				printf("5. Delete at nth position\n");
				printf("6. Delete nth data\n");
				printf("7. Exit\n");
				printf("Enter your choice: ");
				scanf("%d",&del_choice);
				if (del_choice == 1)
				{
					
					if (Del_Start()!=NULL)
					{
						Display_List();
					}
				}
				
				else if (del_choice == 2)
				{
					
					if (Del_End()!=NULL)
					{
						Display_List();
					}			
				}

				else if (del_choice == 3)
				{
					printf("Enter after which data you want to delete: ");
					scanf("%d",&after);
					Del_After(after);
					if (head!=NULL)
					{
						Display_List();
					}
					
				}
				
				else if (del_choice == 4)
				{
					printf("Enter before which data you want to dalete: ");
					scanf("%d",&before);
					Del_Before(before);
					if (head!=NULL)
					{
						Display_List();
					}
					
				}
				

				else if (del_choice == 5)
				{
					printf("Enter the position at which you want to delete: ");
					scanf("%d",&position);
					
					if (Del_Nth_Position(position)!=NULL)
					{
						Display_List();
					}
					
				}
				
				else if (del_choice == 6)
				{
					printf("Enter the data which you want to delete: ");
					scanf("%d",&key);
			
					if (Del_Nth_Data(key)!=NULL)
					{
						Display_List();
					}
					
				}
				
				else if (del_choice == 7)
				{
					printf("Exiting delete menu\n");
					break;
				}
				
				else
				{
					printf("Invalid choice\n");
				}
			}
		}
		else if (cre_choice == 8)
		{					
			printf("End\n");
			break;			
		}
		else
		{
			printf("Invalid choice\n");
		}
	}		
return 0;
}
