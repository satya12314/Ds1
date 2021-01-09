#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
node* NewNode(int item)
{
    struct node* root;
    root=new node();
    root->data=item;
    root->left=root->right=NULL;
    return root;
}
void inorder(struct node* root)
{
    if(root!=NULL){
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    }
}
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return NewNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
   
    return current;
}


node* deletion(struct node* root,int data)
{
if(root==NULL)return root;
else if(data<root->data){root->left=deletion(root->left,data); }
else if(data>root->data){root->right=deletion(root->right,data);}
else{
    //1.> case 1: No child
    if(root->left==NULL && root->right==NULL){
        delete root;
        root=NULL;
        return root;
    }
    // 2.>case2 :only 1 child
    else if(root->right==NULL){
        struct node* temp=root;
        root=root->right;
        delete temp;
        return root;
    }
    else if(root->right==NULL){
        struct node* temp;
        root=root->left;
        delete temp;
        return root;
    }
// Case3:2 children

    else{
struct node* temp=minValueNode(root->right) ;  //minimum value in right subtree and maximum value in left subtree
root->data=temp->data;
root->right=deletion(root->right,temp->data);
    }

}
return root;
}
int main()
{
struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    cout << "Inorder traversal of the given tree \n";
    inorder(root);
    
//    minValueNode(root);
deletion(root,60);
   cout << "\nInorder traversal of the given tree \n";
    inorder(root);
}