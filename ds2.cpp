#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
node* Newnode(int item)
{
    struct node* root=new node();
    
        root->data=item;
        root->left=NULL;
        root->right=NULL;
        return root;
}
node* insert(struct node* root,int item)
{
    if (root==NULL){
        return Newnode(item);
    }
    if(item<root->data){
        root->left=insert(root->left,item);
    }
    else{
        root->right=insert(root->right,item);
    }
    return root;
}
// Function for minimum value in BST
int minvalue(struct node* root)
{
    while(root->left!=NULL){
        root=root->left;
    }
    
    return root->data;
}
//inorder predecessor and successor for a given key in BST
void findpre_succ(node* root,node*& pre,node*& suc,int key)
{if(root==NULL)return;
    if(root->data==key)
    {
        if(root->left!=NULL)
        {
            node* temp=root->left;
            while(temp->right!=NULL)
                temp=temp->right;
            pre=temp;
            
            
        }
        if(root->right!=NULL)
        {
            node* temp=root->right;
            while(temp->left!=NULL)
                temp=temp->left;
            suc=temp;
        }
        return;
    }
    if(root->data>key)
    {
        suc=root;  //important in end case i.e. if ther is no successor or predecessor then it is important
        findpre_succ(root->left,pre,suc,key);   
    }
    else{
        pre=root;     //important in end case i.e. if ther is no successor or predecessor then it is important
        findpre_succ(root->right,pre,suc,key);
    }

}
int main()
{
struct node* root=NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 12);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

minvalue(root);
cout<<"Minimum Value in the given BST is "<<minvalue(root);
node* pre=NULL;
node* suc=NULL;
int key=12;
findpre_succ(root,pre,suc,key);
if(pre!=NULL)
{
    cout<<"Predecessor is "<<pre->data<<"\n";
}
else{
    cout<<"Predecessor = None"<<"\n";
}
if(suc!=NULL){
    cout<<"Successor is "<<suc->data<<"\n";
}
else{
    cout<<"Successor = None"<<"\n";
}
}