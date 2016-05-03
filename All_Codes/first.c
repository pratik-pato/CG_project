#include<stdio.h>
#include<graphics.h>

int main()

{
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
int i,x=10;
//char str[3]=”0″;
setbkcolor(BLUE);

setcolor(12); //outline heart
circle(50,50,40);
//circle(110,50,40);
//line(22,80,80,140);
//line(80,140,138,80);

floodfill(50,50,12); //fill heart
//floodfill(110,50,12);
//floodfill(80,50,12);
//floodfill(80,100,12);

getch();
closegraph();
return 0;
}
