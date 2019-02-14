#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
  int val;
  node *left,*right;
};
struct node * newNode(int key)
{
  struct node *temp=new node();
  temp->val=key;
  temp->right=temp->left=NULL;
  return temp;
}
/*struct node *convert(const vector<int> A)
{
  int len=sizeof(A)/sizeof(A[0]);
    int l=0,h=len-1,mid=0,i;
    mid=(l+h)/2;
    if(l==h)
    {
        node *temp=newNode(A[l]);
        //temp->val=A[0];
        //temp->left=temp->right=NULL;
        return temp;
    }
    else{
    node *root=newNode(A[mid]);
    //root->val=A[mid];
    vector<int> larray;
    for(i=l;i<mid;i++)
        larray.push_back(A[i]);
    if(larray.empty())
    root->left=NULL;
    else
    root->left=convert(larray);
    vector<int> rarray;
    for(i=mid+1;i<h;i++)
        rarray.push_back(A[i]);
    if(rarray.empty())
    root->right=NULL;
    else
    root->right=convert(rarray);
    return root;
    }
}*/
struct node* convert(std::vector<int> arr, int start, int end)
{
    /* Base Case */
    if (start > end)
      return NULL;
    int mid = (start + end)/2;
    struct node *root = newNode(arr[mid]);
    root->left =  convert(arr, start, mid-1);
    root->right = convert(arr, mid+1, end);
    return root;
}
void inorder(struct node *root)
{
  if(root!=NULL)
  {

    inorder(root->left);

    inorder(root->right);
    cout<<root->val;
  }
}
int main()
{
    vector<int> arr={1};
    int len=sizeof(arr)/sizeof(arr[0]);
    struct node* root=convert(arr,0,len-1);
    inorder(root);
    return 0;

}
