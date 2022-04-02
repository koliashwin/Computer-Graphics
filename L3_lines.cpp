#include<iostream>
#include<graphics.h>
#include <math.h>
#include <dos.h>
using namespace std;

void dline(int x1, int y1, int x2, int y2, int type, int bold=1, int color=15){
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
		
		if(type == 1 and i%5 == 0){
			putpixel(x,y,color);
		}
		else if(type ==2 and i%10 < 5){
			putpixel(x,y,color);
		}
		else if(type==3 and (i%20==5 or i%20 > 10)){
			putpixel(x,y,color);
		}
		else if(type==4){
			int thick = bold;
			
			
			for(int j=0; j<=thick; j++){
				if(slope>=1 or slope<=-1){
					putpixel(x+j,y,color);
				}
				else {
					putpixel(x,y+j,color);
				}
			}
			
			
			
		}
	}
	
	if(type==4){
		setcolor(color);
		setfillstyle(1,color);
		if(slope<=1 or slope>=-1){
			
			circle(x1, y1+(bold+1)/2, bold/2);
			circle(x2, y2+(bold+1)/2, bold/2);
			
			floodfill(x1, y1+(bold+1)/2, color);
			floodfill(x2+1, y2+(bold+1)/2, color);
		}
		else{
			circle(x1+(bold+1)/2, y1, bold/2);
			circle(x2+(bold+1)/2, y2, bold/2);
			
			
		}
		
	}
//	cout<<"Slope : "<<slope<<endl;
}

int main(){
	int gd=DETECT, gm, error, x1,y1, x2,y2, x,y,r, thick;
	initgraph(&gd, &gm,(char*)"");
	
//	dline(10,10,630,10);	//	x -> 640, y->480, xy->800
//	dline(10,10,10,470);
//	dline(10,10,630,470);
//	dline(10,470,630,470);
//	dline(630,10,630,470);
//	dline(630,10,10,470);
//	dline(630,10,10,470);
	
//	drawcircle(320,240,230);
//	circle(320,240,250);
	
	
	int ch ;
	do{
		
		cout<<"Select one of the following :-"<<endl<<endl;
		cout<<" 1. Dotted Line.\n 2. Dashed Line.\n 3. Dot-Dash Line.\n 4. Thick Line.\n 0. Exit.\n\n";
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
//				line(x1, y1, x2 ,y2);
	    		dline(x1, y1, x2 ,y2,1,11);
	    		break;
			}
			case 2:{
				cout<<"\nEnter first point (x1,y1): ";
				cin >> x1>>y1;
				cout<<"\nEnter second point (x2,y2): ";
				cin >> x2>>y2;
//				line(x1, y1, x2 ,y2);
	    		dline(x1, y1, x2 ,y2,2,14);
				break;
			}
			case 3:{
				cout<<"\nEnter first point (x1,y1): ";
				cin >> x1>>y1;
				cout<<"\nEnter second point (x2,y2): ";
				cin >> x2>>y2;
//				line(x1, y1, x2 ,y2);
	    		dline(x1, y1, x2 ,y2,3);
				break;
			}
			case 4:{
				cout<<"\nEnter first point (x1,y1): ";
				cin >> x1>>y1;
				cout<<"\nEnter second point (x2,y2): ";
				cin >> x2>>y2;
				
				cout<<"Thickness of line : ";
				cin >> thick;
//				line(x1, y1, x2 ,y2);
	    		dline(x1, y1, x2 ,y2,4,thick,6);
	    		
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
