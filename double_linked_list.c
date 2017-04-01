#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
}*head,*temp;

struct node* insert_begin(struct node *head,int d){
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = d;
	if(head!=NULL){
		temp->right = head;
		temp->left = NULL;
		head->left = temp;
		head = temp;
	}
	else{
		temp->right = NULL;
		temp->left = NULL;
		head = temp;
	}
	return head;
}

void display(struct node* head){
	while(head!=NULL){
		printf("%d->",head->data);
		head = head->right;
	}
	printf("\n");
}

void insert_pos(struct node* head, int pos, int d){
	int flag = 0;
	while(pos>1){
		head=head->right;
		if(head==NULL){
			flag=1;
			break;
		}
		pos--;
	}
	if(flag==0){
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = d;
		temp->right = head->right;
		temp->left = head;
		head->right = temp; 
	}
	else	printf("Illegal position\n");
}

int delete_pos(struct node* head, int pos){
	int flag = 0,d;
	while(pos>=1){
		head=head->right;
		if(head==NULL){
			flag=1;
			break;
		}
		pos--;
	}
	if(flag==0){
		d = head->data;
		head->left->right = head->right;
		head->right->left = head->left;
		head->left = NULL;
		head->right = NULL;
		free(head);
		return d;
	}
	else	printf("Illegal position\n");	
}

struct node* reverse(struct node* head){
	struct node *x,*y;
	while(head->right!=NULL)
		head = head->right;
	temp = head;
	printf("Current position: %d\n",head->data);
	while(1){
		x = temp->left;
		temp->left = temp->right;
		temp->right = x;
		temp=x;
		if(temp==NULL)
			break;
	}
	return head;
}

int main(int argc, char *argv[]){
	head = NULL;
	int i,n,d;
	printf("Enter the number of elements\n");
	scanf("%d",&n); 
	for(i=0;i<n;i++){
		scanf("%d",&d);
		head = insert_begin(head,d);
	}
	display(head);
	printf("enter element\n");
	scanf("%d",&d);
	printf("enter position\n");
	scanf("%d",&n);
	insert_pos(head,n,d);
	display(head);
	printf("enter position of deletion\n");
	scanf("%d",&n);
	printf("element deleted is %d\n",delete_pos(head,n));
	display(head);
	head = reverse(head);
	display(head);
	return 0;
}
