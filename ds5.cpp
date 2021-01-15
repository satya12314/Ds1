// Print kth smallest element in the bst
//2 different methods are listed here

#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
   
};
 stack<int>st1;
node* NewNode(int item){
    struct node* root=new node();
    root->data=item;
    root->left=root->right=NULL;
    return root;
}
node* insert(struct node* root,int item)
{
    if(root==NULL){
        return NewNode(item);
    }
    else if(item<root->data){
        root->left=insert(root->left,item);
    }
    else{
        root->right=insert(root->right,item);
    }
    return root;
}

// Most efficient way of  finding kth smallest element
node* kthsmallest(node* root,int &k)
{
    if(root==NULL)
    {return NULL;}
    node* left = kthsmallest(root->left,k);
    if(left!=NULL)
    {
        return left;
    }
    k--;
    if(k==0)
    {
        return root;
    }
    return kthsmallest(root->right,k);
}
void printkthsmallest(node* root,int k)
{
    
    node* res=kthsmallest(root,k);
    if(res==NULL)
    {
        cout<<"less than k nodes";
    }
    else{
        cout<<"kth smallest element is "<<res->data;
    }
}

// kth smallest element using stack
void inorder(struct node* root)
{
    
    if(root!=NULL)
    {
        inorder(root->left);
        // cout<<root->data<<" ";
        st1.push(root->data);
        inorder(root->right);
    }
    
}
int main(){
struct node* root=NULL;
    root=insert(root,20);
    root=insert(root,8);
    root=insert(root,4);
    root=insert(root,12);
    root=insert(root,10);
    root=insert(root,14);
    root=insert(root,22);
printkthsmallest(root,3);


cout<<"Using stack Method ";
inorder(root);
  int k=2;
  int p=st1.size()-k+1;    //for kth smallest element
   while(p--)
   {
      if(p==0){
          cout<<"\n"<<st1.top();
      }
    //    cout<<st1.top()<<" ";
       st1.pop();
       

   }
}