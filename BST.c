#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left,*right;
};
//INSERT
struct node* insert(struct node *root,int x)
{
if(root==NULL)
{
root=malloc(sizeof(struct node));
root->data=x;
root->left=root->right=NULL;
}
else if(x<root->data)
root->left=insert(root->left,x);
else if(x>root->data)
root->right=insert(root->right,x);
else
printf("Duplicate value\n");
return root;
}
//DISPLAY
void display(struct node *root)
{
if(root!=NULL)
{
display(root->left);
printf("%d\t",root->data);
display(root->right);
}
}
//SEARCH
void search(struct node *root,int x)
{
if(root==NULL)
printf("Not Found\n");
else if(root->data==x)
printf("Found\n");
else if(x<root->data)
search(root->left,x);
else
search(root->right,x);
}
//FIND MINIMUM
struct node* minimum(struct node *root)
{
while(root->left!=NULL)
root=root->left;
return root;
}
//DELETE
struct node* delete(struct node *root,int x)
{
if(root==NULL)
return NULL;
if(x<root->data)
root->left=delete(root->left,x);
else if(x>root->data)
root->right=delete(root->right,x);
else
{
struct node *temp;
if(root->left==NULL)
{
temp=root->right;
free(root);
return temp;
}
if(root->right==NULL)
{
temp=root->left;
free(root);
return temp;
}
temp=minimum(root->right);
root->data=temp->data;
root->right=delete(root->right,temp->data);
}
return root;
}
//MAIN
int main()
{
struct node *root=NULL;
int ch,x;
while(1)
{
printf("\n1.Insert");
printf("\n2.Display");
printf("\n3.Search");
printf("\n4.Delete");
printf("\n5.Exit");
printf("\nEnter your choice: ");
scanf("%d",&ch);
switch(ch){
case 1:
printf("Enter value: ");
scanf("%d",&x);
root=insert(root,x);
break;
case 2:
display(root);
break;
case 3:
printf("Enter value: ");
scanf("%d",&x);
search(root,x);
break;
case 4:
printf("Enter value: ");
scanf("%d",&x);
root=delete(root,x);
break;
case 5:
exit(0);
default:
printf("Wrong Choice");
}
}
return 0;
}
