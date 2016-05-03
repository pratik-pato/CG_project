#include<stdio.h>
#include<graphics.h>
void main()
{
 float d;
 int gd=DETECT,gm,x,y;
 int r;
 initgraph(&gd,&gm,"");
 {
  printf("Enter The Radious Of Circle");
  scanf("%d",&r);

  x=0;
  y=r;
  d=3-2*r;
  do
  {
  	putpixel(200+y,200+x,15);
  	putpixel(200+y,200-x,15);
  	putpixel(200+x,200-y,15);
  	putpixel(200-x,200-y,15);
   	putpixel(200-y,200+x,15);
   	putpixel(200-y,200-x,15);
   	putpixel(200-x,200+y,15);
  	putpixel(200+x,200+y,15);
   if(d<=0)
   {
    d=d+4*x+6;
   }
   else
   {
    d=d+4*(x-y)+10;
    y=y-1;
   }
   x=x+1;
   delay(200);
   }
   while(x<y);
   closegraph();
   }
 }
