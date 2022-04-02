#include<iostream>
#include<graphics.h>
#include <math.h>
#include <dos.h>
using namespace std;

void dline(int x1, int y1, int x2, int y2, int color=7){
	float dx, dy, slope, length, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	slope = dy/dx;
	
	if (abs(dx)>abs(dy))
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
		putpixel(x,y,color);
	}
	
	cout<<"Slope : "<<slope<<endl;
}

void drawcircle(int a, int b, int r, int color=7){
	int x,y,p;
	p = 1-r;
	x = 0;
	y = r;
	while(x<y){
		
		putpixel(a+x,b+y,color);	//1
		putpixel(a+y,b+x,color);	//2
		putpixel(a+y,b-x,color);	//3
		putpixel(a+x,b-y,color);	//4
		putpixel(a-x,b-y,color);	//5
		putpixel(a-y,b-x,color);	//6
		putpixel(a-y,b+x,color);	//7
		putpixel(a-x,b+y,color);	//8
		
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
		
		

	}
}

void poly(){
	int x,y,n;
	
	cout<<"no. of vertices in polygon : ";
	cin >> n;
	
	int xi[n], yi[n];

	for(int i=0; i<n; i++){
		cout<<"enter Co-ordinates(x"<<(i+1)<<",y"<<(i+1)<<"): ";
		cin >> x>>y;
		xi[i]=x;
		yi[i]=y;
		
		if(i>0){
			line(xi[i-1],yi[i-1], xi[i],yi[i]);
//			dline(xi[i-1],yi[i-1], xi[i],yi[i]);
		}
	}
	line(xi[n-1],yi[n-1], xi[0],yi[0]);
//	dline(xi[n-1],yi[n-1], xi[0],yi[0]);
	
}

int main(){
	int gd=DETECT, gm, error, x1,y1, x2,y2, x,y,r;
	initgraph(&gd, &gm,(char*)"");
	
//	dline(10,10,630,10);	//	x -> 640, y->480, xy->800
//	dline(10,10,10,470);
//	dline(10,10,630,470);
//	dline(10,470,630,470);
//	dline(630,10,630,470);
//	dline(630,10,10,470);
//	dline(630,10,10,470);
	
	drawcircle(320,240,230);
//	circle(320,240,250);
	
	
	int ch ;
	do{
		
		cout<<"Select one of the following :-"<<endl<<endl;
		cout<<" 1. Draw Line.\n 2. Draw Circle.\n 3. Draw Polygon.\n 0. Exit.\n\n";
		cout<<"Your Choice :- ";
		cin >> ch;
		switch(ch){
			case 0:{
				break;
			}
			case 1:{
				cout<<"\nEnter first point (x1,y1): ";
				cin >> x1>>y1;
				cout<<"\nEnter second point (x2,y2): ";
				cin >> x2>>y2;
				line(x1, y1, x2 ,y2);
	    		dline(x1, y1, x2 ,y2);
	    		break;
			}
			case 2:{
				cout<<"\nEnter Center Co-ordinates(x,y): ";
				cin >> x>>y;
				cout<<"\nEnter Radius : ";
				cin >> r;
				drawcircle(x,y,r);
				break;
			}
			case 3:{
				poly();
				break;
			}
			default:{
				cout<<"invalid choice...!___Try again...\n\n"<<endl;
			}
		}
	}while(ch!=0);
	getch();
	closegraph();
	return 0;
}
