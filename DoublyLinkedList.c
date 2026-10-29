#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *left,*right;
};
//INSERTION
struct node *insert(struct node *start,int data){
struct node *t=malloc(sizeof(struct node));
t->data=data;
t->left=NULL;
t->right=start;
if(start!=NULL)
start->left=t;
return t;
}
//SEARCH
struct node *search(struct node *start,int item){
while(start!=NULL){
if(start->data==item)
return start;
start=start->right;
}
return  NULL;
}
//DELETION
struct node *delete(struct node *start,struct node *t){
if(t->left!=NULL)
t->left->right=t->right;
else
start=t->right;
if(t->right!=NULL)
t->right->left=t->left;
free(t);
return start;
}
int main(){
struct node *l1=NULL,*t;
int opt,data;
do{
printf("\n1.Insert\n2.Search\n3.Delete\n4.Exit\n");
printf("Enter option: ");
scanf("%d",&opt);
switch(opt){
case 1:
printf("Enter data: ");
scanf("%d",&data);
l1=insert(l1,data);
break;
case 2:
printf("Enter element to search: ");
scanf("%d",&data);
t=search(l1,data);
if(t==NULL)
printf("Not found\n");
else
printf("Found\n");
break;
case 3:
printf("Enter item to delete: ");
scanf("%d",&data);
t=search(l1,data);
if(t!=NULL){
l1=delete(l1,t);
printf("Item deleted\n");
}else{
printf("Item does not exist");
}
break;
case 4:
printf("Exit\n");
break;
default:
printf("Invalid Option\n");
}
}
while(opt!=4);
return 0;
}
