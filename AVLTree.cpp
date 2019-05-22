// Brief implementation of AVL Trees aka Self Balancing Trees
#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int id,height;
    Node *left,*right;
    //Height of leaf is 0
    Node(int i):id(i),height(0),left(NULL),right(NULL){} 
}Node;

int height(Node *n)
{
  //Just to make sure calculations are right NULL node is at -1 level
  if(n==NULL)
     return -1;
  return n->height;
}

int balance(Node *root)
{
  //If node is empty we assert that its balanced
  if(root==NULL)
    return 0;
    
  //Note: Here we return the subtraction not the modulas!
  //This helps us do decide weather its left heavy or right heavy
  return height(root->left)-height(root->right);
}

//      root
//       /
//      y
//     /  \
//    z    T2
Node* leftrotate(Node *root)
{
    Node *y=root->right;
    Node *T2=y->left;
    y->left=root;
    root->right=T2;
    root->height= max(height(root->left),height(root->right))+1;
    y->height= max(height(y->left),height(y->right))+1;
    return y;
}

Node* rightrotate(Node *root)
{
    Node *y=root->left;
    Node *T2=y->right;
    y->right=root;
    root->left=T2;
    root->height= max(height(root->left),height(root->right))+1;
    y->height= max(height(y->left),height(y->right))+1;
    return y;
}

Node* insert( Node *root, int id )
{
    if(root==NULL)
        return new Node(id);
    
    if(id<root->id)
        root->left = insert(root->left, id);
    else if(id>root->id)
        root->right = insert(root->right, id);
    else
        return root;
    
    root->height=max(height(root->left),height(root->right))+1;  
    int b = balance(root);
    
    if(b>1 && id<root->left->id)
    {   return rightrotate(root);  }
    
    if(b<-1 && id>root->right->id)
    {   return leftrotate(root);   }
    
    if(b>1 && id>root->left->id)
    {
       root->left=leftrotate(root->left);
       return rightrotate(root);
    }
    
    if(b<-1 && id<root->right->id)
    {
       root->right=rightrotate(root->right);
       return leftrotate(root);
    }
    return root;
}

void preorder(Node *root)
{
  if(root!=NULL)
  {
    preorder(root->left);
    cout<<root->id<<" ";
    preorder(root->right);
  }
}

int main()
{
  int arr[]={1,5,7,13,22,0};
  Node *root=NULL;
  for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));++i)
    root=insert(root,arr[i]);
  preorder(root);
  return 0;    
}
