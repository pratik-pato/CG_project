//14135

#include<stdio.h>
#include<math.h>
int main()
{
  float y,x,e,c;
  scanf("%f",&x);
  e=(float)exp(x);
  c=cos(2*3.142*x);
  printf("\n%f\t%f",e,(e*c));
  return 0;
}
