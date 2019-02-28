#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int getRightpostion(int A[],int l,int r,int key)
{
  int m;
  while(r-l>1)
  {
    m=(l+r)/2;
    if(A[m]<=key)
    l=m;
    else
    r=m;
  }
  return l;
}
int getLeftpostion(int A[],int l,int r,int key)
{
  int m;
  while(r-l>1)
  {
    m=(l+r)/2;
    if(A[m]>=key)
    r=m;
    else
    l=m;
  }
  return r;
}
int main()
{
int A[]={1,1,2,2,2,2,2,4,4};
int size=sizeof(A)/sizeof(A[0]);
int right=getRightpostion(A,0,size,4);
int left=getLeftpostion(A,-1,size-1,4);
cout<<right<<"\t"<<left<<endl;
if((A[left]==4) && (A[right]==4))
cout<<(right-left+1)<<endl;
else
cout<<-1;
return 1;
}
