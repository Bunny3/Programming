#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
  int date[]={1,2,3,4,7,8,9,10,11,14,15,16,17,18,21,22,23,24,25,28,29,30,31};
  double openVal[]={11130.55,11110.15,11035.70,10940.90,11044.05,11018.90,11089.45,11083.65,11067.15,11033.65,11005.05,11120.65,11141.45,11135.25,11122.10,11142.75,11133.25,11047.85,11062.55,10978.90,10826.40,10879.45,10869.25,};
  //Using equation h=theta0+theta1*x
  double  alpha=0.0001;
  int i,j,k;
  double res=0,dif0,dif1;
  double theta0=0.3;
  double theta1=0.5;
  double temp0,temp1;
  double costo,costn;
  //cost(theta0,therta1)=sum(y^-yi)/(2*m)
  int len=sizeof(date)/sizeof(int);
  do
  {
  for(i=0;i<len;i++)
  {
    res=theta1*date[i]+theta0;
    costo=costo+pow((res-openVal[i]),2);
  }
  costo/=2*len;
  dif0=0;
  dif1=0;
  for(k=0;k<len;k++)
  {
    dif0+=theta1*date[k]+theta0-openVal[k];
    dif1+=(theta1*date[k]+theta0-openVal[k])*date[k];
  }
  dif0/=len;
  dif1/=len;
  temp0=theta0-alpha*dif0;
  temp1=temp1-alpha*dif1;
  theta0=temp0;
  theta1=temp1;
  //CAlCULATE cost function
  for(i=0;i<len;i++)
  {
    res=theta1*date[i]+theta0;
    costn=costn+pow((res-openVal[i]),2);
  }
  costn/=2*len;
}while(costo>costn);
float pvalue=theta1*32+theta0;
printf("%f\n",pvalue);
printf("%f\n%f",theta0,theta1);
double accuracy=(abs(pvalue-11130.55))/(11130.55);
printf("\n%f\n",1-accuracy);
return 1;
}
