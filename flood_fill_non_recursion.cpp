#include<iostream>
#include<graphics.h>
#include <math.h>
#include <dos.h>
#include<stack>

using namespace std;

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

void floodfil(int x, int y, int f_color){
	/*
	x,y 	-> reference point
	f_color -> fill color
	*/
	
	stack<int> stack;	// initiate the stack
	stack.push(x);		// push refference point into stack
	stack.push(y);
	int initial_color = getpixel(x,y);	// record color of refference point
	/*
	while loop
	 consider top x and y cordinates
	 put colored pixel at x,y
	 
	 check these 2 conditions in 4 or 8 neighbouring points
	 1. color of the neighbouring point should be same as color of reference point
	 2. color of the neighbouring point should not be same as fill color
	 
	 if all the conditions are true then push the respective cordinates into stack
	 */
	while(!stack.empty()){
		int tempy = stack.top();
		stack.pop();
		int tempx = stack.top();
		stack.pop();
		
		putpixel(tempx, tempy, f_color);
		
		if(getpixel(tempx+1,tempy)==initial_color  and getpixel(tempx+1,tempy)!=f_color){
			stack.push(tempx+1);
			stack.push(tempy);
		}
		if(getpixel(tempx-1,tempy)==initial_color  and getpixel(tempx-1,tempy)!=f_color){
			stack.push(tempx-1);
			stack.push(tempy);
		}
		if(getpixel(tempx,tempy+1)==initial_color  and getpixel(tempx,tempy+1)!=f_color){
			stack.push(tempx);
			stack.push(tempy+1);
		}
		if(getpixel(tempx,tempy-1)==initial_color  and getpixel(tempx,tempy-1)!=f_color){
			stack.push(tempx);
			stack.push(tempy-1);
		}
	}
	
}





int main(){
	int gd=DETECT, gm, error, x,y,r;
	initgraph(&gd, &gm,(char*)"");
	
	circle(500, 110, 90);
	floodfil(500,150, 1);
	
	rectangle(100,100, 300,300);
	setcolor(14);
	rectangle(200,200, 500,450);
	setcolor(11);
	rectangle(180,250, 350,360);
	setcolor(10);
	circle(350,320, 80);
	floodfil(320,240,9);
	floodfil(320,340,5);
	floodfil(220,140,13);

//	cout<<"ho gaya";
	
	
	
	
	
	delay(500);
	getch();
	closegraph();
	return 0;
}
