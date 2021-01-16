
//Fix a binary tree that is only one swap away from becoming a BST

#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
stack<int>st1;
node* Newnode(int item){
    struct node* root=new node();
    root->data=item;
    root->left=root->right=NULL;
    return root;
}
node* insert(struct node* root,int item)
{
    if(root==NULL){
        return Newnode(item);
    }
    else if(item<root->data){
        root->left=insert(root->left,item);
    }
    else{
        root->right=insert(root->right,item);
    }
    return root;
}

void NodChecker(struct node* root,node* &x,node* &y,node* &prev){
    if(root==NULL)
    {
        return;
    }
    NodChecker(root->left,x,y,prev);
    if(root->data<prev->data){
        if(x==NULL)
         x=prev;

    y=root;
    }
    prev=root;
    NodChecker(root->right,x,y,prev);
}
void swapNode(node* root){
    node* x=NULL;
    node* y=NULL;
    node* prev=Newnode(INT_MIN);
   NodChecker(root,x,y,prev);
     // swap the nodes
    if (x && y)
        swap(x->data, y->data);
}
void inorder(node* root){
    if(root!=NULL){
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);}
}
int main()
{
   struct node *root = Newnode(6); 
    root->left        = Newnode(10); 
    root->right       = Newnode(2); 
    root->left->left  = Newnode(1); 
    root->left->right = Newnode(3); 
    root->right->right = Newnode(12); 
    root->right->left = Newnode(7); 
 inorder(root);   //2 and 10 need to be swaped.
 swapNode(root);
 cout<<"\n";
 inorder(root);
  
   
}
