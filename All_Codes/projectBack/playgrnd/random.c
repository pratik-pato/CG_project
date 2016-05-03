#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int lengthInt(int num)
{
return floor(log10(abs(-435671)))+1;
}

float random_0_1()
{
  int r1 = rand();
  int ln = floor(log10(abs(r1)))+1;
  
  double ans = r1/(pow(10,ln));
  return (float)ans;
}

float getSum(float *arr,int sz)
{
  int i;
  float ans=0;
  for(i=0;i<sz;i++)
    ans=ans+arr[i];
  return ans;
}


float* randArr(int sz)
{
  float *arr;
  int i;
  arr=(float*)malloc(sizeof(float)*sz);
  for(i=0;i<sz;i++)
    {
      arr[i]=random_0_1();
    }
  return arr;
}

float* getProbRange(int sz)
{
  int i;
  float *tmp,*ans,sum;
  ans=(float*)malloc(sizeof(float)*sz);
  tmp=randArr(sz);
  sum=getSum(tmp,sz);
  for(i=0;i<sz;i++)
    ans[i]=tmp[i]/sum;
  return ans;
}



int main()
{
  int i,n;
  float *ans;
  float *ans2;
  scanf("%d",&n);
    ans=getProbRange(n);
  for(i=0;i<n;i++)
    printf("%f\n",ans[i]);
  printf("SUM\t\t%f\n",getSum(ans,n));
  //printf("%d",nDigits);
  return 0;
}
