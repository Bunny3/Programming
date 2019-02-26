#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<map>

#define openfun(ptr,file) ptr.open(file,ios::in)
using namespace std;
vector<string> tokens;
struct node{
  int data;
  int docount;
  struct node *next;
};
struct node * newnode(int data)
{
  struct node *temp=new node();
  temp->docount=1;
  temp->data=data;
  temp->next=NULL;
};
map<string,int> mp;
map<string,struct node *> nmp;
void insertNode(struct node *head,struct node *target)
{
  struct node *temp=head;
  if(head==NULL)
  head=target;

  else
  {
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=target;
  }
}
//function to tokenize
void tokenize(string str,int docID)
{
  stringstream s1(str);
  string intermediate;
  while(getline(s1,intermediate,' '))
    tokens.push_back(intermediate);
}
//function to operate on files
void fun(fstream& fio,int docID)
{
  string line,str="";
  while(fio)
  {
    getline(fio,line);
    str=str+line;
  }
  //To remove punctuations
  string temp="";
  for(int i=0;i<str.length();i++)
  {
    char ch=str[i];
    //if(ch=='.')||(ch=='?')||(ch=='!')||(ch==',')||(ch=='/')//
    if((ch>='0')&&(ch<='9'))
    temp+=ch;
    else if((((ch>='A')&&(ch<='Z'))||(ch>='a')&&(ch<='z'))||(ch==' '))
    temp+=ch;
  }
  //to tokenize the formated string
  tokenize(temp,docID);
  //Counting the frequency of each word
  for(vector<string>::const_iterator itr=tokens.begin();itr!=tokens.end();itr++)
  {
    if(mp.count(*itr)==0)
      mp[*itr]=1;
    else
    mp[*itr]++;
  }
  for(map<string,int>::iterator ftr=mp.begin();ftr!=mp.end();ftr++)
  {
    struct node *temp=newnode(docID);
    if(nmp.count(ftr->first)==0)
    {
      //temp->docount+=ftr->second;
      nmp[ftr->first]=temp;
    }
    else
    {
      insertNode(nmp[ftr->first]);

    }
  }
}
int main()
{
  fstream fio1;
  fstream fio2;
  fstream fio3;
  fstream fio4;
  fstream fio5;
  string line1,line2,line3,line4,line5;
  openfun(fio1,"a1.txt");
  openfun(fio2,"a2.txt");
  openfun(fio3,"a3.txt");
  openfun(fio4,"a4.txt");
  openfun(fio5,"a5.txt");
  fun(fio1,1);
  // fun(fio2,2);
  // fun(fio3,3);
  // fun(fio4,4);
  // fun(fio5,5);
  vector<string>::iterator itr;
  for(map<string,int>::iterator ftr=mp.begin();ftr!=mp.end();ftr++)
  cout<<ftr->first<<"\t"<<ftr->second<<endl;
  fio1.close();
  fio2.close();
  fio3.close();
  fio4.close();
  fio5.close();
  return 1;
}
