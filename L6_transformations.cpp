#include<iostream>
#include<graphics.h>
#include <math.h>
#include <dos.h>
#include<string>

using namespace std;

/*
functions info:

origin -> to set user define pixel cordinates as origin and to set x and y scales

legend -> to display x,y co-ordinates scales on screen

graph_page -> it will print all labels like origin n all the x,y unit markings on screen just like graph paper(co-ordinate system)

convert -> will use this to convert all the user given co-ordintes to pixel cordinates and store them into respesctive variables

input -> will use this to take user input(float) and convert into pixel co-ordinates then store them in integer array so that we can use converted input for further operations

multy_matrix -> to multiply the 2 matrices

display -> to display resultant matrix

trans -> translation opration

scalling -> scaling operation

rotation -> rotation operation

shear -> shear operation

reflection -> reflection operaion

assign_vertex -> to convert 1-D array(same arry where we stored the user input for polygon co-ordinates) into vector matrix

extract_vertex -> extract resultant verctor co-ordinates from ans matrix then convert them into pixel co-ordinates and plot on screen



working of transformations:

step 1 : initialize genral matrix for respective transformation operation
step 2 : convert vertex arry(user inputs for polygon co-ordinates) into matrix (assign_vertex function)
step 3 : multiply 2 matrices
step 4 : now we have obtained the resultant co-ordinates(based on number system) in ans matrix so now we will extract the respective cordinates according to vertices convert them into pixels and plot on screen(extract_vertex function)  



Driver code:
first pass the input for polygon(i.e. number of vertices an co-ordinates for each)

Select one of the following :-

 1. Translate.		-> translation operataion
 2. Scaling.		-> scaling operation
 3. Rotation.		-> rotation
 4. Shear.			-> shear
 5. Reflection.		-> reflection
 6. New Polygon.	-> to draw new polygon
 0. Exit.			-> to exit the loop
 100.Settings.		-> here you can change the graph settings like position of origin or x-y scale
 
 
*/

class graph_paper{
	public:
		int origin_x, scale_x;
		int origin_y, scale_y;
		float new_x,new_y;
		int n,c_points[100], new_points[100];
		float ans[100][100];
		float pt_vector[3][100];
		float x,y,points[100];
		
		
//		void origin(int xo=getmaxx()/2, int yo=getmaxy()/2, int sx=50, int sy=50){
//			origin_x = xo;
//			origin_y = yo;
//			scale_x = sx;
//			scale_y = sy;
//		}
		
		void legend(){
			
			char str1[20];
			sprintf(str1,"1 X_unit =%d pix",scale_x);
			outtextxy(getmaxx()*0.8,10,str1);
			
			sprintf(str1,"1 Y_unit =%d pix",scale_y);
			outtextxy(getmaxx()*0.8,30,str1);
		}
		
		void graph_page(int xo=getmaxx()/2, int yo=getmaxy()/2, int sx=50, int sy=50){
			origin_x = xo;
			origin_y = yo;
			scale_x = sx;
			scale_y = sy;
			
			char str[3];
			
			
		//	circle(origin_x, origin_y, 3);
			for(int i= origin_x; i<getmaxx(); i+=scale_x){
				line(i,origin_y+3, i,origin_y-3);
				sprintf(str,"%d",(i-origin_x)/scale_x);
				outtextxy(i,origin_y+5,str);
			}
			
			for(int i= origin_x; i>0; i-=scale_x){
				line(i,origin_y+3, i,origin_y-3);
				sprintf(str,"%d",(i-origin_x)/scale_x);
				outtextxy(i,origin_y+5,str);
			}
			
			for(int i= origin_y+scale_y; i<getmaxy(); i+=scale_y){
				line(origin_x+3,i, origin_x-3,i);
				sprintf(str,"%d",(-1)*(i-origin_y)/scale_y);
				outtextxy(origin_x-15,i-5,str);
			}
			
			for(int i= origin_y-scale_y; i>0; i-=scale_y){
				line(origin_x+3,i, origin_x-3,i);
				sprintf(str,"%d",(-1)*(i-origin_y)/scale_y);
				outtextxy(origin_x-15,i-5,str);
			}
			line(0,origin_y, getmaxx(),origin_y);
			line(origin_x,0, origin_x,getmaxy());
			
			legend();
		}
		
		void convert(float x, float y){
			
			new_x = origin_x + x*scale_x;
			new_y = origin_y - y*scale_y;
		}
		
		void drawline(float x1, float y1, float x2, float y2){
			convert(x1,y1);
			x1 = new_x;
			y1 = new_y;
			convert(x2,y2);
			x2 = new_x;
			y2 = new_y;
			line(x1,y1,x2,y2);
			circle(x1,y1,5);
			circle(x2,y2,5);
		}
		
		void input(){
			cout<<"\nEnter no. of vertices : ";
			cin>> n;
			char str[2];
			int v=1;
			for(int i=0; i<n*2; i+=2){
				cout<<"\nCo-ordinates of V"<<(i+2)/2<<" :";
				cin>>x>>y;
//				cout<<endl;
				points[i]=x;
				points[i+1]=y;
				convert(x,y);
//				x=new_x;
//				y=new_y;
				c_points[i]=new_x;
				c_points[i+1]=new_y;
				circle(new_x,new_y,5);
				
//				sprintf(str,"V%d",v);
//				outtextxy(new_x+5,new_y-5, str);
//				v++;
			}
			points[2*n]=points[0];
			points[2*n+1]=points[1];
			
			c_points[2*n]=c_points[0];
			c_points[2*n+1]=c_points[1];
//			cout<<points[2*n]<<points[2*n+1];
		}
		
		void multy_matrix(float a[3][3], float b[3][100]){
			for(int i=0; i<3; i++){
				for(int j=0; j<n; j++){
					ans[i][j]=0;
					for(int k=0; k<3; k++){
						ans[i][j] += a[i][k]*b[k][j];
					}
				}
			}
		}
		
		
		void display(){
			for(int i=0; i<3; i++){
				for(int j=0; j<n; j++){
					cout<<ans[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
		
		void trans(float tx, float ty){
//			convert(tx,ty);
//			tx = new_x;
//			ty = new_y;
			
			float tr[3][3] = {{1,0,tx}, {0,1,ty}, {0,0,1}};
			
			assign_vertex();
			
			multy_matrix(tr,pt_vector);
			cout<< "vector matrix for new co-ordinates is follows :- "<<endl;
			display();
			cout<< endl;
			setcolor(10);
			extract_vertex();
			setcolor(15);
//			for(int i=0; i<n*2+2; i++){
//				cout<<new_points[i]<<"\t";
//			}
		}
		
		void scalling(float sx, float sy, float fx=0, float fy=0){
//			convert(tx,ty);
//			tx = new_x;
//			ty = new_y;
			
			float sc[3][3] = {{sx,0,(1-sx)*fx}, {0,sy,(1-sy)*fy}, {0,0,1}};
			
			assign_vertex();
			
			multy_matrix(sc,pt_vector);
			cout<< "vector matrix for new co-ordinates is follows :- "<<endl;
			display();
			cout<< endl;
			setcolor(11);
			extract_vertex();
			convert(fx,fy);
			for(int i=0; i<5; i++){
				circle(new_x,new_y,i);
			}
			setcolor(15);
//			for(int i=0; i<n*2+2; i++){
//				cout<<new_points[i]<<"\t";
//			}
			
			
		}
		
		void rotation(float deg){
//			convert(tx,ty);
//			tx = new_x;
//			ty = new_y;
			float rad = deg*3.14/180;
			
			float ro[3][3] = {{cos(rad),-sin(rad),0}, {sin(rad),cos(rad),0}, {0,0,1}};
			
			assign_vertex();
			
			multy_matrix(ro,pt_vector);
			cout<< "\nvector matrix for new co-ordinates is follows :- "<<endl;
			display();
			cout<< endl;
			setcolor(12);
			extract_vertex();
			setcolor(15);
//			for(int i=0; i<n*2+2; i++){
//				cout<<new_points[i]<<"\t";
//			}
		}
		
		void shear(float shx=0, float shy=0, float rx=0, float ry=0){
//			convert(tx,ty);
//			tx = new_x;
//			ty = new_y;
			
			float sh[3][3] = {{1, shx, -shx*ry}, {shy,1,-shy*rx}, {0,0,1}};
			
			assign_vertex();
			
			multy_matrix(sh,pt_vector);
			cout<< "vector matrix for new co-ordinates is follows :- "<<endl;
			display();
			cout<< endl;
			setcolor(13);
			extract_vertex();
			convert(rx,ry);
			for(int i=0; i<5; i++){
				circle(new_x,new_y,i);
			}
			setcolor(15);
//			for(int i=0; i<n*2+2; i++){
//				cout<<new_points[i]<<"\t";
//			}
			
		}
		
		void reflection(float x1, float y1, float x2, float y2){
//			convert(tx,ty);
//			tx = new_x;
//			ty = new_y;
			int line[4];
			float m = (y2-y1)/(x2-x1);
			float c = y1 - m*x1;
			float ref[3][3] = {{(1-m*m)/(m*m+1), (2*m)/(m*m+1), (-2*c*m)/(m*m+1)}, {(2*m)/(m*m+1), (m-1)/(m*m+1),(2*c)/(m*m+1)}, {0,0,1}};
			
			convert(x1,y1);
			line[0]=new_x;
			line[1]=new_y;
			convert(x2,y2);
			line[2]=new_x;
			line[3]=new_y;
			setcolor(3);
			drawpoly(2, line);
			assign_vertex();
			
			multy_matrix(ref,pt_vector);
			cout<< "vector matrix for new co-ordinates is follows :- "<<endl;
			display();
			cout<< endl;
			setcolor(14);
			extract_vertex();
			setcolor(15);
//			for(int i=0; i<n*2+2; i++){
//				cout<<new_points[i]<<"\t";
//			}
			
		}
		
		void assign_vertex(){
			for(int i=0; i<2*n; i+=2){
				pt_vector[0][i/2]=points[i];
				pt_vector[1][i/2]=points[i+1];
				pt_vector[2][i/2]=1;
			}
		}
		
		void extract_vertex(){
			float x, y;
			
			for(int i=0; i<n*2; i+=2){
				x = ans[0][i/2];
				y = ans[1][i/2];
				
				convert(x,y);
				new_points[i]=new_x;
				new_points[i+1]=new_y;
				circle(new_x,new_y,5);
			}
			new_points[n*2]=new_points[0];
			new_points[n*2+1]=new_points[1];
			drawpoly(n+1, new_points);
			
			for(int i=0; i<n*2+2; i++){
				cout<<new_points[i]<<"\t";
			}
		}
		
};

int main(){
	int gd=DETECT, gm, error;
	initgraph(&gd, &gm,(char*)"");
//	initwindow(1280,720);
	float x1,y1,x2,y2;
	int xc= getmaxx()/2;
	int yc= getmaxy()/2;
	int x_scale = 30;
	int y_scale = 30;
	graph_paper g;
	
	g.graph_page(xc,yc,x_scale,y_scale);
	

	g.input();
	drawpoly(g.n+1, g.c_points);

	int ch ;
	do{
		
		cout<<"\nSelect one of the following :-"<<endl<<endl;
		cout<<" 1. Translate.\n 2. Scaling.\n 3. Rotation.\n 4. Shear.\n 5. Reflection.\n 6. New Polygon.\n 0. Exit.\n 100.Settings.\n\n";
		cout<<"Your Choice :- ";
		cin >> ch;
		switch(ch){
			
			case 1:{
				float tx,ty,x,y;
//				g.input();
//				drawpoly(g.n+1, g.c_points);
				
				cout<<"\nTranslation Scale (Tx,Ty): ";
				cin >>tx>>ty;
				cout<<endl;
				x = tx/20;
				y = ty/20;
				for(int i=1; i<=20; i++){
					delay(50);
					cleardevice();
					g.graph_page(xc,yc,x_scale,y_scale);
					g.trans(x*i,y*i);
				}
				drawpoly(g.n+1, g.c_points);
//				g.trans(tx,ty);
	    		break;
			}
			case 2:{
				float sx,sy,x,y;
				float fx=0;
				float fy=0;
//				g.input();
//				drawpoly(g.n+1, g.c_points);
				string pt;
				cout<<"\nScale w.r.t.(Oringin/Fixed Pt.) :";
				cin>> pt;
				if(pt=="f"){
					cout<<"\nFixed pt Co-ordinates(fx,fy): ";
					cin >> fx>>fy;
				}
				cout<<"\nScaling Factors (Sx,Sy): ";
				cin >>sx>>sy;
				cout<<endl;
				x = sx/20;
				y = sy/20;
				for(int i=1; i<=20; i++){
					delay(50);
					cleardevice();
					g.graph_page(xc,yc,x_scale,y_scale);
					g.scalling(x*i,y*i,fx,fy);
				}
				drawpoly(g.n+1, g.c_points);
				break;
			}
			case 3:{
//				g.input();
//				drawpoly(g.n+1, g.c_points);
				float deg,x;
				
				cout<<"\nRotation Angel (thita):";
				cin >>deg;
				cout<<endl;
				x=deg/30;
				for(int i =1; i<=30; i++){
					delay(50);
					cleardevice();
					g.graph_page(xc,yc,x_scale,y_scale);
					g.rotation(x*i);
				}
				drawpoly(g.n+1, g.c_points);
				break;
			}
			case 4:{
				float shx,shy,x,y;
				float fx=0;
				float fy=0;
//				g.input();
//				drawpoly(g.n+1, g.c_points);
				string pt;
				cout<<"\nShear w.r.t.(Only X/Only Y/Both) :";
				cin>> pt;
				if(pt=="x"){
					cout<<"\nX Shear factor(Shx): ";
					cin >> shx;
					cout<<"\nY refference(Yref):";
					cin >> fy;
				}
				else if(pt=="y"){
					cout<<"\nY Shear factor(Shy): ";
					cin >> shy;
					cout<<"\nX refference(Xref):";
					cin >> fx;
				}
				else{
					cout<<"\nXY Shear factor(Shx,Shy): ";
					cin >>shx>>shy;
					cout<<"\nXY refference(Xref,Yref):";
					cin >> fx>>fy;
				}
				x = shx/20;
				y = shy/20;
				
				for(int i=1; i<=20; i++){
					delay(50);
					cleardevice();
					g.graph_page(xc,yc,x_scale,y_scale);
					g.shear(x*i,y*i,fx,fy);
				}
				drawpoly(g.n+1, g.c_points);
				shx=shy=fx=fy=0;
				break;
			}
			case 5:{
				float x1,x2,y1,y2;
//				g.input();
//				drawpoly(g.n+1, g.c_points);
				
				cout<<"\nCo-ordinates of 1st point (x1,y1): ";
				cin >>x1>>y1;
				cout<<endl;
				cout<<"\nCo-ordinates of 2st point (x2,y2): ";
				cin >>x2>>y2;
				cout<<endl;
				cleardevice();
				drawpoly(g.n+1, g.c_points);
				g.graph_page(xc,yc,x_scale,y_scale);
				g.reflection(x1,y1,x2,y2);
	    		break;
			}
			case 6:{
				cleardevice();
				g.graph_page(xc,yc,x_scale,y_scale);
				g.input();
				drawpoly(g.n+1, g.c_points);
				break;
			}
			case 100:{
				
				cout<<"\nSet Origin Co-ordinates (Xc,Yc):";
				cin >>xc>>yc;
				
				cout<<"\nOn X-axis	1 unit =";
				cin >>x_scale;
				
				cout<<"\nOn Y-axis	1 unit =";
				cin >>y_scale;
				
				cleardevice();
				g.graph_page(xc,yc,x_scale,y_scale);
				break;
			}
			default:{
				cout<<"invalid choice...!___Try again...\n\n"<<endl;
			}
		}
	}while(ch!=0);
	
	
	
	
	delay(500);
	getch();
	closegraph();
	return 0;
}
