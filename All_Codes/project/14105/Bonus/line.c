#include<stdio.h>
#include<graphics.h>

int main(void){
		int gd=DETECT,gm;
		int x1 = 15,y1 = 10, x2 = 100, y2 = 200,dx,dy,E,NE,M;
		initgraph(&gd, &gm, NULL);
		dx = x2-x1;
		dy = y2-y1;
		E = 2*dy;
		NE = 2*(dy-dx);
		M = 2*(dy)-dx;
		putpixel(x1,y1, WHITE);
		while(x1<=x2){
				if(M <= 0)
				{
						M+=E;
						x1++;
				}
				else
				{
						M+=NE;
						x1++;
						y1++;
				}
				putpixel(x1,y1, WHITE);
		}
		
		getch();
		closegraph();
		return 0;
}
