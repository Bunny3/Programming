#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int power(int x,int n)
{
  if(x==0)
  return 0;
  if(n==0)
  return 1;
  long long int rem=1;
  long long temp=x;
  while(n>0)
  {
    if(n%2!=0)
    rem=(rem*temp);
    else
    temp=temp*temp;
    n=n/2;
  }
  return rem;
}
int main()
{
  int x,n;
  cout<<"enter the x and n"<<endl;
  cin>>x>>n;
  long long int val=power(x,n);
  cout<<val<<endl;
  return 0;
}
