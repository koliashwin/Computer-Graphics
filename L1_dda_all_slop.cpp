#include<iostream>
#include<graphics.h>
#include <math.h>
#include <dos.h>
using namespace std;
void drawline(int x1, int y1, int x2, int y2){
	float dx, dy, slope, length, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
//	slope = dy/dx;
	
	if (abs(dx) > abs(dy))
		length = abs(dx);
	else
		length = abs(dy);
		
	dx = dx/length;
	dy = dy/length;
	
	x = x1 + 0.5;
	y = y1 + 0.5;
	
	for(int i =0; i<length; i++){
		x += dx;
		y += dy;
		putpixel(x,y,10);
	}
}

void flag(int x, int y, int h)  
{  
      drawline(x-1,y,x-1,y+h*2);
      drawline(x+1,y,x+1,y+h*2);
      drawline(x,y,x+h,y+h);
      drawline(x,y+h,x+h,y+h);
      delay(500);
}

void stairs(int x, int y, int h, int w=60, int step_dist=20){
	
	for(int i = w; i<h; i += 5){
		drawline(x-i,y,x+i,y);
		drawline(x-i,y,x-i,y+step_dist);
		drawline(x+i,y,x+i,y+step_dist);
		y += step_dist;
	}
	delay(500);
}

void building(int x, int y, int h){
	drawline(x-h*0.9,y,x+h*0.9,y);
	drawline(x-h*0.9,y,x-h*0.9,y+h*2);
	drawline(x+h*0.9,y,x+h*0.9,y+h*2);
	drawline(x-h*0.9,y+h*2,x+h*0.9,y+h*2);
	drawline(x-h*0.4,y+h*0.9,x-h*0.4,y+h*2);
	drawline(x+h*0.4,y+h*0.9,x+h*0.4,y+h*2);
	drawline(x-h*0.4,y+h*0.9,x+h*0.4,y+h*0.9);
	delay(500);
}

void roof2(int x, int y, int h, int spread=3){
	
	for (int i=0; i<2*h; i+=spread){

		drawline(x,y,x-h+i,y+h);
	}
	drawline(x,y,x+h,y+h);
	delay(500);
}



int main(){
	int gd=DETECT, gm, error, x1,y1, x2,y2;
	initgraph(&gd, &gm,(char*)"");
	
	
//	drawline(10,10,630,10);	//	x -> 640, y->480, xy->800
//	drawline(10,10,10,470);
//	drawline(10,10,630,470);
//	drawline(10,470,630,470);
//	drawline(630,10,630,470);
//	line(630,10,10,470);
//	drawline(630,10,10,470);

//// temple
	flag(320, 4, 30);
	stairs(320,60,90,20,10);
	cout<<getpixel(320,61);
	building(320,200,100);
	stairs(320,400,150,60);

//  house
//	roof2(320, 60, 115,1);
//	building(320,170,120);
	
	int ch =1;
	while(ch!=0){
	 
	    printf("Enter first point (x1,y1): ");  
	    scanf("%d%d", &x1, &y1);  
	    printf("Enter second point(x2,y2): ");  
	    scanf("%d%d", &x2, &y2);  
	    drawline(x1, y1, x2 ,y2);
	    line(x1+10, y1+20, x2+10 ,y2+20);
	    
	    printf("Draw another line(press 0 to exit loop):");
	    scanf("%d", &ch);
	}
	getch();
	closegraph();
	return 0;
}
