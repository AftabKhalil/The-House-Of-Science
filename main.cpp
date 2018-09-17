#include<dos.h>																		//DELAY 
#include<math.h>																	//MATH
#include<conio.h>																	//CONSOLE INPUT OUTPUT
#include<stdio.h>																	//STANDARD INPUT OUTPUT
#include<stdlib.h>																	//STANDARD LIBRARY
#include<string.h>																	//STRING
#include<windows.h>																	//WINDOWS
#include<graphics.h>																//GRAPHICS


void TITLE (void);																	//TITLE FUNCTION 
void HOME (void);																	//HOME FUNCTION

void BUTTON(int x, int y, int sx, char str[]);										//BUTTON
void S_BUTTON(int lx, int ty, int rx, int sx, char str[]);							//SPECIAL BUTTON FOR LARGE STRINGS
void C_S(int x, int y, int nx, int ny, char sn[]);									//CALCULATOR SIGHNS BUTTON

int click (int *xpos,int *ypos);													//MOUSE CLICK FUNTION
void wait(int a);																	//MY WAIT FUNCTION
			
void CHEMISTRY(void); void CHEMISTRY_2(void);										//CHEMISTRY
void PHYSICS(void);	  void PHYSICS_2(void);											//PHYSICS
void COMPUTER(void);  void COMPUTER_2(void);										//COMPUTER
void MATH(void);																	//MATH ROOM

void ROOM(char s1[], int s1x, char s2[], int s2x, char s3[], int s3x, char s4[], int s4x);		//ROOM 1st PROTOTYPE
void ROOM_2(char s1[], int s1x, char s2[], int s2x, char s3[], int s3x, char s4[], int s4x);	//ROOM 2nd PROTOTYPE

void CALCULATOR (void);																//CALCULATOR UTILITY PROTOTYPE
void GRAPH(void);																	//GRAPHING UTILITY PROTOTYPE
void NOT_GATE(void);																//NOT GATE
void AND_GATE(void);																//AND GATE
void OR_GATE(void);																	//OR GATE
void XOR_GATE(void);																//XOR GATE
void RGFE(void);																	//RUTHERFORD GOLD FOIL EXPERIMENT
void EOW(void);																		//ELECTROLYSIS OF WATER
void CMB(void);																		//CHEMICAL BOND
void P_M(void);																		//PROJECTILE MOTION
void SP_L(void);																	//SPHERICAL LENSES
void COM(void);																		//CONSERVATION OF MOMENTUM
void DP_E(void);																	//DOPLLERS EFFECT

void cr(int result);																//CALCULATOR FUNCTION RESULT
void cip(void);																		//CLEAR INPUT-DISPLAY IN PROJECTILE
void I_B(void);																		//IONIC-BOND
void C_B(void);																		//COVELENT-BOND
void COC_B(void);																	//CO-ORDINATR COVELENT BOND
void CR_E(void);																	//CATHODE RAY EXPERIMENT
void CX_L(void);																	//CONVEX LENS
void CV_L(void);																	//CONCAVE LENS
void MC_D(void);																	//MOMENTUM CONSERVATION DIAGRAM


/*==MAIN.FUNCTION===*/
main()																				// THE MAIN FUNCTION
{
    initwindow(1200,720,"THE HOUSE OF SCIENCE",0,0,false,true);						//PROGRAM RESOLUTION
    delay(2000);    			 
	TITLE();																		//CALLS TITLE
	HOME();																			//CALLS HOME
}

/*=========TITLE========*/
void TITLE (void){
		int i,j;														//variables
		setcolor(10);
  		settextstyle(4,0,5);
  		outtextxy(200,100,"HELLO !");
		delay(150);    
		outtextxy(320,300,"AND WELCOME...");
		delay(1000);
	
		setcolor(CYAN);
		PlaySound("C:/THE_HOUSE_OF_SCIENCE/load.wav", NULL, SND_ASYNC);
		setcolor(13);
		cleardevice();
  		outtextxy(300,100,"\"THE HOUSE OF\"");
		outtextxy(395,200,"\"SCIENCE\"");
		settextstyle(1,0,2);
		setcolor(RED);
		outtextxy(105,520,"ENSURE YOUR P.C SPEAKERS ARE WORKING PROPERLY");
	
		setcolor(CYAN);
		outtextxy(485,400,"Constructing...");
		rectangle(485,425,695,440);
	for(i=0;i<=210;i++){												//SHOWS CONSTRUCTION LINE
		delay(25);
		line(485+i,425,485+i,440);
		j=j+100;
	}
		delay(200);
}

/*========HOME=========*/
void HOME (void){
		int i,xpos, ypos;
		
		cleardevice();
		delay(500);
		PlaySound("C:/THE_HOUSE_OF_SCIENCE/hp_1.wav", NULL, SND_ASYNC);		//PLAYS HOME SOUND
		setlinestyle(SOLID_LINE,1,4);
		setcolor(CYAN);
		line(200,200,200,500);			//left line of entrance 
		line(200,500,400,500);			//bottom line of entrance
		line(400,500,400,200);			//right line of entrance
		line(810,210,810,500);			//right line of room
		line(810,500,400,500);			//bottom line of room
		circle(300,180,30);				//light entrance of house
		setcolor(BROWN);
		line(190,210,300,100);			//left line of roof1
		line(300,100,410,210);			//right line of roof1
		line(700,100,810,210);			//right line of roof2
		line(300,100,700,100);			//upper line of roof2
		line(410,210,810,210);			//lower line of roof2
		setfillstyle(XHATCH_FILL,BROWN);
		floodfill(450,200,BROWN);		//coloring the roof
		line(220,300,220,500);			//left line of door
		line(220,300,380,300);			//upper line of door
		line(380,300,380,500);			//right line of door
		line(220,500,380,500);			//bottom line of door
		setfillstyle(INTERLEAVE_FILL,BROWN);
		floodfill(230,310,BROWN);		//coloring the door
		setcolor(BLACK);
		circle(235,400,5);				//door lock
	
/*========TREE========*/
		setcolor(BROWN);				//CONSTRUCTION TREE
		arc(700,350,330,30,300);
		arc(1330,350,150,210,300);
		setcolor(GREEN);
		arc(940,270,120,360,50);
		arc(900,200,90,300,60);
		arc(900,140,30,270,70);
		arc(1000,100,330,200,90);
		arc(1100,140,270,150,70);
		arc(1100,200,260,100,60);
		arc(1090,270,180,80,50);
		
/*========BUTTONS======*/
		BUTTON(410,220,420,"CHEMISTRY");			//BUTTON TO CALL CHEMISTRY ROOM 
		BUTTON(600,270,635,"PHYSICS");				//BUTTON TO CALL PHYSICS ROOM
		BUTTON(410,320,420,"COMPUTER");				//BUTTON TO CALL COMPUTER LAB
		BUTTON(600,370,645,"MATHS");				//BUTTON TO CALl MATHS EXPERIENCE
		BUTTON(500,440,550,"EXIT");					//EXIT
		
	while(1){
		click(&xpos,&ypos);																				//USER'S CLICKS
		if (xpos>410&&xpos<590&&ypos>220&&ypos<260) 	{PlaySound(NULL, 0, 0); CHEMISTRY();		}					//CALLS CHEMISTRY
		if (xpos>600&&xpos<780&&ypos>270&&ypos<310)		{PlaySound(NULL, 0, 0); PHYSICS();			}					//CALLS PHYSICS
		if (xpos>410&&xpos<590&&ypos>320&&ypos<360)		{PlaySound(NULL, 0, 0); COMPUTER();			}					//CALLS COMPUTER
		if (xpos>600&&xpos<780&&ypos>370&&ypos<410)		{PlaySound("C:/THE_HOUSE_OF_SCIENCE/door.wav", NULL, SND_ASYNC);		delay(2000);	 MATH();}			//CALLS MATHS
		if (xpos>500&&xpos<680&&ypos>440&&ypos<480) 	{		closegraph();
																PlaySound("C:/THE_HOUSE_OF_SCIENCE/hp_3.wav", NULL, SND_ASYNC);
																printf("\n\n\n\n\n\t\tGOOD  BYE...\n\n\t\t\t\tHAVE  A  NICE  TIME    !   !  ! !!!.. ");
																delay(2000);
																return;
														}													
	}
}

/*========BUTTON========*/
void BUTTON (int x, int y,int sx, char str[]){
		setcolor(CYAN);														
		setlinestyle(0,0,3);												//SETS BUTTON WIDTH
		rectangle(x,y,x+180,y+40);											//DRAWS BUTTTON
		setcolor(BROWN);
		setlinestyle(0,0,1);
		rectangle(x+5,y+5,x+175,y+35);
		setcolor(CYAN);
		settextstyle(6,0,1);
		outtextxy(sx,y+10,str);												//PRINTS BUTTON STRING
}

/*========SPECIAL-BUTTON========*/
void S_BUTTON (int lx, int ty, int rx, int sx, char str[]){
	setcolor(CYAN);
	setlinestyle(0,0,3);														//SETS BUTTON WIDTH
	rectangle(lx,ty,rx,ty+40);													//DRAWS BUTTTON
	setcolor(BROWN);
	setlinestyle(0,0,1);
	rectangle(lx+5,ty+5,rx-5,ty+35);
	setcolor(CYAN);
	settextstyle(6,0,1);
	outtextxy(sx,ty+10,str);														//PRINTS BUTTON STRING	
}

/*========CLICK========*/
int click (int *xpos,int *ypos){
	while(1){																	//INFINITE LOOP TO WAIT FOR USER RESPONSE
			delay(100);
		if((ismouseclick(WM_LBUTTONDOWN))){										//IF LEFT-MOUSE-BUTTON IS PRESSED
			Beep(1000,50);
			getmouseclick(WM_LBUTTONDOWN, *xpos, *ypos);						//RETURNS MOUSE CLICK POSITION
			break;																//END THE FUNCTION
		}
	}
}

/*========MY-DELAY-FUNCTION========*/
void wait(int a){
	int i,j,k=0;
	for(i=0;i<=a;i++){
		for(j=0;j<=1000;j++)k++;
	}
}

/*========CALCULATOR-RESULT========*/
void cr(int result){
		int temp,value,i=0;														//variables
		char oput[20];															//output array
		temp=result;															//TEMPORARY VARIABLE STORE RESULT INT VALUE
	while(temp!=0){																//CONVERT INT TO CHAR
		value=temp%10;
		temp=temp/10;
		oput[i]=value+'0';
		i++;	
	}
		oput[i]='\0';
		strrev(oput);															//REVERSE THE CHARACTERS
		setcolor(CYAN);
		outtextxy(260,150,oput);												//PRINTS THE CHARACTERS
}

/*========CALCULATOR-SIGHNS-BUTTON========*/
void C_S(int x, int y, int sx, int sy, char sn[]){
		setcolor(CYAN);
		setlinestyle(0,0,3);													//SETS BUTTON WIDTH
		rectangle(x,y,x+150,y+60);												//DRAWS BUTTON
		setcolor(BROWN);
		setlinestyle(0,0,1);
		rectangle(x+5,y+5,x+145,y+55);
		setcolor(CYAN);
		settextstyle(6,0,1);
		outtextxy(sx,sy,sn);												//PRINTS SIGHN ON SCREEN
}

/*========MATHS-ROOM========*/
void MATH(void){
	
		cleardevice();														//CLEAR PREVIOUS DISPLAY
		PlaySound("C:/THE_HOUSE_OF_SCIENCE/hp_2.wav", NULL, SND_ASYNC);		//PLAY ROOM SOUND
		int xpos, ypos;														//MOUSE VARIABLES
		setcolor(BROWN);
		setlinestyle(0,0,3);
		ellipse(600,350,0,0,350,90);										//DRAWING THE TABLE
		ellipse(600,360,179,1,350,95);
		line(400,440,350,680); //l1
		line(425,442,380,690);  //l1
		line(350,680,380,690);  //l1
		line(440,445,410,685);  //l1
		line(380,690,410,685);  //l1
		line(800,440,850,680);  //l2
		line(775,442,820,690);  //l2
		line(850,680,820,690);  //l2
		line(760,445,790,685);  //l2
		line(820,690,790,685);  //l2
		line(587,455,575,655);  //lm
		line(613,455,613,660);  //lm
		line(575,655,613,660);  //lm
		line(625,455,635,650);  //lm 
		line(613,660,635,650);  //lm
		
		setfillstyle(INTERLEAVE_FILL,BROWN);											//COLORING TABLE 
		floodfill(600,350,BROWN);	
		setfillstyle(LINE_FILL,BROWN);
		floodfill(600,452,BROWN);
		setfillstyle(LTSLASH_FILL,BROWN);												
		floodfill(405,450,BROWN);
		floodfill(430,450,BROWN);
		floodfill(592,460,BROWN);
		floodfill(620,460,BROWN);
		floodfill(770,450,BROWN);
		floodfill(790,450,BROWN);
		
		rectangle(100,100,210,255);													//FLOWER SCENRY
		circle(150,150,10);
		setcolor(RED);
		circle(150,125,15);
		circle(172,146,15);
		circle(162,173,15);
		circle(135,170,15);
		circle(127,145,15);
		setcolor(GREEN);
		arc(150,205,300,60,50);
		
		setfillstyle(INTERLEAVE_FILL,CYAN);										//COLURING THE ROOM
		floodfill(1,1,BROWN);
		
		S_BUTTON(350,300,555,360,"CALCULATOR");									//BUTTON FOR CALCULATOR
		BUTTON(600,350,615,"GRAPHING");										//BUTTON FOR GRAPHING
		BUTTON(1000,5,1050,"HOME");											//BUTTON FOR HOME
		
		delay(1000);
									
	while(1){
		delay(100);
		click(&xpos,&ypos);																				//USER MOUSE CLICK
		if(xpos>350&&xpos<555&&ypos>300&&ypos<340) 	{	PlaySound(NULL,0,0);	CALCULATOR();}			//CALLS CALCULATOR
		if(xpos>600&&xpos<780&&ypos>350&&ypos<390) 	{	PlaySound("C:/THE_HOUSE_OF_SCIENCE/graph.wav", NULL, SND_ASYNC);	GRAPH();}				//CALLS GRAPH
		if(xpos>1000&&xpos<1180&&ypos>5&&ypos<45)	{	PlaySound(NULL,0,0);	HOME();}				//CALLS HOME
	}
}

/*========CALCULATOR========*/
void CALCULATOR (void){	

		int xpos=0,ypos=0;																				//MOUSE CLICK VARIABLES
		int opo=0,opt=0,result=0;																		//INT AND CHARACTERS VARIABLES
		int temp=0,value=0,i=0,j=0;																	
		char a[10],opp;																					
		char arr[0], oput[10];	
		
		cleardevice();																					//CLEAR PREVIOUS DISPLAY
		setcolor(BROWN);
		setlinestyle(0,0,4);
		rectangle(200,100,1100,660);																	//DRAWING CALCULATOR
		rectangle(250,120,1050,220);
		BUTTON(250,250,335,"1");																	//1
		BUTTON(250,330,335,"2");																	//2
		BUTTON(250,410,335,"3");																	//3	
		BUTTON(250,490,335,"4");																	//4
		BUTTON(250,570,335,"5");																	//5
		BUTTON(480,250,565,"6");																	//6
		BUTTON(480,330,565,"7");																	//7
		BUTTON(480,410,565,"8");																	//8
		BUTTON(480,490,565,"9");																	//9	
		BUTTON(480,570,565,"0");																	//0
		C_S(710,250,780,270,"+");																		//+
		C_S(880,250,950,260,"_");																		//-
		C_S(710,350,780,370,"X");																		//*		
		C_S(880,350,950,370,"/");																		///
		C_S(800,500,870,520,"=");																		//=
		
		settextstyle(3,0,5);
		
		while(1){
			delay(100);
			click(&xpos,&ypos);
				if(xpos>710&&xpos<860&&ypos>250&&ypos<310) {outtextxy(260+i,150,"WRITE A NO FIRST"); delay(1000); CALCULATOR();}
				if(xpos>880&&xpos<1030&&ypos>250&&ypos<310){outtextxy(260+i,150,"WRITE A NO FIRST"); delay(1000); CALCULATOR();}		 
				if(xpos>710&&xpos<860&&ypos>350&&ypos<410) {outtextxy(260+i,150,"WRITE A NO FIRST"); delay(1000); CALCULATOR();}		 
				if(xpos>880&&xpos<1030&&ypos>350&&ypos<410){outtextxy(260+i,150,"WRITE A NO FIRST"); delay(1000); CALCULATOR();}
				if(xpos>800&&xpos<950&&ypos>500&&ypos<560) {outtextxy(260+i,150,"WRITE A NO FIRST"); delay(1000); CALCULATOR();}
				else break;	
		}
		
	while(1){																	
		if(xpos>250&&xpos<430&&ypos>250&&ypos<290) {opo=(opo*10)+1;a[0]='1';outtextxy(260+i,150,a);i=i+30;} 							//1
		if(xpos>250&&xpos<430&&ypos>330&&ypos<370) {opo=(opo*10)+2;a[0]='2';outtextxy(260+i,150,a);i=i+30;} 							//2
		if(xpos>250&&xpos<430&&ypos>410&&ypos<450) {opo=(opo*10)+3;a[0]='3';outtextxy(260+i,150,a);i=i+30;} 							//3	
		if(xpos>250&&xpos<430&&ypos>490&&ypos<530) {opo=(opo*10)+4;a[0]='4';outtextxy(260+i,150,a);i=i+30;} 							//4
		if(xpos>250&&xpos<430&&ypos>570&&ypos<610) {opo=(opo*10)+5;a[0]='5';outtextxy(260+i,150,a);i=i+30;} 							//5
		if(xpos>480&&xpos<660&&ypos>250&&ypos<290) {opo=(opo*10)+6;a[0]='6';outtextxy(260+i,150,a);i=i+30;} 							//6
		if(xpos>480&&xpos<660&&ypos>330&&ypos<370) {opo=(opo*10)+7;a[0]='7';outtextxy(260+i,150,a);i=i+30;} 							//7
		if(xpos>480&&xpos<660&&ypos>410&&ypos<450) {opo=(opo*10)+8;a[0]='8';outtextxy(260+i,150,a);i=i+30;} 							//8
		if(xpos>480&&xpos<660&&ypos>490&&ypos<530) {opo=(opo*10)+9;a[0]='9';outtextxy(260+i,150,a);i=i+30;} 							//9
		if(xpos>480&&xpos<660&&ypos>570&&ypos<610) {opo=(opo*10);a[0]='0'  ;outtextxy(260+i,150,a);i=i+30;}   							//0
		
			
			
		delay(100);
		click(&xpos,&ypos);
			
		if(xpos>710&&xpos<860&&ypos>250&&ypos<310){opp='+'; outtextxy(260+i,150,"+"); i=i+30;break;}			 //+
		if(xpos>880&&xpos<1030&&ypos>250&&ypos<310){opp='-'; outtextxy(260+i,150,"-");i=i+30;break;}			 //-
		if(xpos>710&&xpos<860&&ypos>350&&ypos<410){opp='*'; outtextxy(260+i,150,"X"); i=i+30;break;}			 //*
		if(xpos>880&&xpos<1030&&ypos>350&&ypos<410){opp='/'; outtextxy(260+i,150,"/");i=i+30;break;} 			///
	}
	

		while(1){																						//USER CLICK
		delay(100);
		click(&xpos,&ypos);
		
		if(xpos>250&&xpos<400&&ypos>250&&ypos<290) {opt=(opt*10)+1;a[0]='1';outtextxy(260+i,150,a);i=i+30;} 								//1
		if(xpos>250&&xpos<400&&ypos>330&&ypos<370) {opt=(opt*10)+2;a[0]='2';outtextxy(260+i,150,a);i=i+30;} 								//2
		if(xpos>250&&xpos<400&&ypos>410&&ypos<450) {opt=(opt*10)+3;a[0]='3';outtextxy(260+i,150,a);i=i+30;} 								//3	
		if(xpos>250&&xpos<400&&ypos>490&&ypos<530) {opt=(opt*10)+4;a[0]='4';outtextxy(260+i,150,a);i=i+30;} 								//4
		if(xpos>250&&xpos<400&&ypos>570&&ypos<610) {opt=(opt*10)+5;a[0]='5';outtextxy(260+i,150,a);i=i+30;} 								//5
		if(xpos>480&&xpos<630&&ypos>250&&ypos<290) {opt=(opt*10)+6;a[0]='6';outtextxy(260+i,150,a);i=i+30;} 								//6
		if(xpos>480&&xpos<630&&ypos>330&&ypos<370) {opt=(opt*10)+7;a[0]='7';outtextxy(260+i,150,a);i=i+30;} 								//7
		if(xpos>480&&xpos<630&&ypos>410&&ypos<450) {opt=(opt*10)+8;a[0]='8';outtextxy(260+i,150,a);i=i+30;}									//8
		if(xpos>480&&xpos<630&&ypos>490&&ypos<530) {opt=(opt*10)+9;a[0]='9';outtextxy(260+i,150,a);i=i+30;} 								//9
		if(xpos>480&&xpos<630&&ypos>570&&ypos<610) {opt=(opt*10);a[0]='0'  ;outtextxy(260+i,150,a);i=i+30;}   								//0
		
		delay(200);
		
		if(xpos>800&&xpos<950&&ypos>500&&ypos<560) break; 													//=
	} 											

		setcolor(BROWN);
		setlinestyle(0,0,4);
		rectangle(250,120,1050,220);
		setfillstyle(SOLID_FILL,BLACK);
		floodfill(260,130,BROWN);

if(opp=='/'&&opt==0){setcolor(LIGHTRED);outtextxy(260,150,"MATH ERROR"); delay(1000); CALCULATOR();}

else{
	switch(opp){																						//PERFORM CALCULATOR FUNCTION
		case('+'):{result=opo+opt;break;}
		case('-'):{result=opo-opt;break;}
		case('*'):{result=opo*opt;break;}
		case('/'):{result=opo/opt;break;}
	}
}
	
		if(result==0)outtextxy(260,150,"0");
		else {cr(result);}																			//CALLS RESULTS TO PRINT THE RESULT								
		
		delay(100);
	
		BUTTON(1020,0,1030,"    BACK !");																//BACK BUTTON
		BUTTON(840,0,850,"   CLEAR  !");																//REUSE BUTTON
	
	while(1){
			click(&xpos,&ypos);																			//USER-CLICK
		if(xpos>1020&&ypos<40){MATH();}																	//CALLS MATH
		if(xpos>840&&xpos<1020&&ypos<40){CALCULATOR();}													//CALLS CALCULATOR FOR REUSE AGAIN
			delay(100);
	}														
}

/*========GRAPHING-UTILITY========*/
void GRAPH(void){
	
		cleardevice();																//clear previous display
		int xpos,ypos;																//mouse position variables
		int i;																		//VARIABLES
		int y,x,slope=1,yisp=0;
		char slp[1],c[1];
		char s='1', r='0';
		setcolor(CYAN);
		settextstyle(0,0,3);
	
		setcolor(GREEN);
  		outtextxy(20,20,"LINEAR EQUATIONS ARE OF THE FORM \" Y = m X + C \" .");
		delay(10);
	
		setcolor(LIGHTRED);
		outtextxy(20,50,"WHERE \"m\" REPRESENTS THE \"SLOPE\" ,");
		delay(10);
	
		outtextxy(20,80,"AND \"C\" REPRESENTS THE \"Y\" INTERCEPT .");
		delay(10);
	
		setcolor(CYAN);
		outtextxy(20,120,"WRITE YOUR EQUATION HERE Y = m X + C .");
		
		settextstyle(2,0,4);
		outtextxy(915,125,"|| CLICK ON \"m\" TO EDIT SLOPE.");
		outtextxy(915,137,"|| CLICK ON \"C\" TO EDIT Y INTERCEPT.");
		
		rectangle(705,117,750,150);
		rectangle(850,117,895,150);
	
		BUTTON(965,185,972,"GIVE GRAPH");
	
	for(i=0;i<=1100;i=i+10){															//x-axis coordinates
		line(50+i,390,50+i,400);
	}
	
	for(i=0;i<=470;i=i+10){																//y-axis coordinates
		line(595,175+i,605,175+i);
	}
	
		setlinestyle(0,0,4);
		setcolor(MAGENTA);
		rectangle(50,170,1150,650);															//graph window
		setcolor(CYAN);
		line(600,170,600,650);																//x-axis
		line(50,395,1150,395);																//y-axis
			
		setlinestyle(0,0,1);
	
		while(1){																			//inputs slope and y-intercept
			delay(100);
			click(&xpos,&ypos);
	
			if(xpos>=705&&xpos<=750&&ypos>=117&&ypos<=150){setcolor(BLACK);for(i=0;i<=43;i++){line(706+i,118,706+i,150);};setcolor(CYAN);rectangle(705,117,750,150);slp[0]=getch();slope=slp[0]-48; if(slope>=0&&slope<=9){slp[1]='\0';setcolor(CYAN);outtextxy(710,120,slp); } if(slope<0||slope>9) { slope=1; slp[0]=s; setcolor(CYAN); outtextxy(710,120,"1"); }
				while(1){	
							delay(100);	 
							if(kbhit()){slp[1]=getch(); if(slp[1]-48>=0&&slp[1]-48<=9) {slope=(slope*10)+(slp[1]-48);outtextxy(710,120,slp);} if(slp[1]-48<0||slp[1]-48>9){slope=1; outtextxy(710,120,"0 1"); } break;}
							if(ismouseclick(WM_LBUTTONDOWN))break;
				}	
			}
			
			if(xpos>=850&&xpos<=895&&ypos>=117&&ypos<=150){setcolor(BLACK);for(i=0;i<=43;i++){line(851+i,118,851+i,150);};setcolor(CYAN);rectangle(850,117,895,150);c[0]=getch();yisp=c[0]-48; if(yisp>=0&&yisp<=9){c[1]='\0';setcolor(CYAN);outtextxy(852,120,c); } if(yisp<0||yisp>9) { yisp=0; c[0]=r; setcolor(CYAN); outtextxy(852,120,"0"); } 
				while(1){	
							delay(100);	 
							if(kbhit()){c[1]=getch(); if(c[1]-48>=0&&c[1]-48<=9) {yisp=(yisp*10)+(c[1]-48); c[2]='\0'; outtextxy(852,120,c);}  if(c[1]-48<0||c[1]-48>9) { yisp=0; outtextxy(852,120,"0 0"); } break;  }
							if(ismouseclick(WM_LBUTTONDOWN))break;
				}
			}
			
			if(kbhit())getch();
			
			if(xpos>=965&&xpos<=1145&&ypos>=185&&ypos<=225)break;
		}
	
		setcolor(BLACK);
	
		for(i=0;i<=190;i++){																//removes GIVE GRAPH button
			line(956+i,182,956+i,227);
		}
	
	  	for(i=-700;i<=300;i++){																//draws the graph
  			wait(300);
  
  			x=600+i;
  			y=395+((-slope*i)+(-yisp*10));
  			if(y<=648&&y>=173)putpixel(x,y,BLUE);
		}
	
		BUTTON(965,185,1005,"BACK");													//shows HOME button
		BUTTON(965,230,1005,"REUSE");													//reuse GRAPH button
	
		while(1){
			delay(200);
			click(&xpos,&ypos);
			if(xpos>=965&&xpos<=1145&&ypos>=185&&ypos<=225)MATH();							//calls HOME
			if(xpos>=965&&xpos<=1145&&ypos>=230&&ypos<=270)GRAPH();							//calls GRAPH again
		}						
}

/*================ROOM.1===============*/
void ROOM(char s1[], int s1x, char s2[], int s2x, char s3[], int s3x, char s4[], int s4x){
		delay(1700);
		PlaySound("C:/THE_HOUSE_OF_SCIENCE/hp_2.wav", NULL, SND_ASYNC);		//PLAYS HOME SOUND
		int i,x,y;															//variables;	
		
		cleardevice();													//cleardevice
		setfillstyle(INTERLEAVE_FILL,CYAN);								//ROOM  COLOR
		floodfill(0,0,BROWN);											// COLORING ROOM

		setlinestyle(0,0,4);
		setcolor(BLACK);
		line(100,0,100,600);											//ROOM BOUNDRIES
		line(100,600,0,700);
		line(100,600,1400,600);

		setcolor(BROWN);												//CONSTRUCTING CUPBOARD
		setlinestyle(0,0,5);
		rectangle(350,100,950,650);
		rectangle(355,105,945,645);
		line(350,100,400,50);
		line(400,50,1000,50);
		line(1000,50,950,100);
		line(1000,50,1000,600);
		line(1000,600,950,650);

		setfillstyle(SOLID_FILL,BLACK);									//POLISHING CUPBOARD
		floodfill(400,80,BROWN);
		floodfill(960,200,BROWN);
		floodfill(400,120,BROWN);
		setfillstyle(LINE_FILL,BROWN);
		floodfill(400,80,BROWN);
		floodfill(960,200,BROWN);

		setcolor(BROWN);											//MAKING CUPBOARD DOORS
		rectangle(350,100,650,650);
		floodfill(360,120,BROWN);
		rectangle(650,100,950,650);
		floodfill(900,120,BROWN);

		delay(1000);												//OPENING CUPBOARD DOORS
	for(i=0;i<=300;i++){
			setcolor(BROWN);
			rectangle(350-i,100,650-i,650);
			floodfill(360-i,120,BROWN);
			rectangle(650+i,100,950+i,650);
			floodfill(900+i,120,BROWN);
			setcolor(BLACK);

			line(355-i,110,355-i,640);
			line(655-i,110,655-i,640);
			line(645+i,110,645+i,640);
			line(945+i,110,945+i,640);
		}

		setfillstyle(INTERLEAVE_FILL,BROWN);					//INSIDE CUPBOARD
		floodfill(360,120,BROWN);
		setcolor(YELLOW);
		arc(650,110,180,0,20);
		line(630,110,670,110);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(650,115,YELLOW);
		setcolor(BLACK);
	for(i=0;i<=300;i+=100){
			line(360,250+i,940,250+i);
		}
	
		S_BUTTON(370,200,930,s1x,s1);						//BUTTONS
		S_BUTTON(370,300,930,s2x,s2);
		S_BUTTON(370,400,930,s3x,s3);
		S_BUTTON(370,500,930,s4x,s4);
		BUTTON(120,10,160,"HOME !");
}

/*==============ROOM.2===============*/
void ROOM_2(char s1[], int s1x, char s2[], int s2x, char s3[], int s3x, char s4[], int s4x){
		
		PlaySound("C:/THE_HOUSE_OF_SCIENCE/hp_2.wav", NULL, SND_ASYNC);		//PLAYS HOME SOUND
		int i=300,x,y;														//variables;	
		
		cleardevice();													//cleardevice
		setfillstyle(INTERLEAVE_FILL,CYAN);								//ROOM  COLOR
		floodfill(0,0,BROWN);											// COLORING ROOM

		setlinestyle(0,0,4);
		setcolor(BLACK);
		line(100,0,100,600);											//ROOM BOUNDRIES
		line(100,600,0,700);
		line(100,600,1400,600);

		setcolor(BROWN);												//CONSTRUCTING CUPBOARD
		setlinestyle(0,0,5);
		rectangle(350,100,950,650);
		rectangle(355,105,945,645);
		line(350,100,400,50);
		line(400,50,1000,50);
		line(1000,50,950,100);
		line(1000,50,1000,97);

		floodfill(400,80,BROWN);
		floodfill(960,200,BROWN);
		floodfill(400,120,BROWN);
		setfillstyle(LINE_FILL,BROWN);
		floodfill(400,80,BROWN);
	
		rectangle(350-i,100,650-i,650);
		floodfill(360-i,120,BROWN);
		rectangle(950,100,1250,650);
		for(x=0;x<=100;x++)
		floodfill(1050,150,BROWN);
		floodfill(980,80,BROWN);
	
		setfillstyle(INTERLEAVE_FILL,BROWN);					//INSIDE CUPBOARD
		floodfill(360,120,BROWN);
		setcolor(YELLOW);
		arc(650,110,180,0,20);
		line(630,110,670,110);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(650,115,YELLOW);
		
		setcolor(BLACK);
	for(i=0;i<=300;i+=100){
			line(360,250+i,940,250+i);
		}
	
		S_BUTTON(370,200,930,s1x,s1);						//BUTTONS
		S_BUTTON(370,300,930,s2x,s2);
		S_BUTTON(370,400,930,s3x,s3);
		S_BUTTON(370,500,930,s4x,s4);
		BUTTON(120,10,160,"HOME !");
}

/*==============cCHEMISTRY=============*/
void CHEMISTRY(void){
	int xpos, ypos;
	PlaySound("C:/THE_HOUSE_OF_SCIENCE/door.wav", NULL, SND_ASYNC);								//PLAY DOOR SOUND
	ROOM("RUTHERFORD GOILD-FOIL EXPEREMENT",385,"CATHODE-RAY EXPEREMENT",470,"CHEMICAL BONDING",510,"ELECTROLYSIS OF WATER",480);			//CALLS ROOM CUPDOARD
	while(1){
			delay(100);
			click(&xpos,&ypos);																												//USER CLICKS
		
		if(xpos>=370&&xpos<=930&&ypos>=200&&ypos<=240)	{	PlaySound("C:/THE_HOUSE_OF_SCIENCE/rgfe.wav",NULL,SND_ASYNC);	RGFE(); }
		if(xpos>=370&&xpos<=930&&ypos>=300&&ypos<=340)	{	PlaySound("C:/THE_HOUSE_OF_SCIENCE/cre.wav",NULL,SND_ASYNC);	CR_E();	}
		if(xpos>=370&&xpos<=930&&ypos>=400&&ypos<=440)	{	PlaySound("C:/THE_HOUSE_OF_SCIENCE/cmb.wav",NULL,SND_ASYNC);	CMB() ;	}	
		if(xpos>=370&&xpos<=930&&ypos>=500&&ypos<=540)	{	PlaySound("C:/THE_HOUSE_OF_SCIENCE/eow.wav", NULL, SND_ASYNC);	EOW() ;	}
		if(xpos>=120&&xpos<=300&&ypos>=10&&ypos<=50)																	   HOME() ;
	}
}

/*============CHEMISTRY.2==============*/
void CHEMISTRY_2(void){
	int xpos, ypos;
	ROOM_2("RUTHERFORD GOILD-FOIL EXPEREMENT",385,"CATHODE-RAY EXPEREMENT",470,"CHEMICAL BONDING",510,"ELECTROLYSIS OF WATER",480);
	while(1){
			delay(100);
			click(&xpos,&ypos);
		
		if(xpos>=370&&xpos<=930&&ypos>=200&&ypos<=240)		{	PlaySound("C:/THE_HOUSE_OF_SCIENCE/rgfe.wav",NULL,SND_ASYNC) ;	RGFE(); }
		if(xpos>=370&&xpos<=930&&ypos>=300&&ypos<=340)		{	PlaySound("C:/THE_HOUSE_OF_SCIENCE/cre.wav",NULL,SND_ASYNC)  ; 	CR_E();	}
		if(xpos>=370&&xpos<=930&&ypos>=400&&ypos<=440)		{	PlaySound("C:/THE_HOUSE_OF_SCIENCE/cmb.wav",NULL,SND_ASYNC)  ;	CMB() ;	}	
		if(xpos>=370&&xpos<=930&&ypos>=500&&ypos<=540)		{	PlaySound("C:/THE_HOUSE_OF_SCIENCE/eow.wav", NULL, SND_ASYNC);	EOW() ;	}	
		if(xpos>=120&&xpos<=300&&ypos>=10&&ypos<=50)																	       HOME() ;
	}
}

/*=============PHYSICS=================*/
void PHYSICS(void){
	int xpos, ypos;
	PlaySound("C:/THE_HOUSE_OF_SCIENCE/door.wav", NULL, SND_ASYNC);
	ROOM("CONSERVATION OF MOMENTUM",430,"PROJECTILE MOTION",510,"CONCAVE/CONVEX LENSES",480,"DOPPLER'S EFFECT",520);
	while(1){
			delay(100);
			click(&xpos,&ypos);
		
		if(xpos>=370&&xpos<=930&&ypos>=200&&ypos<=240){																	COM();  }
		if(xpos>=370&&xpos<=930&&ypos>=300&&ypos<=340){	PlaySound("C:/THE_HOUSE_OF_SCIENCE/pm.wav", NULL, SND_ASYNC);	P_M();  }
		if(xpos>=370&&xpos<=930&&ypos>=400&&ypos<=440){	PlaySound("C:/THE_HOUSE_OF_SCIENCE/spl.wav", NULL, SND_ASYNC);	SP_L();	}
		if(xpos>=370&&xpos<=930&&ypos>=500&&ypos<=540){DP_E();}
		if(xpos>=120&&xpos<=300&&ypos>=10&&ypos<=50)HOME();	
	}
}

/*=============PHYSICS.2================*/
void PHYSICS_2(void){
	int xpos, ypos;
	ROOM_2("CONSERVATION OF MOMENTUM",430,"PROJECTILE MOTION",510,"CONCAVE/CONVEX LENSES",480,"DOPPLER'S EFFECT",520);
	while(1){
			delay(100);
			click(&xpos,&ypos);
		
		if(xpos>=370&&xpos<=930&&ypos>=200&&ypos<=240){																		COM();  }
		if(xpos>=370&&xpos<=930&&ypos>=300&&ypos<=340){	PlaySound("C:/THE_HOUSE_OF_SCIENCE/pm.wav", NULL, SND_ASYNC);		P_M();	}
		if(xpos>=370&&xpos<=930&&ypos>=400&&ypos<=440){	PlaySound("C:/THE_HOUSE_OF_SCIENCE/spl.wav", NULL, SND_ASYNC);SP_L();}
		if(xpos>=370&&xpos<=930&&ypos>=500&&ypos<=540){DP_E();}
		if(xpos>=120&&xpos<=300&&ypos>=10&&ypos<=50)  {HOME();}	
	}
}

/*==============COMPUTER===============*/
void COMPUTER(void){
	int xpos, ypos;
	PlaySound("C:/THE_HOUSE_OF_SCIENCE/door.wav", NULL, SND_ASYNC);
	ROOM("NOT GATE",580,"AND GATE",580,"OR GATE",585,"XOR GATE",580);
	while(1){
			delay(100);
			click(&xpos,&ypos);
		
		if(xpos>=370&&xpos<=930&&ypos>=200&&ypos<=240){NOT_GATE();}
		if(xpos>=370&&xpos<=930&&ypos>=300&&ypos<=340){AND_GATE();}
		if(xpos>=370&&xpos<=930&&ypos>=400&&ypos<=440){OR_GATE() ;}
		if(xpos>=370&&xpos<=930&&ypos>=500&&ypos<=540){XOR_GATE();}	
		if(xpos>=120&&xpos<=300&&ypos>=10&&ypos<=50)HOME();	
	}
}

/*=============COMPUTER.2==============*/
void COMPUTER_2(void){
	int xpos, ypos;
	ROOM_2("NOT GATE",580,"AND GATE",580,"OR GATE",585,"XOR GATE",580);
	while(1){
			delay(100);
			click(&xpos,&ypos);
		
		if(xpos>=370&&xpos<=930&&ypos>=200&&ypos<=240){NOT_GATE();}
		if(xpos>=370&&xpos<=930&&ypos>=300&&ypos<=340){AND_GATE();}
		if(xpos>=370&&xpos<=930&&ypos>=400&&ypos<=440){OR_GATE() ;}
		if(xpos>=370&&xpos<=930&&ypos>=500&&ypos<=540){XOR_GATE();}	
		if(xpos>=120&&xpos<=300&&ypos>=10&&ypos<=50)HOME();	
	}
}

/*=============NOT.GATE===============*/
void NOT_GATE(void){
	PlaySound("C:/THE_HOUSE_OF_SCIENCE/notgate.wav", NULL, SND_ASYNC);
	
	int xpos,ypos,i;
	char input[0];
	cleardevice();
	settextstyle(6,0,3);
	setcolor(CYAN);
	outtextxy(50,50,"THE LOGIC GATE WHICH INVERTS THE INPUT FROM .... :");
	setcolor(RED);
	outtextxy(360,100," * HIGH TO LOW !");
	outtextxy(360,150," * LOW TO HIGH !");
	setcolor(CYAN);
	outtextxy(50,200,"IS KNOWN AS \" NOT-GATE \" . ");
	BUTTON(1000,5,1045,"BACK !");
	
	setcolor(MAGENTA);
	setlinestyle(0,0,6);
	rectangle(50,250,1150,650);
	
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,3);
	line(400,425,500,425);
	line(500,350,500,500);
	line(500,350,600,425);
	line(500,500,600,425);
	line(600,425,700,425);
	
	setlinestyle(0,0,1);
	rectangle(350,400,400,449);
	rectangle(701,400,750,450);
	
	settextstyle(2,0,4);
	outtextxy(140,420,"\"CLICK\" AND WRITE  YOUR  INPUT  HERE ====>");
	
	settextstyle(1,0,1);
	
	while(1){
		click(&xpos,&ypos);
		if(xpos>=1000&&xpos<=1180&&ypos>=5&&ypos<=45)COMPUTER_2();
		if(xpos>=350&&xpos<=400&&ypos>=400&&ypos<=450){
			for(i=0;i<=45;i++){setcolor(BLACK);line(351+i,401,351+i,448);line(702+i,401,702+i,448);setcolor(LIGHTCYAN);}
				input[0]=getch();    if(input[0]-'0'==0)outtextxy(362,412,input); else outtextxy(362,412,"1");
				delay(100);
				if(input[0]-'0'==0){rectangle(350,400,400,449);setlinestyle(0,0,3);line(400,425,500,425);delay(100);setlinestyle(0,0,1);outtextxy(714,411,"1");}
		        else			   {rectangle(350,400,400,449);setlinestyle(0,0,3);line(400,425,500,425);delay(100);setlinestyle(0,0,1);outtextxy(714,411,"0");}        
			}
		if(kbhit())getch();
		delay(100);
	}
}

/*=============AND.GATE===============*/
void AND_GATE(void){
	PlaySound("C:/THE_HOUSE_OF_SCIENCE/andgate.wav", NULL, SND_ASYNC);
	
	int xpos,ypos,i;
	int i_1=1,i_2=2;
	char input_1[0],input_2[0];
	cleardevice();
	settextstyle(6,0,3);
	setcolor(CYAN);
	outtextxy(50,50,"THE LOGIC GATE WHICH GIVES");
	setcolor(RED);
	outtextxy(250,100," * HIGH OUTPUT IF BOTH INPUTS ARE HIGH,");
	outtextxy(250,150," * LOW OUTPUT IF ANY OF THE INPUT IS LOW");
	setcolor(CYAN);
	outtextxy(50,200,"IS KNOWN AS \" AND-GATE \" . ");
	BUTTON(1000,5,1045,"BACK !");
	
	setcolor(MAGENTA);
	setlinestyle(0,0,6);
	rectangle(50,250,1150,650);
	
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,3);
	line(400,380,500,380);
	line(400,470,500,470);
	line(500,350,500,500);
	arc(495,425,275,85,73);
	line(565,425,700,425);
	setlinestyle(0,0,1);
	rectangle(350,355,399,405);
	rectangle(350,445,399,495);
	rectangle(701,400,750,450);
	settextstyle(2,0,4);
	outtextxy(120,375,"\"CLICK\" AND WRITE  YOUR  1st  INPUT  HERE ====>");
	outtextxy(120,465,"\"CLICK\" AND WRITE  YOUR  2nd  INPUT  HERE ====>");
	
	settextstyle(1,0,1);
	
	while(1){
		click(&xpos,&ypos);
		if(xpos>=1000&&xpos<=1180&&ypos>=5&&ypos<=45)COMPUTER_2();
		
		if(xpos>=350&&xpos<=399&&ypos>=355&&ypos<=405){setcolor(BLACK);for(i=0;i<=40;i++){line(351+i,357,349+i,404);};setcolor(LIGHTCYAN);input_1[0]=getch(); if(input_1[0]-'0'==0){outtextxy(365,373,"0"); i_1=0; } else {outtextxy(363,373,"1"); i_1=1;} rectangle(350,355,399,405);setlinestyle(0,0,3);line(400,380,500,380);delay(100);setlinestyle(0,0,1);}
	 	if(xpos>=350&&xpos<=399&&ypos>=445&&ypos<=495){setcolor(BLACK);for(i=0;i<=40;i++){line(351+i,447,349+i,494);};setcolor(LIGHTCYAN);input_2[0]=getch(); if(input_2[0]-'0'==0){outtextxy(365,463,"0"); i_2=0; } else {outtextxy(365,463,"1"); i_2=1;} rectangle(350,445,399,495);setlinestyle(0,0,3);line(400,470,500,470);delay(100);setlinestyle(0,0,1);}
				 
				 
				if(i_1==1&&i_2==1){setcolor(BLACK);for(i=0;i<=48;i++){line(702+i,400,702+i,450);};setcolor(LIGHTCYAN);rectangle(701,400,750,450);delay(100);outtextxy(718,418,"1");}
				if(i_1==0||i_2==0){setcolor(BLACK);for(i=0;i<=48;i++){line(702+i,400,702+i,450);};setcolor(LIGHTCYAN);rectangle(701,400,750,450);delay(100);outtextxy(718,418,"0");}
	delay(200);
	}
}

/*===========OR.GATE==================*/
void OR_GATE(void){
	PlaySound("C:/THE_HOUSE_OF_SCIENCE/orgate.wav", NULL, SND_ASYNC);
	
	int xpos,ypos,i;
	int i_1=1,i_2=2;
	char input_1[0],input_2[0];
	cleardevice();
	settextstyle(6,0,3);
	setcolor(CYAN);
	outtextxy(50,50,"THE LOGIC GATE WHICH GIVES");
	setcolor(RED);
	outtextxy(250,100," * HIGH OUTPUT IF ANY OF THE INPUTS IS HIGH,");
	outtextxy(250,150," * LOW OUTPUT IF BOTH OF THE INPUTS ARE LOW");
	setcolor(CYAN);
	outtextxy(50,200,"IS KNOWN AS \" OR-GATE \" . ");

	setcolor(MAGENTA);
	setlinestyle(0,0,6);
	rectangle(50,250,1150,650);
	
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,3);
	line(400,380,510,380);
	line(400,470,510,470);
	arc(370,425,330,30,150);
	line(500,350,600,425);
	line(500,500,600,425);
	line(600,425,700,425);

	setlinestyle(0,0,1);
	rectangle(350,355,399,405);
	rectangle(350,445,399,495);
	rectangle(701,400,750,450);
	settextstyle(2,0,4);
	outtextxy(120,375,"\"CLICK\" AND WRITE  YOUR  1st  INPUT  HERE ====>");
	outtextxy(120,465,"\"CLICK\" AND WRITE  YOUR  2nd  INPUT  HERE ====>");

	BUTTON(1000,5,1045,"BACK !");

	settextstyle(1,0,1);
	
	while(1){
		click(&xpos,&ypos);
		
		if(xpos>=1000&&xpos<=1180&&ypos>=5&&ypos<=45)COMPUTER_2();
	
	
		if(xpos>=350&&xpos<=399&&ypos>=355&&ypos<=405){setcolor(BLACK);for(i=0;i<=40;i++){line(351+i,357,349+i,404);};setcolor(LIGHTCYAN);input_1[0]=getch(); if(input_1[0]-'0'==0){outtextxy(365,373,"0"); i_1=0; } else {outtextxy(363,373,"1"); i_1=1;} rectangle(350,355,399,405);setlinestyle(0,0,3);line(400,380,500,380);delay(100);setlinestyle(0,0,1);}
	 	if(xpos>=350&&xpos<=399&&ypos>=445&&ypos<=495){setcolor(BLACK);for(i=0;i<=40;i++){line(351+i,447,349+i,494);};setcolor(LIGHTCYAN);input_2[0]=getch(); if(input_2[0]-'0'==0){outtextxy(365,463,"0"); i_2=0; } else {outtextxy(365,463,"1"); i_2=1;} rectangle(350,445,399,495);setlinestyle(0,0,3);line(400,470,500,470);delay(100);setlinestyle(0,0,1);}
				 		 
		if(i_1==0&&i_2==0&&i_2!=2)  {setcolor(BLACK);for(i=0;i<=48;i++){line(702+i,400,702+i,450);};setcolor(LIGHTCYAN);rectangle(701,400,750,450);delay(100);outtextxy(718,418,"0");}
		if((i_1==1||i_2==1)&&i_2!=2){setcolor(BLACK);for(i=0;i<=48;i++){line(702+i,400,702+i,450);};setcolor(LIGHTCYAN);rectangle(701,400,750,450);delay(100);outtextxy(718,418,"1");}
	
		if(kbhit())getch();
		delay(200);
	}
}

/*===========XOR.GATE================*/
void XOR_GATE(void){
	PlaySound("C:/THE_HOUSE_OF_SCIENCE/xorgate.wav", NULL, SND_ASYNC);
	
	int xpos,ypos,i;
	int i_1=1,i_2=2;
	char input_1[0],input_2[0];
	cleardevice();
	settextstyle(6,0,3);
	setcolor(CYAN);
	outtextxy(50,50,"THE LOGIC GATE WHICH GIVES");
	setcolor(RED);
	outtextxy(250,100," * HIGH OUTPUT IF THE INPUTS ARE DIFFERENT,");
	outtextxy(250,150," * LOW OUTPUT IF THE INPUTS ARE SAME");
	setcolor(CYAN);
	outtextxy(50,200,"IS KNOWN AS \" EXCLUSIVE-OR-GATE \" . ");

	setcolor(MAGENTA);
	setlinestyle(0,0,6);
	rectangle(50,250,1150,650);
	
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,3);
	line(400,380,480,380);
	line(400,470,480,470);
	arc(340,425,330,30,150);
	arc(370,425,330,30,150);
	line(500,350,600,425);
	line(500,500,600,425);
	line(600,425,700,425);

	setlinestyle(0,0,1);
	rectangle(350,355,399,405);
	rectangle(350,445,399,495);
	rectangle(701,400,750,450);
	settextstyle(2,0,4);
	outtextxy(120,375,"\"CLICK\" AND WRITE  YOUR  1st  INPUT  HERE ====>");
	outtextxy(120,465,"\"CLICK\" AND WRITE  YOUR  2nd  INPUT  HERE ====>");

	BUTTON(1000,5,1045,"BACK !");

	settextstyle(1,0,1);
	
	while(1){
		click(&xpos,&ypos);
		
		if(xpos>=1000&&xpos<=1180&&ypos>=5&&ypos<=45)COMPUTER_2();
		
		if(xpos>=350&&xpos<=399&&ypos>=355&&ypos<=405){setcolor(BLACK);for(i=0;i<=40;i++){line(351+i,357,349+i,404);};setcolor(LIGHTCYAN);input_1[0]=getch(); if(input_1[0]-'0'==0){outtextxy(365,373,"0"); i_1=0; } else {outtextxy(363,373,"1"); i_1=1;} rectangle(350,355,399,405);setlinestyle(0,0,3);delay(100);setlinestyle(0,0,1);}
	 	if(xpos>=350&&xpos<=399&&ypos>=445&&ypos<=495){setcolor(BLACK);for(i=0;i<=40;i++){line(351+i,447,349+i,494);};setcolor(LIGHTCYAN);input_2[0]=getch(); if(input_2[0]-'0'==0){outtextxy(365,463,"0"); i_2=0; } else {outtextxy(365,463,"1"); i_2=1;} rectangle(350,445,399,495);setlinestyle(0,0,3);delay(100);setlinestyle(0,0,1);}
				 		 
		if(i_1==1&&i_2==1&&i_2!=2){setcolor(BLACK);for(i=0;i<=48;i++){line(702+i,400,702+i,450);};setcolor(LIGHTCYAN);rectangle(701,400,750,450);delay(100);outtextxy(718,418,"0");}
		if(i_1==0&&i_2==0&&i_2!=2){setcolor(BLACK);for(i=0;i<=48;i++){line(702+i,400,702+i,450);};setcolor(LIGHTCYAN);rectangle(701,400,750,450);delay(100);outtextxy(718,418,"0");}
		if(i_1==0&&i_2==1&&i_2!=2){setcolor(BLACK);for(i=0;i<=48;i++){line(702+i,400,702+i,450);};setcolor(LIGHTCYAN);rectangle(701,400,750,450);delay(100);outtextxy(718,418,"1");}
		if(i_1==1&&i_2==0&&i_2!=2){setcolor(BLACK);for(i=0;i<=48;i++){line(702+i,400,702+i,450);};setcolor(LIGHTCYAN);rectangle(701,400,750,450);delay(100);outtextxy(718,418,"1");}
	
		if(kbhit())getch();
		delay(100);
	}
}

/*=RUTHERFORD.GOLD.FOIL.EXPERIMENT=*/
void RGFE(void){
	int i,j,xpos,ypos;
	char aps[]="a-PARTICLES SOURCE";
	aps[0]=224;
	
	cleardevice();
	
	delay(1000);
	setcolor(LIGHTGREEN);
	settextstyle(6,0,4);
	outtextxy(100,50,"RUTHERFORD'S GOLD FOIL EXPEREMENT");
	outtextxy(90,87,"===================================");
	delay(1000);
	setcolor(LIGHTRED);
	settextstyle(3,0,1);
	outtextxy(130,120,"EXPEREMENT BY WHICH SCIENTISTS DISCOVERED THAT EVERY ATOM CONTAINS A NUCLEUS");
	outtextxy(210,140,"WHERE ITS POSITIVE CHARGE AND MOST OF ITS MASS ARE CONCENTRATED.");
	delay(11000);

	setcolor(CYAN);
	setlinestyle(0,0,4);
	rectangle(50,200,1150,650);

	setcolor(YELLOW);
	setlinestyle(0,0,1);
	setfillstyle(1,YELLOW);
	rectangle(520,250,700,600);
	floodfill(530,260,YELLOW);

	setcolor(LIGHTGRAY);
	rectangle(1070,220,1115,630);
	settextstyle(1,1,1);
	outtextxy(1105,250,"PHOTOGRAPHIC FILM");

	setcolor(YELLOW);
	rectangle(100,220,130,630);
	outtextxy(125,245,aps);
	setfillstyle(SOLID_FILL,YELLOW);
	for(i=1;i<=9;i++){	
		circle(160,250+(i*35),10);
		floodfill(160,250+(i*35),YELLOW);
	}
	delay(4000);
	
	setcolor(BLACK);
	for(i=0;i<=89;i++){
		delay(10);
		line(520+i,250,520+i,601);
		line(700-i,250,700-i,601);
	}
	
	
	for(i=0;i<=174;i++){
		delay(10);
		putpixel(610,250+i,BLACK);
		putpixel(610,600-i,BLACK);
	}	

	putpixel(610,425,BLACK);
	
	for(i=2;i<=150;i++){
		circle(610,425,i);
		delay(30);
		setcolor(BLACK);
		circle(610,425,i-1);
		setcolor(YELLOW);	
	}
	
	setcolor(YELLOW);
	circle(610,425,20);
	outtextxy(620,417,"+");
	
	for(j=1;j<=890;j++){
		for(i=1;i<=9;i++){
			if(i!=4&&i!=5&&i!=6){setcolor(YELLOW);circle(160+j,250+(i*35),10);circle(610,425,150);wait(300);setcolor(BLACK);arc(160+j-2,250+(i*35),90,270,10);}
		}
	}
		
	for(j=1;j<=420;j++){
		for(i=1;i<=9;i++){
			if(i==4||i==6){setcolor(YELLOW);circle(160+j,250+(i*35),10);circle(610,425,150);wait(700);setcolor(BLACK);arc(160+j-2,250+(i*35),90,270,10);}
		}
	}	
	
	for(j=420;j<=600;j++){
		setcolor(YELLOW);circle(160+j,810-j,10);circle(160+j,811-j,10);circle(610,425,150);wait(1000);setcolor(BLACK);arc(160+j-2,810-j,135,315,11);arc(160+j-2,811-j,135,315,11);
		setcolor(YELLOW);circle(160+j,40+j,10); circle(160+j,39+j,10);  circle(610,425,150);wait(1000);setcolor(BLACK);arc(160+j-2,40+j,45,225,11);  arc(160+j-2,39+j,45,225,11);
	}	
	
	for(j=1;j<=400;j++){
		setcolor(YELLOW);circle(160+j,425,10);circle(610,425,150);setcolor(BLACK);wait(2000);arc(160+j-2,425,90,270,10);
	}
	
	for(j=400;j>=0;j--){
		setcolor(YELLOW);circle(160+j,425,10);circle(610,425,150);setcolor(BLACK);wait(2000);arc(160+j+2,425,270,90,10);
	}
	
	BUTTON(1000,0,1045,"BACK !");
	while(1){
		delay(100);
		click(&xpos,&ypos);
		if(xpos>=1000&&xpos<=1180&&ypos>=0&&ypos<=40)CHEMISTRY_2();
	}
}

/*=====ELECTROLUSIS.OF.WATER=====*/
void EOW(void){
	
	int i, xpos, ypos;
	cleardevice();
	
	setcolor(LIGHTGREEN);
	settextstyle(6,0,4);
	outtextxy(250,50,"ELECTROLYSIS OF WATER");
	outtextxy(240,87,"=======================");
	delay(2000);
	
	setcolor(CYAN);
	settextstyle(3,0,1);
	outtextxy(200,120,"THE DECOMPOSITION OF WATER INTO  \"OXYGEN\"  AND  \"HYDROGEN\"  GAS");
	outtextxy(160,140,"BY PASSING ELECTRIC CURRENT THROUGH IT IS KNOWN AS ELECTROLYSIS OF WATER");
	delay(9000);
	
	setlinestyle(0,0,4);
	setcolor(MAGENTA);
	rectangle(50,180,1150,680);
	
	setcolor(WHITE);
	setlinestyle(0,0,1);
	ellipse(600,400,0,0,300,50);
	line(300,400,300,600);
	ellipse(600,600,180,0,300,50);
	line(900,400,900,600);
	
	setcolor(BLUE);
	ellipse(600,450,180,0,299,50);
	line(301,450,301,599);
	ellipse(600,599,180,0,299,50);
	line(899,450,899,600);
	
	setfillstyle(SOLID_FILL,CYAN);
	floodfill(890,550,BLUE);
	
	delay(3000);
	
	setcolor(RED);
	ellipse(450,580,0,0,40,10);
	line(410,580,410,220);
	ellipse(450,222,0,180,41,10);
	line(490,220,490,580);
	ellipse(450,280,180,0,40,10);
	floodfill(450,560,RED);
	
	setcolor(WHITE);
	ellipse(450,580,0,0,40,10);
	line(410,580,410,220);
	ellipse(450,222,0,180,41,10);
	line(490,220,490,580);
	ellipse(600,400,180,0,300,50);
	
	setcolor(RED);
	ellipse(750,580,0,0,40,10);
	line(710,580,710,220);
	ellipse(750,222,0,180,41,10);
	line(790,220,790,580);
	ellipse(750,280,180,0,40,10);
	floodfill(750,560,RED);
	
	setcolor(WHITE);
	ellipse(750,580,0,0,40,10);
	line(710,580,710,220);
	ellipse(750,222,0,180,41,10);
	line(790,220,790,580);
    ellipse(600,400,180,0,300,50);	
	
	
	delay(3000);
	rectangle(445,400,455,500);	
	rectangle(745,400,755,500);
	rectangle(950,540,1100,640);
	outtextxy(973,580,"12 Volts D.C");
	setcolor(RED);
	line(450,500,450,600);
	line(450,600,350,600);
	line(350,600,350,340);
	line(350,340,280,340);
	line(280,340,280,665);
	line(280,665,1130,665);
	line(1130,665,1130,520);
	line(1130,520,1070,520);
	line(1070,520,1070,540);
	
	line(750,500,750,600);
	line(750,600,850,600);
	line(850,600,850,340);
	line(850,340,920,340);
	line(920,340,920,520);
	line(920,520,980,520);
	line(980,520,980,540);
	
	delay(5000);
	
	settextstyle(8,1,1);
	outtextxy(405,240,"HYDROGEN");
	outtextxy(705,240,"OXYGEN");
	
	for(i=0;i<=100;i++){
		
		delay(40);
		setcolor(WHITE);	
    	ellipse(451,280+i,180,0,39,10);
    	ellipse(750,280+i,180,0,39,10);
    	
		setcolor(BLUE);
	
		if(i<=20){circle(440,330-i,3);circle(740,330-i,3);circle(460,330-i,3);circle(760,330-i,3);}
		if(i<=55){circle(440,400-i,3);circle(740,400-i,3);circle(460,400-i,3);circle(760,400-i,3);}
		if(i<=75){circle(440,440-i,3);circle(740,440-i,3);circle(460,440-i,3);circle(760,440-i,3);}
		if(i<=100){circle(440,488-i,3);circle(740,488-i,3);circle(460,488-i,3);circle(760,488-i,3);}
		
		setcolor(BLACK);
    	ellipse(451,279+i,180,0,39,10);	ellipse(451,278+i,180,0,39,10);
    	ellipse(751,279+i,180,0,39,10); ellipse(751,278+i,180,0,39,10);

		setcolor(CYAN);
		if(i<=20){arc(440,330-i,180,0,3);arc(740,330-i,180,0,3);arc(460,330-i,180,0,3);arc(760,330-i,180,0,3);}
		if(i<=55){arc(440,400-i,180,0,3);arc(740,400-i,180,0,3);arc(460,400-i,180,0,3);arc(760,400-i,180,0,3);}
		if(i<=75){arc(440,440-i,180,0,3);arc(740,440-i,180,0,3);arc(460,440-i,180,0,3);arc(760,440-i,180,0,3);}
		if(i<=100){arc(440,488-i,180,0,3);arc(740,488-i,180,0,3);arc(460,488-i,180,0,3);arc(760,488-i,180,0,3);}
			
	}
		
	BUTTON(1000,0,1050,"BACK !");
	while(1){
		click(&xpos,&ypos);
		if(xpos>=1000&xpos<=1180&&ypos>=0&&ypos<=40)CHEMISTRY_2();
		delay(100);
	}
	
}

/*======CHEMICAL.BONDING========*/
void CMB(void){
	int i,xpos,ypos;
	cleardevice();
	
	setcolor(LIGHTGREEN);
	settextstyle(6,0,4);
	outtextxy(257,50,"THE CHEMICAL BONDING");
	outtextxy(250,87,"======================");
	
	setcolor(CYAN);
	settextstyle(3,0,1);
	outtextxy(180,120,"THE FORCE WHICH HOLDS ATOMS TOGETHER IS KNOWN AS CHEMICAL BONDING");
	outtextxy(275,140,"THERE ARE THREE TYPES OF INTRA-MOLECULAR FORCES");
	
	BUTTON(1000,10,1040,"BACK !");
	S_BUTTON( 80,185,330,90,"COVALENT-BOND");
	S_BUTTON(380,185,560,390,"IONIC-BOND");
	S_BUTTON(610,185,1055,620,"CO-ORDINATE COVALENT BOND");
	
	
	while(1){
		click(&xpos,&ypos);
		if(xpos>=1000&&xpos<=1180&&ypos>=10&&ypos<=50)	CHEMISTRY_2();
		if(xpos>=80&&xpos<=330&&ypos>=185&&ypos<=225)	      C_B();
		if(xpos>=380&&xpos<=560&&ypos>=185&&ypos<=225)	      I_B();
		if(xpos>=610&&xpos<=1055&&ypos>=185&&ypos<=225) 	COC_B();
	}
	
	
	getch();
}

/*=========IONIC.BOND============*/
void I_B(void){
	
	PlaySound("C:/THE_HOUSE_OF_SCIENCE/ib.wav", NULL, SND_ASYNC);
	
	int i,xpos,ypos;
	
	setcolor(BLACK);
	for (i=0;i<=1150;i++){
		line(999+i,0,999+i,52);
		line(0+i,140,0+i,720);
	}
	
	setcolor(LIGHTRED);
	settextstyle(4,0,2);
	outtextxy(60,190,"IONIC-BOND");
	outtextxy(58,210,"------------------");
	delay(1000);
	
	settextstyle(8,0,3);
	setcolor(CYAN);
	outtextxy(90,250,"BOND FORMED BY THE COMPLETE TRANSFER OF ELECTRON FROM ONE ATOM TO ANOTHER");
	delay(5000);
	
	setlinestyle(0,0,4);
	setcolor(MAGENTA);
	rectangle(50,240,1150,680);
	
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
	
	circle(300,460,90);
	circle(300,460,30);
	outtextxy(288,449,"Na");
	
	circle(300,370,7);
	for(i=0;i<=250;i++){
		setcolor(LIGHTCYAN);
		circle(300+i,370,7);
		circle(300,460,90);
		if(i==20)outtextxy(250,350,"+");
		setcolor(BLACK);
		delay(1);
		arc(299+i,370,90,270,7);
	}
	
	setcolor(LIGHTCYAN);
	circle(800,460,90);
	circle(800,460,30);
	outtextxy(788,449,"Cl");
	
	delay(200);
	
	for(i=250;i<=500;i++){
		setcolor(LIGHTCYAN);
		circle(300+i,370,7);
		circle(800,460,90);
		setcolor(BLACK);
		delay(1);
		arc(299+i,370,90,270,7);
	}
	
	delay(200);
	
	for(i=0;i<=200;i++){
		line(700+i,300,700+i,600);
	}
	
	setcolor(LIGHTCYAN);
	circle(800,460,90);
	circle(800,460,30);
	outtextxy(788,449,"Cl");
	outtextxy(850,350,"-");
	
	delay(1000);
	
	for(i=1;i<=160;i++){
		setcolor(BLACK);
		circle(801-i,460,90);
		circle(801-i,460,30);
		outtextxy(789-i,449,"Cl");
		outtextxy(851-i,350,"-");
		circle(299+i,460,90);	
		circle(299+i,460,30);
		outtextxy(287+i,449,"Na");
		outtextxy(249+i,350,"+");
		setcolor(LIGHTCYAN);
		circle(800-i,460,90);
		circle(800-i,460,30);
		outtextxy(788-i,449,"Cl");
		outtextxy(850-i,350,"-");
		circle(300+i,460,90);
		circle(300+i,460,30);
		outtextxy(288+i,449,"Na");
		outtextxy(250+i,350,"+");	
		delay(10);
	}
	
	setcolor(BLACK);
	outtextxy(850-i,350,"-");
	outtextxy(250+i,350,"+");	
	
	BUTTON(1000,10,1025,"RETURN !");
	while(1){
		click(&xpos,&ypos);
		if(xpos>=1000&&xpos<=1180&&ypos>=10&&ypos<=50)	CMB();
	}

}

/*=========COVELENT.BOND==========*/
void C_B(void){
	PlaySound("C:/THE_HOUSE_OF_SCIENCE/cb.wav",NULL,SND_ASYNC);
	
	int i,xpos,ypos;
	setcolor(BLACK);
	for (i=0;i<=1150;i++){
		line(999+i,0,999+i,52);
		line(0+i,140,0+i,720);		
	}
	
	setcolor(LIGHTRED);
	settextstyle(4,0,2);
	outtextxy(60,190,"COVALENT-BOND");
	outtextxy(58,210,"--------------------------");
	delay(1500);
	
	setlinestyle(0,0,4);
	setcolor(MAGENTA);
	rectangle(50,240,1150,680);
	
	settextstyle(8,0,3);
	setcolor(CYAN);
	outtextxy(90,250,"BOND FORMED BY THE SHARING OF ELECTRONS BETWEEN ONE ATOM AND ANOTHER");
	outtextxy(90,275,"IT HAS THREE TYPES");

	delay(8000);	
	
	setcolor(BLUE);
	outtextxy(420,300,"SINGLE COVALENT BOND");
	outtextxy(320,600,"BOND FORMED BY ONLY ONE ELECTRON SHARING");
	
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
	circle(380,460,90);
	circle(380,460,30);
	circle(470,460,7);
	outtextxy(372+i,450,"H");
	
	circle(780,460,90);
	circle(780,460,30);
	circle(690,460,7);
	outtextxy(772,450,"H");
	
	delay(100);
	for(i=0;i<=130;i++){
		setcolor(BLACK);
		circle(379+i,460,90);
		circle(379+i,460,30);
		circle(469+i,460,7);
		outtextxy(372+i,450,"H");
		circle(781-i,460,90);
		circle(781-i,460,30);
		circle(691-i,460,7);
		outtextxy(772-i,450,"H");

		setcolor(LIGHTCYAN);
		circle(380+i,460,90);
		circle(380+i,460,30);
		circle(470+i,460,7);
		outtextxy(372+i,450,"H");
		circle(780-i,460,90);
		circle(780-i,460,30);
		circle(690-i,460,7);
		outtextxy(772-i,450,"H");
		delay(10);
	}
	
	delay(2200);
	
	setcolor(BLACK);
	for(i=0;i<=1000;i++)line(60+i,300,60+i,675);

	setcolor(BLUE);
	outtextxy(420,300,"DOUBLE COVALENT BOND");
	outtextxy(320,600,"BOND FORMED BY TWO ELECTRON SHARING");
	
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
	circle(380,460,90);
	circle(380,460,30);
	circle(467,445,7);
	circle(467,475,7);
	outtextxy(372,450,"O");
	
	circle(780,460,90);
	circle(780,460,30);
	circle(691,445,7);
	circle(691,475,7);
	outtextxy(772,450,"O");	

	delay(100);
	for(i=0;i<=130;i++){
		setcolor(BLACK);
		circle(379+i,460,90);
		circle(379+i,460,30);
		circle(466+i,445,7);
		circle(466+i,475,7);
		outtextxy(372+i,450,"O");
		
		circle(781-i,460,90);
		circle(781-i,460,30);
		circle(692-i,445,7);
		circle(692-i,475,7);
		outtextxy(772-i,450,"O");
		
		setcolor(LIGHTCYAN);
		
		circle(380+i,460,90);
		circle(380+i,460,30);
		circle(467+i,445,7);
		circle(467+i,475,7);
		outtextxy(372+i,450,"O");
		
		circle(780-i,460,90);
		circle(780-i,460,30);
		circle(691-i,445,7);
		circle(691-i,475,7);
		outtextxy(772-i,450,"O");
		delay(10);
	}
	
	delay(2200);
	
	setcolor(BLACK);
	for(i=0;i<=1000;i++)line(60+i,300,60+i,675);
	
	setcolor(BLUE);
	outtextxy(420,300,"TRIPLE COVALENT BOND");
	outtextxy(320,600,"BOND FORMED BY THREE ELECTRON SHARING");
	
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
	circle(380,460,90);
	circle(380,460,30);
	outtextxy(372,450,"N");
	circle(465,440,7);
	circle(470,460,7);
	circle(465,480,7);
	
	circle(780,460,90);
	circle(780,460,30);
	circle(695,440,7);
	circle(690,460,7);
	circle(695,480,7);
	outtextxy(772,450,"N");
	
	delay(100);
	for(i=0;i<=130;i++){
		setcolor(BLACK);
		circle(379+i,460,90);
		circle(379+i,460,30);
		circle(464+i,440,7);
		circle(469+i,460,7);
		circle(464+i,480,7);
		outtextxy(372+i,450,"N");
		
		circle(781-i,460,90);
		circle(781-i,460,30);
		circle(696-i,440,7);
		circle(691-i,460,7);
		circle(696-i,480,7);
		outtextxy(772-i,450,"N");
		
		setcolor(LIGHTCYAN);
		circle(380+i,460,90);
		circle(380+i,460,30);
		circle(465+i,440,7);
		circle(470+i,460,7);
		circle(465+i,480,7);
		outtextxy(372+i,450,"N");
		
		circle(780-i,460,90);
		circle(780-i,460,30);
		circle(695-i,440,7);
		circle(690-i,460,7);
		circle(695-i,480,7);
		outtextxy(772-i,450,"N");
			
		delay(10);
	}
	
	BUTTON(1000,10,1025,"RETURN !");
	while(1){
		click(&xpos,&ypos);
		if(xpos>=1000&&xpos<=1180&&ypos>=10&&ypos<=50)	CMB();
		delay(100);
	}

}

/*===C0.ORDINATE.COVELENT.BOND===*/
void COC_B(void){
	
	PlaySound("C:/THE_HOUSE_OF_SCIENCE/cocb.wav", NULL, SND_ASYNC);

	int i,xpos,ypos;
	
	setcolor(BLACK);
	for (i=0;i<=1150;i++){
		line(999+i,0,999+i,52);
		line(0+i,140,0+i,720);
	}
	
	setcolor(LIGHTRED);
	settextstyle(4,0,2);
	outtextxy(60,190,"CO-ORDINATE COVALENT-BOND");
	outtextxy(58,210,"----------------------------------------------");
	delay(1000);
	
	settextstyle(8,0,3);
	setcolor(CYAN);
	outtextxy(90,250,"SPECIAL TYPE OF BOND IN WHICH ONLY ONE ATOM PROVIDE ELECTRON FOR SHARING");
	outtextxy(90,270,"ELECTRON DOES'NT TRANSFER BETWEEN THE ATOMS");
	delay(8500);
	
	setlinestyle(0,0,4);
	setcolor(MAGENTA);
	rectangle(50,240,1150,680);
	
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
	
	circle(300,460,90);
	circle(300,460,30);
	outtextxy(292,449,"H");
	
	circle(300,370,7);
	for(i=0;i<=150;i++){	
		setcolor(BLACK);
		delay(1);
		arc(301-i,370,270,90,8);
		setcolor(LIGHTCYAN);
		circle(300-i,370,7);
		circle(300,460,90);
		if(i==20)outtextxy(330,350,"+");
	}
	
	setcolor(BLACK);
	for(i=0;i<=25;i++)line(140+i,360,145+i,380);
	
	setcolor(LIGHTCYAN);
	circle(780,460,90);
	circle(780,460,30);
	circle(691,445,7);
	circle(691,475,7);
	outtextxy(772,450,"N");
	delay(2000);
		
	for(i=0;i<=320;i++){
		setcolor(BLACK);
		circle(299+i,460,90);
		circle(299+i,460,30);
		outtextxy(291+i,449,"H");
		outtextxy(329+i,350,"+");
	
		setcolor(LIGHTCYAN);
		outtextxy(292+i,449,"H");
		outtextxy(330+i,350,"+");
		circle(780,460,90);
		circle(780,460,30);
		circle(691,445,7);
		circle(691,475,7);
		circle(300+i,460,90);
		circle(300+i,460,30);
	
		delay(10);
	}
	
	line(500,350,540,350);
	line(500,350,500,580);
	line(500,580,540,580);
	line(850,580,890,580);
	line(890,580,890,350);
	line(890,350,850,350);
	
	setcolor(BLACK);
	outtextxy(650,350,"+");
	setcolor(LIGHTCYAN);
	circle(620,460,90);
	
	outtextxy(900,340,"+");
	
	BUTTON(1000,10,1025,"RETURN !");
	while(1){
		click(&xpos,&ypos);
		if(xpos>=1000&&xpos<=1180&&ypos>=10&&ypos<=50)	CMB();
		delay(100);
	}
}

/*=====CATHODE.RAY.EXPERIMENT=====*/
void CR_E(void){
	
	int i, j, xpos, ypos;
	
	cleardevice();
	setcolor(LIGHTGREEN);
	settextstyle(6,0,4);
	outtextxy(250,50,"CATHODE RAY EXPERIMENT");
	outtextxy(240,87,"=========================");
	
	delay(2000);	
	setcolor(CYAN);
	settextstyle(3,0,1);
	outtextxy(110,120,"EXPERIMENT PERFORMED BY THE PASSAGE OF ELECTRIC CURRENT THROUGH GASES AT LOW PRESSURE ");
	outtextxy(160,140,"THIS EXPERIMENT IS ALSO KNOWN AS EXPERIMENT FOR THE \"DISCOVERY OF ELECTRONS\" ");
	delay(10000);
	
	setlinestyle(0,0,4);
	setcolor(MAGENTA);
	rectangle(50,180,1150,680);
	
	setcolor(RED);
	outtextxy(70,205,"---------------------------");
	outtextxy(70,190,"CONSTRUCTION :");
	setcolor(LIGHTRED);
	outtextxy(220,230,"A EVACUATED GLASS TUBE FITTED WITH ELECTRODES AND HIGH POTENTIAL BATTERY");
	
	setlinestyle(0,0,1);
	setcolor(LIGHTCYAN);
	
	ellipse(600,400,0,0,250,60);
	delay(1000);
	setcolor(BROWN);
	setlinestyle(0,0,2);
	rectangle(400,380,410,420);
	outtextxy(388,370,"-");
	rectangle(800,380,790,420);
	outtextxy(809,373,"+");

	line(400,400,300,400);
	line(250,400,300,550);
	line(300,550,750,550);
	line(750,550,750,570);
	
	line(800,400,900,400);
	line(900,400,900,550);
	line(900,550,850,550);
	line(850,550,850,570);
	
	setcolor(DARKGRAY);
	setlinestyle(0,0,3);
	rectangle(700,570,900,670);
	setlinestyle(0,0,2);
	setcolor(LIGHTCYAN);
	outtextxy(760,610,"10,000 Volts");
	delay(6000);
	
	delay(200);
	setcolor(BLACK);
	for(i=0;i<=1000;i++)line(69+i,185,69+i,300);
	delay(100);
	setcolor(RED);
	outtextxy(70,205,"-------------------");
	outtextxy(70,190,"WORKING :");
	setcolor(LIGHTRED);
	outtextxy(220,230,"ON APPLYING ELECTRIC CURRENT A GLOW FROM CATHODE TO ANODE OCCURS");	
	
	for(i=0;i<=50;i++){
		setcolor(BLACK);
		delay(20);
		line(249+i,400,300,550);
		setcolor(BROWN);
		line(250+i,400,300,550);
	}

	for(i=0;i<=378;i++){
		for(j=0;j<=40;j=j+2){
			wait(120);
			putpixel(411+i,380+j,BLUE);	
		}
	}	
	
	BUTTON(1000,0,1050,"BACK !");
	while(1){
		click(&xpos,&ypos);
		if(xpos>=1000&xpos<=1180&&ypos>=0&&ypos<=40)CHEMISTRY_2();
		delay(100);
	}

}

/*clearinputprojectile*/	
void cip(void){
	int i;
	setcolor(BLACK);
	for(i=1;i<=49;i++)line(770+i,166,770+i,194);
	setcolor(CYAN);
	rectangle(770,165,820,195);
}

/*=====PROJECTILE.MOTION=====*/
void P_M(void){
	
	int xpos,ypos, i, d=0,e=0, angl=45;
	float a,b,c, x=0, y, v=100, angle;
	int w=pow(v,2);
	char agl[]={"45"}, oput[10];
	char o,s='4';
	
	cleardevice();
	
	setcolor(LIGHTGREEN);
	settextstyle(6,0,4);
	outtextxy(340,50,"PROJECTILE MOTION");
	outtextxy(335,87,"==================");
	
	setcolor(CYAN);
	settextstyle(3,0,1);
	outtextxy(100,120,"THE TWO DIMENTIONAL MOTION OF A BODY DEPENDING UPON THE VELOCITY AND ANGLE OF PROJECTION");
	outtextxy(110,140,"LET US CONSIDER THE INITIAL VELOCITY BE 100 AND THE ACCELERATION DUT TO GRAVITY BE 9.8 m/s ");
	
	setcolor(LIGHTRED);
	outtextxy(350,170,"WRITE YOUR ANGLE OF PROJECTION HERE");
	setcolor(CYAN);
	rectangle(770,165,820,195);
	settextstyle(2,0,5);
	outtextxy(830,175,"<==== ANGLE MUST BE LESS THEN 90 DEGREES");
	
	
	setlinestyle(0,0,4);
	setcolor(MAGENTA);
	rectangle(50,220,1150,650);															//graph window
	setcolor(CYAN);
	line(55,645,55,225);
	line(55,645,1145,645);								
	setlinestyle(0,0,1);
	for(x=0;x<=410;x=x+10)line(55,225+x,60,225+x);
	for(x=0;x<=1090;x=x+10)line(55+x,645,55+x,640);						

	setcolor(CYAN);	
	setlinestyle(0,0,1);
	
	BUTTON(950,250,960,"GIVE GRAPH");
	while(1){
		
	click(&xpos,&ypos);
		if(xpos>=770&&xpos<=820&&ypos>=165&&ypos<=195){
			agl[0]=getch();angl=agl[0]-48; if(angl>=0&&angl<=9){agl[1]='\0';setcolor(CYAN);outtextxy(777,170,agl);} if(angl<0||angl>9){ angl=4; agl[0]=s ; agl[1]='\0'; outtextxy(777,170,agl); }
			while(1){		 
					delay(10);
					if(kbhit()){	agl[1]=getch();  if(agl[1]-48>=0&&agl[1]-48<=9) {angl=(angl*10)+(agl[1]-48);cip();outtextxy(777,170,agl);}	if(agl[1]-48<0||agl[1]-48>9){ angl=45,cip();outtextxy(777,170,"45"); }			}
					if(ismouseclick(WM_LBUTTONDOWN))break;
				}
			}
		if(kbhit())getch();
		if(xpos>=950&&xpos<=1130&&ypos>=250&&ypos<=290)break;
	}
	
	PlaySound(NULL,0,0);
	
	angle=angl*0.01745;
	b=(9.8)/(2*w*cos(angle)*cos(angle));
	
	for(x=0;x<=1200;x++){
			a=x*tan(angle);
			c=b*x*x;
			y=(a-c);
		if((640-y<=643)&&(640-y>=220))	{setcolor(RED);putpixel(58+x,640-y,RED);setcolor(LIGHTRED);putpixel(58+x,639-y,RED);wait(300);d=x+0; }
		}
	
	for(i=0;i<=9;i++){
		e=d%10;
		o=e+'0';
		d=d/10;
		oput[i]=o;
		if(d==0)break;
	}
	oput[i+1]='\0';
	strrev(oput);
	
	setcolor(CYAN);
	outtextxy(900,400,"V.S =");
	setcolor(RED);
	outtextxy(970,400,oput);
	setcolor(CYAN);
	outtextxy(1030,400,"METERS");
		
	setcolor(BLACK);
	for(x=0;x<=190;x++)line(945+x,245,945+x,295);
	
	BUTTON(950,250,990,"REUSE !");
	BUTTON(950,300,990,"BACK !");
	
	while(1){
		click(&xpos,&ypos);
		if(xpos>=950&&xpos<=1130&&ypos>=250&&ypos<=290)P_M();
		if(xpos>=950&&xpos<=1130&&ypos>=300&&ypos<=340)PHYSICS_2();
	}
}

/*=====SPHERICAL.LENSES======*/
void SP_L(void){
	
	int i,xpos,ypos;
	cleardevice();
	
	setcolor(LIGHTGREEN);
	settextstyle(6,0,4);
	outtextxy(340,50,"SPHERICAL LENSES");
	outtextxy(335,87,"================");
	
	setcolor(CYAN);
	settextstyle(3,0,1);
	outtextxy(100,120,"LENSES WHICH HAVE DIFFERENT THICKNESS AT ENDS AND IN MID IS KNOWN AS SPHERICAL LENSES");
	setcolor(LIGHTRED);
	outtextxy(350,160,"THEY ARE DIVIDED INTO TWO SUB GROUPS : ");
	
	S_BUTTON(340,200,550,350,"CONVEX LENS");
	S_BUTTON(570,200,795,580,"CONCAVE LENS");
	BUTTON(1000,10,1050,"BACK !");
	
	while(1){
		click(&xpos,&ypos);
		if(xpos>=340&&xpos<=550&&ypos>=200&&ypos<=240)CX_L();
		if(xpos>=570&&xpos<=795&&ypos>=200&&ypos<=240)CV_L();
		if(xpos>=1000&&xpos<=1180&&ypos>=10&&ypos<=50)PHYSICS_2();
	}	
}

/*========CONVEX.LENS========*/
void CX_L(void){

	PlaySound("C:/THE_HOUSE_OF_SCIENCE/cxl.wav", NULL, SND_ASYNC);

	int i, j, k, xpos, ypos;
	setcolor(BLACK);
	
	for(i=0;i<=1200;i++)line(0+i,150,0+i,720);
	for(i=0;i<=200;i++)line(999+i,0,999+i,55);

	setcolor(LIGHTRED);
	settextstyle(3,0,2);
	outtextxy(95,175,"-----------------------");
	outtextxy(100,160,"CONVEX LENS");

	setlinestyle(0,0,4);
	setcolor(MAGENTA);
	rectangle(50,200,1150,650);

	setcolor(CYAN);
	settextstyle(8,0,3);
	outtextxy(110,220,"THE LENS WHICH IS THICKER IN MID AND SHARPER ON EDGES IS CONVEX LENS");
	outtextxy(220,243,"IT HAS THE ABILITY TO CONVERGE A PARALLEL BEAM OF LIGHT");
	
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
	arc(682,450,135,225,200);
	arc(400,450,315,45,200);

	delay(100);
		
	for(i=0;i<=140;i++){
		delay(10);
		for(j=0;j<=280;j=j+46)putpixel(400+i,310+j,YELLOW);
		}
				
	for(i=0;i<=137;i++){
		delay(20);
		putpixel(540+i,310+i,YELLOW);
		putpixel(540+i,356+(i/1.5),YELLOW);
		putpixel(540+i,402+(i/3),YELLOW);
		putpixel(540+i,448,YELLOW);	
		putpixel(540+i,494-(i/3),YELLOW);
		putpixel(540+i,540-(i/1.5),YELLOW);
		putpixel(540+i,586-i,YELLOW);
	}

	BUTTON(1000,10,1050,"BACK !");
	while(1){
		click(&xpos,&ypos);
		if(xpos>=1000&&xpos<=1180&&ypos>=10&&ypos<=50)SP_L();
	}	
	
}

/*=========CONCAVE.LENS=======*/
void CV_L(void){

	PlaySound("C:/THE_HOUSE_OF_SCIENCE/cvl.wav", NULL, SND_ASYNC);

	int i, j, k, xpos, ypos;
	setcolor(BLACK);
	
	for(i=0;i<=1200;i++)line(0+i,150,0+i,720);
	for(i=0;i<=200;i++)line(999+i,0,999+i,55);

	setcolor(LIGHTRED);
	settextstyle(3,0,2);
	outtextxy(95,175,"-----------------------");
	outtextxy(100,160,"CONCAVE LENS");

	setlinestyle(0,0,4);
	setcolor(MAGENTA);
	rectangle(50,200,1150,650);

	setcolor(CYAN);
	settextstyle(8,0,3);
	outtextxy(110,220,"THE LENS WHICH IS THICKER AT ENDS AND THINNER IN MID IS CONCAVE LENS");
	outtextxy(220,243,"IT HAS THE ABILITY TO DIVERGE A PARALLEL BEAM OF LIGHT");
	
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
	arc(770,450,135,225,200);
	arc(320,450,315,45,200);
	line(461,309,629,309);
	line(461,589,629,589);
		
	for(i=0;i<=227;i++){
		delay(10);
	
					putpixel(400+i,312,YELLOW);
		if(i<=192)	putpixel(400+i,356,YELLOW);
		if(i<=175)	putpixel(400+i,402,YELLOW);
		if(i<=168)	putpixel(400+i,448,YELLOW);	
		if(i<=175)	putpixel(400+i,494,YELLOW);
		if(i<=192)	putpixel(400+i,540,YELLOW);
					putpixel(400+i,586,YELLOW);
}
				
	for(i=35;i<=135;i++){
		delay(10);
	
		if(i>=88)	putpixel(540+i,310-i+88,YELLOW);
		if(i>=50)	putpixel(540+i,356-(i/2)+25,YELLOW);
		if(i>=35)	putpixel(540+i,402-(i/3)+12,YELLOW);
					putpixel(540+i,448,YELLOW);	
		if(i>=35)	putpixel(540+i,494+(i/3)-12,YELLOW);
		if(i>=50)	putpixel(540+i,540+(i/2)-25,YELLOW);
		if(i>=88)	putpixel(540+i,586+i-88,YELLOW);
	}
	
	BUTTON(1000,10,1050,"BACK !");
	while(1){
		click(&xpos,&ypos);
		if(xpos>=1000&&xpos<=1180&&ypos>=10&&ypos<=50)SP_L();
	}	

}

/*==CONSERVATION.OF.MOMENTUM==*/
void COM(void){
	PlaySound("C:/THE_HOUSE_OF_SCIENCE/com.wav", NULL, SND_ASYNC);
	
	int i, j, xpos, ypos;
	
	cleardevice();
	setcolor(LIGHTGREEN);
	settextstyle(6,0,4);
	outtextxy(170,50,"CONSERVATION OF MOMENTUM");
	outtextxy(165,87,"============================");
	delay(1500);
	setcolor(CYAN);
	settextstyle(3,0,1);
	outtextxy(120,120,"THE FACT THAT MOMENTUM REMAINS CONSTANT BEFORE AND AFTER AN ELASTIC COLLISION");
	outtextxy(350,145,"IS CALLED CONSERVATION OF MOMENTUM");
	delay(6000);
	
	BUTTON(1000,10,1050,"BACK !");
	
	
	MC_D();
	while(1){
		click(&xpos,&ypos);
			if(xpos>=1000&&xpos<=1180&&ypos>=10&&ypos<=50)PHYSICS_2();
			else MC_D();
	}
	
}

/*=MOMENTUM.CONSERVATION.DIAGRAM=*/
void MC_D(void){
	int i,j;
	
	while(!ismouseclick(WM_LBUTTONDOWN)){

	j=0;
	setcolor(BLACK);
	setlinestyle(0,0,1);
	for(i=0;i<=1100;i++)line(50+i,175,50+i,650);
	
	setlinestyle(0,0,4);
	setcolor(MAGENTA);
	rectangle(50,175,1150,650);
	
	setcolor(LIGHTRED);
	settextstyle(8,0,1);
	outtextxy(60,190,"1. A BODY COLIDE WITH OTHER BODY");outtextxy(60,210,"   HAVING SAME MASS AND IN MOTION");
	outtextxy(600,190,"2. A BODY COLIDE WITH OTHER BODY");outtextxy(600,210,"   AT REST HAVING SAME MASS");
	outtextxy(60,400,"3. A LIGHT BODY COLLIDE WITH A");outtextxy(60,420,"   HEAVE BODY AT REST");
	outtextxy(600,400,"4. A HEAVY BODY COLLIDE WITH A");outtextxy(600,420,"   LIGHT BODY AT REST");
	
	setlinestyle(0,0,1);
	
	for(i=0;i<=220;i++){
		
		delay(20);
		
	/*=======================.1.=========================*/	
		if(i<=110){										//
		setcolor(LIGHTCYAN);							//
		rectangle(60+i,300,120+i,340);					//
		setcolor(BLACK);								//
		line(59+i,299,59+i,341);						//
		line(119+i,301,119+i,340);						//
														
		setcolor(CYAN);									//
		rectangle(220+(i/10),300,280+(i/10),340);		//
		setcolor(BLACK);								//
		line(219+(i/10),299,219+(i/10),341);			//
		line(279+(i/10),301,279+(i/10),340);}			//
		
		if(i>=110){										//
		j++;											//
		setcolor(LIGHTCYAN);							//
		rectangle(170+j/10,300,230+j/10,340);			//
		setcolor(BLACK);								//
		line(169+j/10,299,169+j/10,341);				//
		line(229+j/10,301,229+j/10,340);}				//
				
		if(i>=110&&i<=200){								//
		setcolor(CYAN);									//
		rectangle(120+i,300,180+i,340);					//
		setcolor(BLACK);								//
		line(119+i,299,119+i,341);						//
		line(179+i,301,179+i,340);}						//
	/*==================================================*/	
	
	/*=======================.2.========================*/
	if(i<109){											//
		setcolor(LIGHTCYAN);							//
		rectangle(600+i,300,660+i,340);					//
		setcolor(CYAN);									//
		rectangle(770,300,830,340);						//
		setcolor(BLACK);								//
		line(599+i,299,599+i,341);						//
		line(659+i,301,659+i,340);}						//								
						
	if(i>=110){											//
		setcolor(CYAN);									//
		rectangle(660+i,300,720+i,340);					//
		setcolor(BLACK);								//
		line(659+i,299,659+i,341);						//
		line(719+i,301,719+i,340);}						//
	/*==================================================*/
	
	/*===================.3.============================*/
	setcolor(CYAN);										//	
	rectangle(230,480,330,550);							//
	
	if(i<110){											//
		setcolor(LIGHTCYAN);							//
		rectangle(60+i,510,120+i,550);					//
		setcolor(BLACK);								//
		line(59+i,509,59+i,551);						//
		line(119+i,511,119+i,550);}	
	
	if(i>=110){											//
		setcolor(LIGHTCYAN);							//
		rectangle(280-i,510,340-i,550);					//
		setcolor(BLACK);								//
		line(281-i,511,281-i,550);						//
		line(341-i,509,341-i,551);}						//	
	/*==================================================*/
	
	/*===================.4.============================*/
		setcolor(LIGHTCYAN);							//
		rectangle(600+i,480,700+i,550);					//
		setcolor(BLACK);								//
		line(599+i,479,599+i,551);						//
		line(699+i,481,699+i,550);						//
		
		if(i<110){										//
				setcolor(CYAN);							//
				rectangle(810,510,870,550);}			//
							
		if(i==110||i==111){								//
			setcolor(BLACK);							//
			rectangle(810,510,870,550);}				//
			
		if(i>=110){										//
			setcolor(CYAN);								//
			rectangle(590+(i*2),510,650+(i*2),550);		//
			setcolor(BLACK);							//
			line(588+(i*2),510,588+(i*2),560);			//
			line(589+(i*2),510,589+(i*2),560);			//
			line(648+(i*2),509,648+(i*2),550);			//
			line(649+(i*2),511,649+(i*2),550);}			//
								
	if(ismouseclick(WM_LBUTTONDOWN))break;				//	
	/*==================================================*/	
		}												

	}

}

/*=====DOPPLERS.EFFECT=====*/
void DP_E(void){
	int i, j, xpos, ypos;
	cleardevice();
	PlaySound("C:/THE_HOUSE_OF_SCIENCE/dpe1.wav", NULL, SND_ASYNC);
	
	setcolor(LIGHTGREEN);
	settextstyle(6,0,4);
	outtextxy(370,50,"DOPPLER'S EFFECT");
	outtextxy(365,87,"================");
	
	setcolor(CYAN);
	settextstyle(3,0,1);
	outtextxy(120,120,"THE APPARENT CHANGE IN THE FREQUENCY OF SOUND WHEN IT's SOURCE IS IN RELATIVE MOTION");
	outtextxy(300,145,"WITH RESPECT TO THE LISTNER IS CALLED DOPPLER'S EFFECT");
	
	setlinestyle(0,0,4);
	setcolor(GREEN);
	line(0,170,1200,170);
	line(0,370,1200,370);
	line(0,480,1200,480);
	setfillstyle(INTERLEAVE_FILL,GREEN);
	floodfill(10,180,GREEN);
	floodfill(10,700,GREEN);
		
	
	for(i=0;i<=1200;i=i+40){
		setcolor(WHITE);
			line(0+i,370,20+i,370);	
			line(0+i,480,20+i,480);
		setcolor(YELLOW);
			line(20+i,370,40+i,370);	
			line(20+i,480,40+i,480);
	}
	
	setlinestyle(0,0,1);
	
	setcolor(LIGHTCYAN);
	circle(600,500,10);
	setfillstyle(INTERLEAVE_FILL,LIGHTCYAN);
	floodfill(600,500,LIGHTCYAN);
	line(600,505,600,525);
	line(600,510,590,520);
	line(600,510,610,520);
	line(600,525,590,540);
	line(600,525,610,540);
	
	delay(10020);
	PlaySound("C:/THE_HOUSE_OF_SCIENCE/dpe2.wav", NULL, SND_ASYNC);
	
	for(i=-200;i<=1300;i++){
	setcolor(YELLOW);
	rectangle(170+i,400,140+i,450);
	setcolor(BLUE);	
	rectangle(140+i,400,60+i,450);
	wait(500);
	setcolor(BLACK);
	line(59+i,395,59+i,455);	}

	for(i=-200;i<=1300;i++){
	setcolor(RED);
	rectangle(160+i,402,130+i,438);
	outtextxy(90+i,410,"+");
	setcolor(LIGHTCYAN);	
	rectangle(130+i,400,60+i,440);
	wait(800);
	setcolor(BLACK);
	line(59+i,395,59+i,445);
	setcolor(LIGHTCYAN);
	outtextxy(90+i,410,"+");	}
	
	delay(410);
	
	for(i=-200;i<=1300;i++){
	setcolor(CYAN);
	rectangle(130+i,400,50+i,440);
	setcolor(RED);
	rectangle(100+i,410,60+i,430);
	line(100+i,410,130+i,400);
	line(100+i,430,130+i,440);
	setcolor(BLACK);
	line(100+i,410,60+i,410);
	line(100+i,430,60+i,430);
	wait(400);
	setcolor(BLACK);
	line(49+i,395,49+i,445);	}

	BUTTON(1000,10,1050,"BACK !");
	while(1){
		click(&xpos , &ypos);
		if(xpos>=1000&&xpos<=1180&&ypos>=10&&ypos<=50)PHYSICS_2();
		delay(100);
	}


getch();
}

