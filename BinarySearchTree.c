
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
struct node* insertnode(struct node *root,int item);
struct node* deletenode(struct node *root,int itemd);
struct node* inordersuc(struct node* root);
void inorder(struct node *root);
void postorder(struct node *root);
void preorder(struct node *root);
struct node* searchnode(struct node *root,int items);
void main()
{
struct node *root=NULL;
int choice,ch,item,itemd,items;
do
{
printf("\nMENU\n");
printf("1.Insertion\t2.Deletion\t3.Display\t4.Search a specified node\t5.Exit\n");
printf("Enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
printf("Enter the data to be inserted\n");
scanf("%d",&item);
root=insertnode(root,item);
break;
}
case 2:
{
printf("Enter the data to be deleted\n");
scanf("%d",&itemd);
root=deletenode(root,itemd);
break;
}
case 3:
{
printf("Choose type of traversal for display\n");
printf("1.InOrder Traversal\t2.PostOrder Traversal\t3.PreOrder Traversal\n");
printf("Enter choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
printf("Displaying InOrder traversal\n");
inorder(root);
break;
}
case 2:
{
printf("Displaying PostOrder traversal\n");
postorder(root);
break;
}
case 3:
{
printf("Displaying PreOrder traversal\n");
preorder(root);
break;
}
default:
{
printf("INVALID CHOICE\n");
break;
}
}
break;
}
case 4:
{                      
printf("Enter data to be searched\n");
scanf("%d",&items);
if ((root=searchnode(root,items))!=NULL)
printf("Node with data %d is found in the Binary Search Tree\n",items);
else
printf("Node with data %d is not found in the Binary Search Tree\n",items);
break;
}
case 5:
{
printf("Exiting Binary Search Tree program\n");
break;
}
default:
{
printf("INVALID CHOICE\n");
break;
}
}
}
while(choice!=5);
}
struct node* insertnode(struct node *root,int item)
{
if(root==NULL)
{
struct node *p;
p=(struct node*)malloc(sizeof(struct node));
p->data=item;
p->left=NULL;
p->right=NULL;
return p;
}
else if (item < root->data)
root->left=insertnode(root->left,item);
else
root->right=insertnode(root->right,item);
return root;
}
struct node* deletenode(struct node *root,int itemd)
{
if(root==NULL)
return root;
if(itemd < root->data)
root->left=deletenode(root->left,itemd);
else if (itemd > root->data)
root->right=deletenode(root->right,itemd);
else
{
if (root->left==NULL)
{
struct node *temp = root->right;
free(root);
return temp;
}
else if(root->right==NULL)
{
struct node *temp=root->left;
free(root);
return temp;
}
struct node *temp=inordersuc(root->right);
root->data=temp->data;
root->right = deletenode(root->right,temp->data);
root->left=deletenode(root->left,temp->data);
}
return root;
}
struct node* inordersuc(struct node *root)
{
while (root->left!=NULL)
root = root->left;
return root;
}
void inorder(struct node *root)
{
if(root==NULL)
return;
inorder(root->left);
printf("%d\t",root->data);
inorder(root->right);
}
void preorder(struct node *root)
{
if(root==NULL)
return;
printf("%d\t",root->data);
preorder(root->left);
preorder(root->right);
}
void postorder(struct node *root)
{
if(root==NULL)
return;
postorder(root->left);
postorder(root->right);
printf("%d\t",root->data);
}
struct node* searchnode(struct node *root,int items)
{
if (root==NULL||root->data==items)
return root;
if (items < root->data)
return searchnode(root->left,items);
return searchnode(root->right,items);
}






