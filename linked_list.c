#include<stdio.h>
#include<malloc.h>

struct node{
	int val;
	struct node *link;
}*head;


void insert_begin(int num){
	struct node *new;
	new = (struct node*)malloc(sizeof(struct node));
	new->val = num;
	new->link=head;
	head=new;
}

int delete_begin(){
	int value;
	struct node *temp;
	temp = head;
	value = temp->val;
	head=temp->link;
	temp->link=NULL;
	free(temp);
	return value;	
}

int delete_pos(int pos){
	struct node *temp,*temp1,value;
	temp=head;
	if(pos==0){
		value = delete_begin();
		return value;
	}
	while(temp!=NULL){
		if(pos==1){
			temp1=temp;	
		}
		else if(pos==0){
			temp1->link=temp->link;
			temp->link=NULL
			value = temp->val;
			free(temp);
			break;	
		}
		else continue;
		temp=temp->link;
		pos--;
	}
	return value;
}


void insert_pos(int pos,int value){
	struct node *temp,*new;
	temp=head;
	if(pos==0){
		insert_begin(value);
		return;
	}
	else{
		while(temp!=NULL){
			pos--;
			if(pos==0){
				new->val = value;
				new->link = temp->link;
				temp->link = new;
				break;
			}
		}
	}
}

void display(){
	struct node *temp;
	temp=head;
	if(head==NULL){
		printf("empty list");
		return;
	}	
	while(temp!=NULL){
		printf("%d->",temp->val);
		temp=temp->link;
	}
	printf("\n");
}

int main(){
	int len,i,temp;
	head = NULL;
	printf("enter the size of the list\n");
	scanf("%d",&len);
	for(i=0;i<len;i++){
		printf("enter the value to insert\n");
		scanf("%d",&temp);
		insert_begin(temp);
	}
	display();
	temp = delete_begin();
	printf("the value deleted is: %d\n",temp);
	display();
	return 0;
}
