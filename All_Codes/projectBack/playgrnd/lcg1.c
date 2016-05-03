#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
  int i,sz,*op;
  scanf("%d",&sz);
  double *u,*z,m,a=630360016,c=1,temp;
  op=(int*)malloc(sizeof(int)*sz);
  u=(double*)malloc(sizeof(double)*100);
  z=(double*)malloc(sizeof(double)*100);
  m=pow(2,31);
  z[0]=22091993;
  printf("%lf\n",(z[0]*a));
  u[0]=z[0]/m;
  for(i=1;i<sz;i++)
    {
      temp=(a*z[i-1])+c;
      z[i]=fmod(temp,m);
      u[i]=z[i]/m;
      if(u[i]>=0.0 && u[i]<=0.19)
	op[i]=1;
      else if(u[i]>=0.2 && u[i]<=0.39)
	op[i]=2;
      else if(u[i]>=0.4 && u[i]<=0.59)
	op[i]=3;
      else if(u[i]>=0.6 && u[i]<=0.79)
	op[i]=4;
      else 
	op[i]=5;
      printf("%d\n",op[i]);
    }

  
  return 0;
}
