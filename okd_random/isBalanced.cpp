#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};

int height(struct node* node){
    if(node == NULL)
        return 0;
    
    return 1 + max(height(node->left), height(node->right));
}
bool isBalanced(struct node *root){
    int lh;
    int rh;

    if(root == NULL)
        return 1;
    
    lh = height(root->left);
    rh = height(root->right);

    if(abs(lh-rh) <=1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    
    return 0;
}

//================O(n^2)================

bool isBalanced(struct node * root, int *height){
    int lh=0, rh=0;
    int l = 0, r=0;
    if(root==NULL){
        *height=0;
        return 1;
    }
    l=isBalanced(root->left, &lh);
    r=isBalanced(root->right, &rh);

    *height=(lh>rh?lh:rh)+1;
    if(abs(lh-rh)>=2) 
        return 0;

    else return l&&r;
}