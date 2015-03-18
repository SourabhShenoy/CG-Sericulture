/***********************************************************
Sericulture Project using OpenGL

Team Members:
Sourabh S Shenoy (4NM12CS161)
Sowjanya Nayak H (4NM12CS162)

************************************************************/



#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED

/******************************************************Header Files*************************************************************************/
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<sys/time.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <string.h>
#include<stdio.h>
#include<math.h>


/******************************************************Function Declarations*************************************************************************/
void mouse1(int,int,int,int);
void mouse2(int,int,int,int);
void mouse3(int,int,int,int);
void mouse4(int,int,int,int);
void mouse5(int,int,int,int);
void mouse6(int,int,int,int);
void screen1();
void screen2();
void screen3();
void screen4();
void screen5();
void screen6();
void skyland();
void cloud(int,int);
void sun(double,double);
void tree(int,int);
void delay(int);
void clouds();
void swegghatch();
void cateating(int,int);
void caterpillarout(int,int);

/******************************************************Variable Declarations*************************************************************************/
float yax=0,xax=0,but2x=0,but2y=0,catx=0,caty=-0.16; //Translate for but1, but2, caterpillar
int i=0,xdir=0,ydir=0,but1angle=290,but2angle=290,eggang=2,windx=0,windy=0,countegg=0;
bool flag1,flag2,flag3=true,flag3update=true,flag4update=true,flag4=false,flagcrack=false,swhatch=false,catout=false,catmove=false,catanglincr=true,cateat1=false,cateat2=false;
double cloudx[20],eggtrans=0,crackvisib=0,catcounter=0,catangle=0,leafhole1=0,leafhole2=0;
//Caterpillar hatching visibility
double cathead=0,cat1=0,cat2=0,cat3=0,cat4=0,cat5=0,cat6=0,cat7=0,cat8=0;
#endif // HEADERS_H_INCLUDED
