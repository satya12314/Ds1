// Lowest common Ancestor of given 2 nodes
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
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

node* LCA(struct node*root,int n1,int n2 ){
    if(root==NULL) return NULL;
    if(root->data>n1 && root->data>n2)
    {
        return LCA(root->left,n1,n2);
    }
    if(root->data<n1 && root->data<n2)
    {
        return LCA(root->right,n1,n2);
    }
    return root;
}

int main()
{
    struct node* root=NULL;
    root=insert(root,20);
    root=insert(root,8);
    root=insert(root,4);
    root=insert(root,12);
    root=insert(root,10);
    root=insert(root,14);
    root=insert(root,22);

    // LCA(root,17,14);
    cout<<" LCA is "<<LCA(root,14,10)->data;   // LCA is 12
    cout<<" LCA is "<<LCA(root,14,8)->data;   // LCA is 8
    cout<<" LCA is "<<LCA(root,22,4)->data;   // LCA is 20
}