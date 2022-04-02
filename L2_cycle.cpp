#include<iostream>
#include<graphics.h>
#include <math.h>
#include <dos.h>

void drawcircle(int a, int b, int r, int arc1=7, int arc2=7, int arc3=7, int arc4=7, int arc5=7, int arc6=7, int arc7=7, int arc8=7){
	int x,y,p;
	p = 1-r;
	x = 0;
	y = r;
	while(x<=y){
		if(p<0){
			p += 2*(x) +2;
//			putpixel(a+x+1,b+y,15);	
		}
		else{
//			putpixel(a+x+1, b+y-1, 15);
			p += 2*(x) +2 -2*(y)-2;
			y--;
			
		}
		x++;
		
		putpixel(a+x,b+y,arc1);	//1
		putpixel(a+y,b+x,arc2);	//2
		putpixel(a+y,b-x,arc3);	//3
		putpixel(a+x,b-y,arc4);	//4
		putpixel(a-x,b-y,arc5);	//5
		putpixel(a-y,b-x,arc6);	//6
		putpixel(a-y,b+x,arc7);	//7
		putpixel(a-x,b+y,arc8);	//8

	}
}

void front_tire(int x, int y, int r, int clr1=0, int clr2=7){
	int thick = r*0.15;
	circle(x,y,5);
	circle(x,y,r);
	circle(x,y,r-thick);
//	for(int i = 0; i<thick; i++){
//		drawcircle(x,y,r+1.8*thick+i, clr1,clr1,clr2,clr2,clr2,clr1,clr1,clr1);
//	}
}

void rear_tire(int x, int y, int r, int clr1=0, int clr2=7){
	int thick = r*0.15;
	circle(x,y,5);
	circle(x,y,r);
	circle(x,y,r-thick);
//	for(int i = 0; i<thick; i++){
//		drawcircle(x,y,r+1.8*thick+i, clr1,clr1,clr2,clr2,clr2,clr1,clr1,clr1);
//	}
}

void middle_part(int x, int y, int h, int w){
	line(x-w,y,x+w,y);
	line(x-w,y,x-w-0.45*h,y+h);
	line(x+w,y,x+w+0.55*h,y+h);
}

void cycle(int x, int y, int h){
	int w = h*0.75;
	middle_part(x,y,h,w);
	front_tire(x-w-0.45*h,y+h, h/2);
	front_tire(x+w+0.55*h,y+h, h/2);
	circle(x+0.15*h,y+h, (w+h)/9);	//paddle
	line(x+w+0.55*h,y+h+5, x+0.15*h,y+h+(w+h)/9);
	line(x+w+0.55*h,y+h-5, x+0.15*h,y+h-(w+h)/9);
	line(x+0.15*h,y+h, x-w,y);
	line(x+0.15*h,y+h, x+w,y);
	line(x-w,y,x-w-h*0.1,y-h*0.3);
	line(x-w-h*0.1,y-h*0.3, x-w+h*0.4,y-h*0.3);
}

void animation(int x,int y, int h, int dist, int speed = 5){
	int i = 0;
	while(i != dist){
		setcolor(0);
		cycle(x,y,h);
		if(i<dist){
			x+=speed;
			i+=speed;
		}
		else{
			x-=speed;
			i-=speed;
		}
		setcolor(7);
		cycle(x,y,h);
		delay(20);
	}
}

int main(){
	int gd=DETECT, gm, error, x1,y1, x2,y2;
	initgraph(&gd, &gm,(char*)"");
	
	
//	drawcircle(320,240,200,1,2,3,4,5,6,7,8);
//	cycle(320, 240,90);
//	
//	cycle(320, 20,10);
//	cycle(400, 100,100);

	animation(400, 400, 50 ,-200);
	animation(100, 40, 20 ,300);
	
	int ch =1;
	while(ch!=0){
	 
	    printf("Enter first point (x1,y1): ");  
	    scanf("%d%d", &x1, &y1);  
	    printf("Enter second point(x2,y2): ");  
	    scanf("%d%d", &x2, &y2);  
	    line(x1, y1, x2 ,y2);
//	    dline(x1, y1, x2 ,y2);
	    
	    printf("Draw another line(press 0 to exit loop):");
	    scanf("%d", &ch);
	}
	getch();
	closegraph();
	return 0;
}
