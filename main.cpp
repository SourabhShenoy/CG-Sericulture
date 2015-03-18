#include "headers.h"
/******************************************************User Defined Functions for shapes*************************************************************************/
//To print strings
void printstring( int x, int y, char *st)
{
    int l,i=0;
    l=strlen( st );
    glRasterPos2i( x, y);
    for( i=0; i < l; i++)
    {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);
    }
}

void circle(float xc,float yc,float radius,int angle1=0,int angle2=360,double xmul=1,double ymul=1,int circarc=0)
{
    if(circarc==0)
	{
	    glBegin(GL_POLYGON);
	}
	else
    {
        glBegin(GL_LINE_STRIP);
    }
	for(int a=angle1;a<=angle2;a=a+5)
	{
		float angle_radians=a*(22/7)/(float)180;
		float x=xc+radius*(float)cos(angle_radians)*xmul;
		float y=yc+radius*(float)sin(angle_radians)*ymul;
        glVertex2f(x,y);
	}
	glEnd();
}

void line(int x1,int y1,int x2,int y2)
{
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}

/******************************************************Timed Update Functions*************************************************************************/

void update3(int value)
{
    srand ( time(NULL) );

    if(xax>=0.55)
    {
        xdir=1;
        but1angle=70;
    }
    if(xax<=-0.55)
    {
         xdir=0;
         but1angle=290;
    }

    if(yax>=0.55)
        ydir=1;
    if(yax<=-0.55)
        ydir=0;

    if(xdir==0)
        xax+=double(rand()) / double(RAND_MAX)*0.05;
    else
        xax-=double(rand()) / double(RAND_MAX)*0.05;

    if(ydir==0)
        yax+=double(rand()) / double(RAND_MAX)*0.04;
    else
        yax-=double(rand()) / double(RAND_MAX)*0.04;

    for(i=0;i<20;i++)
        cloudx[i]+=double(rand()) / double(RAND_MAX)*0.0009;



    if(but2x<=1.25)
    {
        but2x+=0.05;
        but2y+=0.001;
    }
    else
    {
        flag3=false;
    }

    if(flag3==false)
    {
        eggtrans+=0.02;
        if(eggtrans>=0.98)
        {
            flag4=true;
        }
    }

    if(flag4)
    {
            but2x+=0.05;
            but2y+=0.02;
    }

    glutPostRedisplay();
    glutTimerFunc(150,update3,0);
}


void update4(int value)
{
    if(countegg<5)
    {
        eggang=-eggang;
        countegg++;
    }
    else
    {
        eggang=0;
        flagcrack=true;
    }

    if(flagcrack)
    {
        crackvisib+=0.08;
        if(crackvisib>=0.65)
        {
            swhatch=true;
        }
        if(crackvisib>=0.95)
        {
            catout=true;
            catmove=true;
        }
    }

    if(catout)
    {
        catcounter+=0.16;
    }

    if(catcounter>=0.5)
    {
        cathead=1;
    }
    if(catcounter>=0.9)
    {
        cat1=1;
    }
    if(catcounter>=1.18)
    {
        cat2=1;
    }
    if(catcounter>=1.5)
    {
        cat3=1;
    }
    if(catcounter>=1.9)
    {
        cat4=1;
    }
    if(catcounter>=2.25)
    {
        cat5=1;
    }
    if(catcounter>=2.6)
    {
        cat6=1;
    }
    if(catcounter>=3.25)
    {
        cat7=1;
    }
    if(catcounter>=3.6)
    {
        cat8=1;
    }

    if(catcounter>=4.2)
    {
        if(catanglincr)
        {
            catangle+=4;
        }
        if(catangle>=25)
        {
            catmove=false;
            catanglincr=false;
            cateat1=true;
        }
    }

    if(cateat1)
    {
        leafhole1+=0.15;
        if(leafhole1>=1.5)
        {
            catanglincr=true;
        }
        if(catangle>=44)
        {
            catanglincr=false;
            cateat2=true;
        }
        if(catanglincr)
        {
            catangle+=4;
        }
    }

    if(cateat2)
    {
        leafhole2+=0.05;
    }

    if(catmove)
    {
        caty+=0.025;
    }

    glutPostRedisplay();
    glutTimerFunc(650,update4,0);
}

/******************************************************Functions for Objects*************************************************************************/

void buttons(char* btn1,char* btn2)
{
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(310,50);
    glVertex2f(360,50);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(360,30);
    glVertex2f(310,30);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    printstring(320,40,btn1);

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(70,30);
    glVertex2f(20,30);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(20,50);
    glVertex2f(70,50);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    printstring(30,40,btn2);
}

void skyland(int sx1=0,int sy1=0,int sx2=1100,int sy2=1100, int lx1=0, int ly1=0, int lx2=1100, int ly2=200)
{
//Sky

    glColor3f(0.0,0.9,0.9);
    glBegin(GL_POLYGON);
    glVertex2f(sx1,sy1);
    glColor3f(0.419608 ,0.137255 , 0.556863);
    glVertex2f(sx1,sy2);
    glColor3f(0.0,0.9,0.9);
    glVertex2f(sx2,sy2);
    glColor3f(0.0,0.6,0.9);
    glVertex2f(sx2,sy1+300);
    glEnd();

//land
    glBegin(GL_POLYGON);
    glColor3f( 0.419608 , 0.556863 , 0.137255);
    glVertex2f(lx1,ly1);
    glColor3f(0.196078 ,0.8 , 0.196078);
    glVertex2f(lx2,ly1);
    glColor3f(0.196078 ,0.8 , 0.196078);
    glVertex2f(lx2,ly2);
    glColor3f( 0.419608 , 0.556863 , 0.137255);
    glVertex2f(lx1,ly2-50);
    glEnd();

}

void cloud(int x,int y)
{
    circle(x,y,18,0,360);
    circle(x+15,y,18,0,360);
    circle(x+15,y+15,18,0,360);
    circle(x+25,y,18,0,360);
}

void clouds()
{
        glPushMatrix();
        glColor3f(1,1,1);
        glScaled(0.5,0.5,1);
        glTranslated(cloudx[0],0,0);
        cloud(-100,480);
        glColor3f(0.54,0.54,0.54);
        glTranslated(cloudx[1],0,0);
        cloud(520,400);
        glColor3f(0.81,0.81,0.81);
        glTranslated(cloudx[2],0,0);
        cloud(-350,390);
        glTranslated(cloudx[3],0,0);
        cloud(-20,420);
        glColor3f(0.74,0.74,0.74);
        glTranslated(cloudx[4],0,0);
        cloud(-350,460);
        glTranslated(cloudx[5],0,0);
        cloud(200,420);
        glColor3f(1,1,1);
        glTranslated(cloudx[6],0,0);
        cloud(-180,450);
        glTranslated(cloudx[7],0,0);
        cloud(40,400);
        glColor3f(0.84,0.84,0.84);
        glTranslated(cloudx[8],0,0);
        cloud(300,490);
        glColor3f(0.89,0.89,0.89);
        glTranslated(cloudx[9],0,0);
        cloud(370,375);
        glTranslated(cloudx[10],0,0);
        cloud(425,400);
        glTranslated(cloudx[11]*0.05,0,0);
        cloud(-250,440);
        glTranslated(cloudx[12]*0.01,0,0);
        cloud(-290,390);
        glTranslated(cloudx[13]*0.02,0,0);
        cloud(-400,480);
        glTranslated(cloudx[14]*0.035,0,0);
        cloud(-600,500);
        glTranslated(cloudx[15]*0.02,0,0);
        cloud(-850,400);
        glTranslated(cloudx[16]*0.02,0,0);
        cloud(-1000,440);
        glTranslated(cloudx[17]*0.03,0,0);
        cloud(-1200,390);
        glTranslated(cloudx[18]*0.04,0,0);
        cloud(-1400,480);
        glTranslated(cloudx[19]*0.05,0,0);
        cloud(-1600,500);
        glPopMatrix();
}

void sun(double x, double y)
{
    glColor3f(1,1,0);
    circle(x,y,15,0,360);
}

void tree(int x, int y)
{

    //trunk
    glBegin(GL_POLYGON);
    glColor3f(0.3,0.1,0.0);
    glVertex2f(x,y);
    glVertex2f(x,y+100);
    glVertex2f(x-3,y+110);
    glVertex2f(x+2,y+112);
    glVertex2f(x+8,y+80);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(x+25,y+123);
    glVertex2f(x+27,y+122);
    glVertex2f(x+15,y+80);
    glVertex2f(x+15,y);
    glEnd();

    //leaves
    glColor3f(0.5,0.7,0.0);
    circle(x-10,y+120,20,0,360);
    circle(x-5,y+130,20,0,360);
    circle(x+5,y+145,20,0,360);
    circle(x+4,y+110,20,0,360);
    circle(x+24,y+120,20,0,360);
    circle(x+4,y+120,20,0,360);
    circle(x-6,y+120,20,0,360);
    circle(x+14,y+120,20,0,360);
}

void treebark()
{
    glColor3f(0.251,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(35,0);
    glVertex2f(35,70);
    glVertex2f(65,170);
    glVertex2f(68,200);
    glVertex2f(35,130);
    glVertex2f(35,400);
    glVertex2f(0,400);
    glEnd();
}

void fruits()
{
    glColor3f(0,0,0);
    line(20,270,20,275);
    glColor3f(1,0,0);
    circle(20,270,3,0,360);

    glColor3f(0,0,0);
    line(10,230,10,235);
    glColor3f(1,0,0);
    circle(10,230,3,0,360);

    glColor3f(0,0,0);
    line(60,230,60,235);
    glColor3f(1,0,0);
    circle(60,230,3,0,360);

    glColor3f(0,0,0);
    line(100,210,100,215);
    glColor3f(1,0,0);
    circle(100,210,3,0,360);

    glColor3f(0,0,0);
    line(310,228,310,233);
    glColor3f(1,0,0);
    circle(310,228,3,0,360);
}

void smalleggs(int x=150, int y=120)
{
    circle(x,y,10,0,360);
    circle(x+50,y+20,10,0,360);
    circle(x+70,y+20,10,0,360);
    circle(x,y-30,10,0,360);
}

void butterfly(int x=190,int y=290, int s=0)
{
    glColor3f(1,1,0.3);

//antenna
    glColor3f(0,0,0);
    circle(x-5,y-20,3,0,360,0.33,30);
    circle(x+5,y-20,3,0,360,0.33,30);

//small head
    glColor3f(1,0.85,0);
    circle(x,y,8,0,360);
    glColor3f(1,0.54,0);

//head
    circle(x,y-20,18,0,360);
    glColor3f(0.95,0.35,0);

//eyes
    glColor3f(0,0,0);
    circle(x-9,y-10,2,0,360);
    circle(x+9,y-10,2,0,360);

//wings
    glColor3f(0.95,0.35,0);
    circle(x-30,y-60,30-s,0,360);
    circle(x-10,y-100,30-s,0,360);
    circle(x+10,y-100,30-s,0,360);
    circle(x+10,y-80,30-s,0,360);
    circle(x+30,y-60,30-s,0,360);
    circle(x-20,y-80,20-s,0,360);


//body
    glColor3f(1,0.8,0);
    circle(x,y-45,14.5,0,360);
    circle(x,y-50,14,0,360);
    circle(x,y-60,13,0,360);
    circle(x,y-70,13,0,360);
    circle(x,y-80,12,0,360);
    circle(x,y-90,12,0,360);
    circle(x,y-100,11.5,0,360);
    circle(x,y-110,10,0,360);
    circle(x,y-120,10,0,360);
    circle(x,y-130,10,0,360);
    circle(x,y-141,9,0,360);

//spots on wings
    glColor3f(0,0,0.2);
    circle(x-25,y-50,6,0,360);
    circle(x-25,y-70,4,0,360);
    circle(x+24,y-80,6,0,360);
    circle(x+36,y-50,4,0,360);
    circle(x-20,y-110,6,0,360);
    circle(x+20,y-110,6,0,360);

}

void scaledbutterfly(int x=190,int y=290, int s=30, int butangle=70)
{
    glPushMatrix();
    glScaled(0.2,0.2,1);
    glRotated(butangle,0,0,1);
    butterfly(x,y,s);
    glPopMatrix();
//    glFlush();
}

void butterflies()
{
    glPushMatrix();
    glTranslated(xax,yax,0);

    if(flag1)
    {
            scaledbutterfly(190,290,-5,but1angle);
            flag1=false;
    }
    else
    {
            scaledbutterfly(190,290,11,but1angle);
            flag1=true;
    }
    glPopMatrix();

    glPushMatrix();
    glTranslated(but2x,but2y,0);
    if(flag2)
    {
            scaledbutterfly(-290,-390,-5,but2angle);
            flag2=false;
    }
    else
    {
            scaledbutterfly(-290,-390,11,but2angle);
            flag2=true;
    }

    glPopMatrix();
}

void caterpillar(int x=300,int y=200,double ch=1,double c1=1,double c2=1,double c3=1,double c4=1,double c5=1,double c6=1,double c7=1,double c8=1)
{

//left leg lines
    glColor4f(0,0,0,c1);
    line(170,250.0,190,250);
    line(169,245,190,250);
    line(170,240.0,190,250);

    glColor4f(0,0,0,c2);
    line(169,235.0,190,240);
    line(169,230.0,190,230);
    line(170,225.0,190,230);

    glColor4f(0,0,0,c4);
    line(170,220.0,190,220);
    line(167,215.0,190,220);
    line(168,210.0,190,210);

    glColor4f(0,0,0,c5);
    line(170,205.0,190,210);
    line(169,200.0,190,205);
    line(169,195.0,190,205);

    glColor4f(0,0,0,c6);
    line(170,190.0,190,205);
    line(170,185.0,190,205);
    line(170,180.0,190,200);

    glColor4f(0,0,0,c6);
    line(170,175.0,190,200);
    line(169,170.0,190,180);
    line(169,165.0,190,180);

    glColor4f(0,0,0,c7);
    line(169,160.0,190,180);
    line(171,155.0,190,175.0);
    line(171,150.0,190,170);

    glColor4f(0,0,0,c8);
    line(171,145.0,190,170);
    line(171,140.0,190,165);
    line(171,135.0,190,165);

//right leg lines
    glColor4f(0,0,0,c1);
    line(200,250.0,213,250);
    line(200,245.0,213,240);
    line(200,240.0,213,230);

    glColor4f(0,0,0,c2);
    line(200,235.0,213,230);
    line(200,230.0,213,220);
    line(200,225.0,213,220);

    glColor4f(0,0,0,c4);
    line(200,220.0,213,210);
    line(200,210.0,213,210);
    line(200,205.0,213,205);

    glColor4f(0,0,0,c5);
    line(200,200.0,213,200);
    line(200,190.0,213,190);

    glColor4f(0,0,0,c6);
    line(200,185.0,213,180);
    line(200,185.0,213,183);
    line(200,200.0,213,185);

    glColor4f(0,0,0,c6);
    line(200,180.0,213,175);
    line(200,180.0,213,170);
    line(200,170.0,211,165);

    glColor4f(0,0,0,c7);
    line(200,170.0,211,160);
    line(200,170.0,211,155.0);
    line(180,160.0,211,150);


    //legs left
    glColor4f(0,0,0,c1);
    circle(175.0,250.0,5,0,360);
    glColor4f(0,0,0,c2);
    circle(175.0,240.0,5,0,360);
    glColor4f(0,0,0,c3);
    circle(175.0,230.0,5,0,360);
    glColor4f(0,0,0,c4);
    circle(175.0,220.0,5,0,360);
    circle(175.0,210.0,5,0,360);
    glColor4f(0,0,0,c5);
    circle(175.0,200.0,5,0,360);
    glColor4f(0,0,0,c6);
    circle(175.0,190.0,5,0,360);
    circle(177.0,180.0,5,0,360);
    glColor4f(0,0,0,c7);
    circle(177.0,170.0,5,0,360);
    glColor4f(0,0,0,c8);
    circle(178.0,160.0,5,0,360);
    circle(178.0,150.0,5,0,360);

    //legs right
    glColor4f(0,0,0,c1);
    circle(205.0,250.0,5,0,360);
    glColor4f(0,0,0,c2);
    circle(205.0,240.0,5,0,360);
    glColor4f(0,0,0,c3);
    circle(205.0,240.0,5,0,360);
    glColor4f(0,0,0,c4);
    circle(205.0,230.0,5,0,360);
    circle(205.0,220.0,5,0,360);
    glColor4f(0,0,0,c5);
    circle(205.0,210.0,5,0,360);
    glColor4f(0,0,0,c6);
    circle(205.0,200.0,5,0,360);
    circle(203.0,190.0,5,0,360);
    glColor4f(0,0,0,c7);
    circle(203.0,180.0,5,0,360);
    circle(202.0,170.0,5,0,360);
    glColor4f(0,0,0,c8);
    circle(202.0,160.0,5,0,360);
    circle(202.0,150.0,5,0,360);

    //antenna
    glColor4f(0,0,0,ch);
    circle(185.0,283.0,0.20,0,360,3,30);
    circle(197.0,283.0,0.20,0,360,3,30);

    //body
    glColor4f(1,0,0,ch);
    circle(190.0,265.0,13.5,0,360);
    glColor4f(1,0.8,0,c1);
    circle(190.0,245.0,13.0,0,360);
    glColor4f(1,0.8,0,c2);
    circle(190.0,240.0,13,0,360);
    glColor4f(1,0.8,0,c3);
    circle(190.0,230.0,12.5,0,360);
    glColor4f(1,0.8,0,c4);
    circle(190.0,220.0,12,0,360);
    circle(190.0,210.0,11.5,0,360);
    glColor4f(1,0.8,0,c5);
    circle(190.0,200.0,11,0,360);
    glColor4f(1,0.8,0,c6);
    circle(190.0,190.0,11.5,0,360);
    circle(190.0,180.0,10,0,360);
    glColor4f(1,0.8,0,c7);
    circle(190.0,170.0,10,0,360);
    circle(190.0,160.0,10,0,360);
    glColor4f(1,0.8,0,c8);
    circle(190.0,150.0,10,0,360);
    circle(190.0,145.0,10,0,360);

    //spots
    glColor4f(0.5,0.4,0.3,c2);
    circle(198.0,240.0,3,0,360);
    circle(182.0,230.0,3,0,360);
    glColor4f(0.5,0.4,0.3,c4);
    circle(198.0,220.0,3,0,360);
    circle(182.0,210.0,3,0,360);
    glColor4f(0.5,0.4,0.3,c6);
    circle(198.0,200.0,3,0,360);
    circle(182.0,190.0,3,0,360);

    //eye
    glColor4f(0,0,0,ch);
    circle(184.0,270.0,2.0,0,360);
    circle(197.0,270.0,2.0,0,360);
}

void scaledcaterpillar(int x=300, int y=200)
{
    glPushMatrix();
    glScaled(0.3,0.7,1);
    glTranslated(0.8,0,0);
    caterpillar(x,y);
    glPopMatrix();
}

void eggs()
{
    glColor4f(1,1,1,eggtrans);
    glPushMatrix();
    glScaled(0.2,0.2,0);
    smalleggs(650,420);
    glPopMatrix();
}

void bigleaf(int x=170,int y=210)
{
    //Leaf
    glColor3f(0,0.283,0);
    circle(x,y,8,0,360,3,10);
    circle(x+30,y,8,0,360,3,10);
    circle(x+17,y-70,5,0,360,5,7);
    circle(x+18,y-75,5,0,360,3,7);

    //Stem
    glColor3f(0.251,0,0);
    glLineWidth(5);
    line(x+15,y+62,x+15,y+200);

}

void wind(int x,int y)
{
    glColor4f(1,1,1,0.15);

    circle(x,y,25,200,255,1,1,1);
    line(x-14,y-22,x+20,y-24);

    circle(x,y,30,200,255,1,1,1);
    line(x-10,y-27,x+20,y-29);

    circle(x,y,35,200,255,1,1,1);
    line(x-10,y-32,x+20,y-34);
}

void grass(int x, int y)
{
    glColor3f(0,0.283,0);
    circle(x,y,8,0,360,0.2,3);

    glPushMatrix();
    glRotated(4,0,0,1);
    circle(x-3,y-3,8,0,360,0.2,2.5);
    glPopMatrix();

    glPushMatrix();
    glRotated(356,0,0,1);
    circle(x+3,y-3,8,0,360,0.2,2.5);
    glPopMatrix();

    glPushMatrix();
    glRotated(16,0,0,1);
    circle(x-4,y-3,8,0,360,0.2,2.5);
    glPopMatrix();

    glPushMatrix();
    glRotated(344,0,0,1);
    circle(x+4,y-3,8,0,360,0.2,2.5);
    glPopMatrix();
}

void grassfunc()
{
    glPushMatrix();
    glScaled(0.8,0.65,1);
    glTranslated(-0.2,-0.4,0);
    grass(200,200);
    glTranslated(-0.1,-0.6,0);
    grass(200,200);
    glTranslated(0.7,0.4,0);
    grass(200,200);
    glTranslated(0.5,0.1,0);
    grass(200,200);
    glTranslated(-1.9,-0.3,0);
    grass(200,200);

    glScaled(0.4,0.45,1);
    glTranslated(1.5,0.2,0);
    grass(200,200);
    glTranslated(-1.3,-0.5,0);
    grass(200,200);
    glTranslated(2.2,0.8,0);
    grass(200,200);

    glTranslated(2.2,-0.6,0);
    grass(200,200);
    glTranslated(-1.4,0.4,0);
    grass(200,200);
    glTranslated(1.2,-1.2,0);
    grass(200,200);
    glTranslated(-0.9,0,0);
    grass(200,200);
    glPopMatrix();
}

void screen4egg()
{
    glPushMatrix();
    glColor3f(1,1,1);
    glRotated(eggang,0,0,1);
    if(!flagcrack)
    circle(200.0,200.0,3,0,360,4,14);
    else
    circle(200.0,200.0,3,0,360,10,7.2);
    glPopMatrix();

    //Cracks
    glPushMatrix();
    glRotated(90,0,0,1);
    glRotated(180,0,1,0);
    glRotated(180,1,0,0);
    glTranslated(0,0.02,0);
    glScaled(1.4,1,1);
    glLineWidth(2.5);
    glColor4f(0,0.283,0,crackvisib);
    line(195,205,188,210);
    glColor4f(0,0.283,0,crackvisib/2);
    line(200,210,195,205);
    glColor4f(0,0.283,0,crackvisib/5);
    line(200,210,205,205);
    glColor4f(0,0.283,0,crackvisib/8);
    line(205,205,212,212);
    glPopMatrix();

    if(swhatch)
    {
        swegghatch();
    }
}

void swegghatch()
{
    //Holes
    glColor3f(0,0.283,0);
    circle(220,184,12.5,0,360);
    circle(228,190,12.5,0,360);
    circle(211,192,2.5,0,360);
    circle(222,200,2.5,0,360);
    circle(228,205,3.5,0,360);
    circle(207,182,2.5,0,360);
    circle(217,216.5,2.5,0,360);
    circle(222,212.5,2.5,0,360);

    //White bits on leaves
    glColor3f(1,1,1);
    circle(220,170,3.5,0,360);
    circle(212,162,2.5,0,360,1,2);
    circle(217,156.5,1.5,0,360);
    circle(228,162.5,5.5,0,360,1,1.5);
    circle(228,230.5,1.5,0,360);

    //green
    glColor3f(0,0.283,0);
    circle(233,159,1.5,0,360);
    circle(224,158.5,1.5,0,360);
    circle(228,169.5,1.5,0,360);
    circle(220,166.5,1.5,0,360);
    circle(220,172.5,1.5,0,360);

    if(catout)
    {
        caterpillarout(200,200);
    }
}

void caterpillarout(int x=200, int y=200)
{
    if(cateat1)
    {
        cateating(281,194);
    }
    if(cateat2)
    {
        cateating(278,218);
    }

    glPushMatrix();
    glScaled(0.38,0.38,1);
    glRotated(235+catangle,0,0,1);
    glTranslated(catx,caty,0);
    caterpillar(x,y,cathead,cat1,cat2,cat3,cat4,cat5,cat6,cat7,cat8);
    glPopMatrix();
}

void cateating(int x=281,int y=194)
{
    glColor4f( 0.419608 , 0.556863 , 0.137255,leafhole1);
    circle(x,y,4);
    glColor3f(0,0.283,0);
    circle(x+3,y,1.5);
    circle(x-3,y+3,1.5);
    circle(x-5,y-3,1.5);
}

/******************************************************Mouse Functions*************************************************************************/

//For screen1, Project Intro
void mouse1(int btn,int state,int x,int y)
{
    x=x*1400/glutGet(GLUT_SCREEN_WIDTH);
    y=y*1200/glutGet(GLUT_SCREEN_HEIGHT);

    printf("Screen1, Mouse1: %d %d \n",x,y);

    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if(x>=1085 && x<=1260 && y>=1015 && y<=1075)
        {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glPointSize(3.0);
            glClearColor(1,1,1,1);
            glutDisplayFunc(screen2);
            glutMouseFunc(mouse2);
            glFlush();
            glutPostRedisplay();
        }
        else if(x>=70 && x<=245 && y>=1015 && y<=1075)
        {
            glutHideWindow();
        }
    }
}

void mouse2(int btn,int state,int x,int y)
{
    x=x*1400/glutGet(GLUT_SCREEN_WIDTH);
    y=y*1200/glutGet(GLUT_SCREEN_HEIGHT);
    printf("Screen2, Mouse2: %d %d \n",x,y);

    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if(x>=1085 && x<=1260 && y>=1015 && y<=1075)
        {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glPointSize(3.0);
            glClearColor(1,1,1,1);
            if(flag3update)
            {
                glutTimerFunc(100,update3,0);
                flag3update=false;
            }
            glutDisplayFunc(screen3);
            glutMouseFunc(mouse3);
            glFlush();
            glutPostRedisplay();
        }
        else if(x>=70 && x<=245 && y>=1015 && y<=1075)
        {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glPointSize(3.0);
            glClearColor(1,1,1,1);
            glutDisplayFunc(screen1);
            glutMouseFunc(mouse1);
            glFlush();
            glutPostRedisplay();
        }
    }
}

void mouse3(int btn,int state,int x,int y)
{
    x=x*1400/glutGet(GLUT_SCREEN_WIDTH);
    y=y*1200/glutGet(GLUT_SCREEN_HEIGHT);
    printf("Screen3, Mouse3: %d %d \n",x,y);

    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if(x>=1085 && x<=1260 && y>=1015 && y<=1075)
        {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glPointSize(3.0);
            glClearColor(1,1,1,1);
            if(flag4update)
            {
                glutTimerFunc(100,update4,0);
                flag4update=false;
            }
            glutDisplayFunc(screen4);
            glutMouseFunc(mouse4);
            glFlush();
            glutPostRedisplay();
        }
        else if(x>=70 && x<=245 && y>=1015 && y<=1075)
        {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glPointSize(3.0);
            glClearColor(1,1,1,1);
            glutDisplayFunc(screen2);
            glutMouseFunc(mouse2);
            glFlush();
            glutPostRedisplay();
        }
    }
}

void mouse4(int btn,int state,int x,int y)
{
    x=x*1400/glutGet(GLUT_SCREEN_WIDTH);
    y=y*1200/glutGet(GLUT_SCREEN_HEIGHT);
    printf("Screen4, Mouse4: %d %d \n",x,y);

    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if(x>=1085 && x<=1260 && y>=1015 && y<=1075)
        {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glPointSize(3.0);
            glClearColor(1,1,1,1);
            glutDisplayFunc(screen5);
            glutMouseFunc(mouse5);
            glFlush();
            glutPostRedisplay();
        }
        else if(x>=70 && x<=245 && y>=1015 && y<=1075)
        {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glPointSize(3.0);
            glClearColor(1,1,1,1);
            glutDisplayFunc(screen3);
            glutMouseFunc(mouse3);
            glFlush();
            glutPostRedisplay();
        }
    }
}

void mouse5(int btn,int state,int x,int y)
{
    x=x*1400/glutGet(GLUT_SCREEN_WIDTH);
    y=y*1200/glutGet(GLUT_SCREEN_HEIGHT);
    printf("Screen5, Mouse5: %d %d \n",x,y);

    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if(x>=1085 && x<=1260 && y>=1015 && y<=1075)
        {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glPointSize(3.0);
            glClearColor(1,1,1,1);
            glutDisplayFunc(screen6);
            glutMouseFunc(mouse6);
            glFlush();
            glutPostRedisplay();
        }
        else if(x>=70 && x<=245 && y>=1015 && y<=1075)
        {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glPointSize(3.0);
            glClearColor(1,1,1,1);
            glutDisplayFunc(screen4);
            glutMouseFunc(mouse4);
            glFlush();
            glutPostRedisplay();
        }
    }
}

void mouse6(int btn,int state,int x,int y)
{

}


/******************************************************Screens*************************************************************************/
//1st Screen, Project Intro
void screen1()
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    //Green Background
    glColor3f(0,1,0);

    //Gradient Color
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glColor3f(0,1.45,0);
    glVertex2f(450,0);
    glColor3f(1,0,0);
    glVertex2f(400,408);
    glColor3f(0,0,0);
    glVertex2f(0,600);
    glEnd();


    glColor3f(0.0f, 0.0f, 1.0f);
    printstring(190,360,"PROJECT:");
    glColor3f(1.0f, 1.0f, 1.0f);
    printstring(100,330,"**********************************************************************");
    glColor3f(0.0f, 1.0f, 0.0f);
    printstring(100,320,"*                         -------  S E R I C U L T U R E   -------                                    *");
    glColor3f(1.0f, 1.0f, 1.0f);
    printstring(100,310,"*                                                                                                                                        *");
    printstring(100,300,"**********************************************************************");
    glColor3f(0.0f, 1.0f, 1.0f);
    printstring(190,250,"Team Members:");
    glColor3f(1.0f, 1.0f, 1.0f);
    printstring(130,200,"Sowjanya Nayak H                                  4NM12CS162");
    printstring(130,180,"Sourabh S Shenoy                                   4NM12CS160");
    glColor3f(1.0f, .0f, .0f);
    printstring(185,140,"Under The Guidance Of");
    glColor3f(1.0f, 1.0f, 0.0f);
    printstring(190,120," Mr.Pradeep Kanchan");
    glColor3f(1.0f, 1.0f, 1.0f);
    printstring(170,100,"Assistant Professor, Dept of CSE");
    printstring(190,80,"  NMAMIT, Nitte");

    buttons("NEXT","EXIT");

    glutMouseFunc(mouse1);
    glFlush();
    glutSwapBuffers();

}

//About the Project
void screen2()
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 1.0f);
    printstring(185,360,"INTRODUCTION");
    glColor3f(1, 0, 0);
    printstring(100,330,"Sericulture is the process of extracting silk from silkworms.");
    printstring(30,310,"The stages of production are as follows:");
    printstring(30,290,"1.  The silk moth lays thousands of eggs.");
    printstring(30,270,"2.  The silk moth eggs hatch to form larvae of caterpllars, known as silkworms.");
    printstring(30,250,"3.  The larvae feed on mulberry leaves.");
    printstring(30,230,"4.  Having grown and moulded several times silkworm weaves a net to hold itself.");
    printstring(30,210,"5.  It swings it's head from side to side in figure '8' and spins silk.");
    printstring(30,190,"6.  The silk solidifies when it contacts the air.");
    printstring(30,170,"7.  It completely encloses itself in a cocoon. Length of silk is almost 1 mile.");
    printstring(30,150,"8.  Silk is obtained by rushing undamaged cocoon to find outside end of filament.");
    printstring(30,130,"9.  Silk filaments are then wound on a reel.");

    buttons("NEXT","BACK");

    glutMouseFunc(mouse2);
    glFlush();
    glutSwapBuffers();
}

//Scenary
void screen3()
{
    glClear(GL_COLOR_BUFFER_BIT);
    skyland(0,0,1100,1100,0,0,1100,200);
    clouds();
    sun(250,350);
    tree(70,100);
    tree(300,120);
    tree(20,120);
    fruits();
    grassfunc();
    eggs();
    butterflies();
    //wind(100,100);
    buttons("NEXT","BACK");
    glFlush();
    glutSwapBuffers();
}

void screen4()
{
    glClear(GL_COLOR_BUFFER_BIT);
    skyland(0,0,1100,1100,0,0,1100,330);
    treebark();
//Leaf
    glPushMatrix();
    glRotated(110,0,0,1);
    glScaled(1.4,1,1);
    bigleaf(170,210);
    glPopMatrix();

//Egg
    screen4egg();

    //scaledcaterpillar(300,200);

    buttons("NEXT","BACK");
    glFlush();
    glutSwapBuffers();
}

void screen5()
{
    glClear(GL_COLOR_BUFFER_BIT);
    skyland(0,0,1100,1100,0,0,1100,330);
    treebark();
    glPushMatrix();
    glRotated(110,0,0,1);
    glScaled(1.4,1,1);
    bigleaf(170,210);
    glPopMatrix();


    buttons("NEXT","BACK");
    glFlush();
    glutSwapBuffers();
}

void screen6()
{
    glClear(GL_COLOR_BUFFER_BIT);


    buttons("NEXT","BACK");
    glFlush();
    glutSwapBuffers();
}


/******************************************************Other Funcs*************************************************************************/

//glutKeyboardFunc
void cover(unsigned char key,int x,int y)
{
    screen1();
}


//Called from Main()
void init()
{
    glClearColor(0.0,0.5,0.0,0.0);
    glOrtho(0,400,0,400,-200,200);
    glColor3f(0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

int main(int argc, char *argv[])
 {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(1400,1200);
    glutInitWindowPosition(0,0);
    glutCreateWindow("SERICULTURE");
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(screen1);
    init();
    glutKeyboardFunc(cover);
    glutMainLoop();
    return 0;
}
