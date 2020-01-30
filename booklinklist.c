//BOOK MANAGEMENT SYSTEM USING LINKED LIST

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nde
{
	char book[20];
	char author[20];
	struct nde *next;
}node;

void create(node *head,int n)
{
	int i;
	node *last,*temp,*newnode;
	last=head;

	for(i=0;i<n;i++)
	{
		newnode=(node*)malloc(sizeof(node));
		newnode->next=NULL;
		printf("\nEnter the book name:");
		scanf("%s",&newnode->book);
		printf("\nEnter the author name:");
		scanf("%s",&newnode->author);
		last->next=newnode;
		last=newnode;
	}
}

//insert at end
void insert(node *head,char x[20],char y[20])
{
	node *temp,*newnode;
	newnode=(node*)malloc(sizeof(node));
	strcpy(newnode->book,x);
	strcpy(newnode->author,y);
	newnode->next=NULL;
	for(temp=head;temp->next!=NULL;temp=temp->next);
	temp->next=newnode;
}

//delete from any position
void delete(node *head,int pos)
{
	int i;
	node *temp,*temp1;
	for(temp=head,i=1;(temp->next!=NULL)&&(i<=pos-1);i++)
	{
		temp=temp->next;
	}
	if(temp->next==NULL)
	{
		printf("\nOut of range!!");
	}
	temp1=temp->next;
	temp->next=temp1->next;
	free(temp1);
}

//update book
void update(node *head,char bk[20])
{	node *temp;
	char newbk[20],aut[20];
	int flag=0;
	for(temp=head->next;temp!=NULL;temp=temp->next)
	{
		if(strcmp(bk,temp->book)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		printf("\nEnter the new bookname:");
		scanf("%s",newbk);
		printf("\nEnter the author:");
		scanf("%s",aut);
		strcpy(temp->book,newbk);
		strcpy(temp->author,aut);
	}
	else
		printf("\nBook doesnot exist.!!!");
}

//display
void disp(node *head)
{
	node *temp;
	int i;
	printf("\n\n\nBOOK\tAUTHOR");
	for(temp=head->next;temp!=NULL;temp=temp->next)
	{
		printf("\n%s\t%s",temp->book,temp->author);
	}
	printf("\n");
}

void main()
{
	int ch,n,pos;
	char x[20],y[20],bk[20],b[20];
	node* head;
	head=(node*)malloc(sizeof(node));
	head->next=NULL;
	do{
		printf("\n Enter number of books :");
		scanf("%d",&n);
		if(n<=0)
			printf("\n Invalid number of books!");
	}while(n<=0);
	create(head,n);
	disp(head);
	do
	{
		printf("\n\n***M E N U***\n1.Insert new book.\n2.Delete book\n3.Update book\n4.Exit\n Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\n Enter book name:");
					scanf("%s",x);
					printf("\n Enter book author:");
					scanf("%s",y);
					insert(head,x,y);
					disp(head);
				break;
			case 2:printf("\nEnter the position:");
					scanf("%d",&pos);
					if(pos<=0)
						printf("\n Out of range!");
					else
					{
						delete(head,pos);
						disp(head);
					}
				break;
			case 3:printf("\nEnter the bookname to update:");
					scanf("%s",bk);
					update(head,bk);
					disp(head);
				break;
			case 4: exit(1);
				break;
		}
	}while(ch!=4);
}
