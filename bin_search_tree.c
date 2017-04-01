#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node* insert(int,struct node*);
void preorder(struct node*);
void main()
{
	struct node *head;
	head=NULL;
	int n,i,num;
	printf("enter the number of elements you want to enter\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the number\n");
		scanf("%d",&num);
		head=insert(num,head);
	}	
	preorder(head);
	printf("enter the element you want to delete\n");
	scanf("%d",&n);
}
struct node* insert(int num,struct node *head)
{
	struct node* temp;
	if(head==NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=num;
		temp->left=NULL;
		temp->right=NULL;
		//printf("\n value returned");
		return temp;
	}
	else
	{
		if(num>head->data)	
			head->right=insert(num,head->right);
		else
			head->left=insert(num,head->left);
		return head;	
	}
}


void preorder(struct node *head)
{
	if(head!=NULL)
	{
		preorder(head->left);
		printf("%d->",head->data);
		preorder(head->right);
	}
	else return;
}
