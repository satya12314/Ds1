#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
// Function for  
//Determine if given Binary Tree is a BST or not


bool isBst(node* root,int min,int max){
    if(root==NULL)return true;
    
    if(root->data<min || root->data>max)return false;

    return isBst(root->left,min,root->data) && isBst(root->right,root->data,max);
}
void isBST(node* root)
{
    if(isBst(root,INT_MIN,INT_MAX)){
        cout<<"BST ";
    }
    else{
        cout<<"BST ";
    }
}
