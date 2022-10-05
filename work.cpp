#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "modules.h"

#include<iostream>

using namespace std;





int pp = 2;
int qq = 0;
int ss = 0;

// double Txval=0,Tyval=0,Tzval=17;
double eyex = 0, eyey = 5, eyez = 20;
double x = 0, y = 0, z = 0;
double xaxis = 0, yaxis = 1, zaxis = 0;
double windowHeight=1200, windowWidth=800;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0;
GLboolean bRotate = false, uRotate = false;
// GLdouble eX = 5,eY = 3, eZ = 10, cX = 2, cY = 0, cZ = 0, uX = 0, uY = 0, uZ = 0;

double lpan = 0, rpan = 0, fdist = 0;
double dx = 0, dy = 0, dz = 0;
double yaw =0, pitch= 0, roll = 0;
double PI = 3.14;



float fan_height = 7.5;
float fan_angle = 1;







//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	//you can have upto 8 lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals
	//glShadeModel(GL_SMOOTH); //Enable smooth shading
}



void drawFloor()
{
    glPushMatrix();
        glTranslatef(-15,-5,5);
        drawCube(30,0.5,30);
    glPopMatrix();
}

void drawRight()
{
    glPushMatrix();
        glTranslatef(15,-5,5);
        drawCube(0.5,20,30);
    glPopMatrix();
}

void drawBack()
{
    glPushMatrix();
        glTranslatef(-15,-5,-25);
        drawCube(30,20,0.5);
    glPopMatrix();
}

void drawLeft()
{
    glPushMatrix();
        glTranslatef(-15,-5,5);
        drawCube(0.5,20,30);
    glPopMatrix();
}



void drawRoom()
{
    glColor3f(0.1,0.1,0.1);
    drawFloor();
    glColor3f(0.3,0.3,0.3);
    drawRight();
    drawBack();
    drawLeft();

}




void drawSofa()
{
    glColor3f(0.9, 0.9, 0.9);
    glTranslatef(-4,0,8);
    drawCube(0.3,2.5,5);
    glTranslatef(4,0,-8);
    
    glColor3f(0.1, 0.1, 0.1);
    glTranslatef(-3.7,0,8.1);
    drawCube(1.5,2,0.3);
    glTranslatef(3.7,0,-8.1);

    glTranslatef(-3.7,0,3);
    drawCube(1.5,2,0.3);
    glTranslatef(3.7,0,-3);

    glColor3f(0.7, 0.7, 0.7);

    glTranslatef(-3.7,0.5,8);
    drawCube(1.2,0.2,5);
    glTranslatef(3.7,-0.5,-8);

}

void drawSofa2()
{
    glColor3f(0.9, 0.9, 0.9);
    glTranslatef(-4,0,8);
    drawCube(0.3,2.5,3);
    glTranslatef(4,0,-8);
    
    glColor3f(0.1, 0.1, 0.1);
    glTranslatef(-3.7,0,8.1);
    drawCube(1.5,2,0.3);
    glTranslatef(3.7,0,-8.1);

    glTranslatef(-3.7,0,5);
    drawCube(1.5,2,0.3);
    glTranslatef(3.7,0,-5);

    glColor3f(0.7, 0.7, 0.7);

    glTranslatef(-3.7,0.5,8);
    drawCube(1.2,0.2,3);
    glTranslatef(3.7,-0.5,-8);

}


void drawMulSofa()
{
    glTranslatef(-1,0,-1);
    drawSofa();
    glTranslatef(1,0,1);

    glTranslatef(-2,0,10);
    glRotatef(180,0,1,0);
    drawSofa();
    glRotatef(-180,0,1,0);
    glTranslatef(2,0,-10);

    glTranslatef(4.5,0,3);
    glRotatef(-90,0,1,0);
    drawSofa2();
    glRotatef(90,0,1,0);
    glTranslatef(4.5,0,-3);

    glTranslatef(-17,0,5.5);
    glRotatef(90,0,1,0);
    drawSofa2();
    glRotatef(90,0,1,0);
    glTranslatef(17,0,-5.5);


}


void drawDoor()
{
    glColor3f(0.8, 0.8, 0.8);
    glTranslatef(-10,0,5);
    drawCube(0.2,7,2.5);
    glTranslatef(10,0,-5);

    glTranslatef(-10,0,2.45);
    drawCube(0.2,7,2.5);
    glTranslatef(10,0,-2.45);

    glColor3f(0.0, 0.0, 0.0);

    glTranslatef(-9.8,3,2.40);
    drawCube(0.1,1,0.3);
    glTranslatef(9.8,-3,-2.40);

    // glColor3f(0.0, 0.0, 1);

    glTranslatef(-9.8,3,3.0);
    drawCube(0.1,1,0.3);
    glTranslatef(9.8,3,-3.0);

}



void drawTable()
{   
    glColor3f(0.1,0.2,0.3);

    glTranslatef(-3,1.3,5.5);
    drawCube(2.75,0.4,2.75);
    glTranslatef(3,-1.3,-5.5);

    glTranslatef(-3,0,5.5);
    drawCube(0.5,1.3,0.5);
    glTranslatef(3,0,-5.5);

    glTranslatef(-0.75,0,5.5);
    drawCube(0.5,1.3,0.5);
    glTranslatef(0.75,0,-5.5);

    glTranslatef(-3,0,2.75);
    drawCube(0.5,1.3,0.5);
    glTranslatef(3,0,-2.75);

    glTranslatef(-0.75,0,2.75);
    drawCube(0.5,1.3,0.5);
    glTranslatef(0.75,0,-2.75);

}







void drawTriangle(float x, float y, float z){

        glBegin(GL_QUADS);

        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0,0,0);
        glVertex3f(x,0,0);
        glVertex3f(x,y,0);
        glVertex3f(0,y,0);

        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(x,0,0);
        glVertex3f(x,0,-z);
        glVertex3f(x,y,-z);
        glVertex3f(x,y,0);

        glNormal3f(0.0f, 1.0f, 1.0f);
        glVertex3f(x,0,-z);
        glVertex3f(0,0,0);
        glVertex3f(0,y,0);
        glVertex3f(x,y,-z);

        glEnd();

        glBegin(GL_TRIANGLES);

        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0,y,0);
        glVertex3f(x,y,0);
        glVertex3f(x,y,-z);

        glNormal3f(0.0f, -1.0f, 0.0f);

        glVertex3f(0,0,0);
        glVertex3f(x,0,0);
        glVertex3f(x,0,-z);

        glEnd();
    

}

void drawCircle(float x, float y, float z)
{
    glPushMatrix();
    for(int i = 0; i < 100; i++)
    {
        glRotatef(3.6,0,1,0);
        drawTriangle(x,y,z);
    }
    
    glPopMatrix();
}

void drawRoundTable()
{
    glColor3f(0.3,0,1);
    glTranslatef(6,2,6.5);

    drawCircle(2.2,0.1,0.2);
    
    glTranslatef(-6,-2,-6.5);


    // glTranslated(6,0,0);

    
}

void drawDinningTable(){

    drawRoundTable();

    glTranslatef(4,0,6);
    drawCube(0.2,2,0.2);
    glTranslatef(-4,0,-6);

    glTranslatef(4.2,0,8);
    drawCube(0.2,2,0.2);
    glTranslatef(-4.2,0,-8);

    glTranslatef(7.7,0,6);
    drawCube(0.2,2,0.2);
    glTranslatef(-7.7,0,-6);

    glTranslatef(7.5,0,8);
    drawCube(0.2,2,0.2);
    glTranslatef(-7.5,0,-8);
}




void drawChair(){


    glPushMatrix();

        glTranslatef(1.5,1,7);

        drawCube(0.1,2,2);

        glTranslatef(-1.5,-1,-7);

        glTranslatef(1.5,1,7);

        drawCube(1.3,0.1,2);

        glTranslatef(-1.5,-1,-7);

        // glColor3f(1,0,1);

        glTranslatef(1.9,0,6.2);

        drawCube(0.2,1,0.2);

        glTranslatef(-1.9,0,-6.2);

        // glColor3f(1,1,1);


        glTranslatef(2.0,0,6.1);

        drawCircle(0.4,0.1,0.2);
        
        glTranslatef(-2.0,0,-6.1);


        


    glPopMatrix();
}



void drawSetChair()
{   
    glTranslatef(0.7,0,0.8);
    drawChair();
    glTranslatef(-0.7,0,-0.8);


    glPushMatrix();
    // glTranslatef(0,0,10);
    glRotatef(180,0,1,0);
    glTranslatef(-10,0,-12);


    drawChair();

    glRotatef(-180,0,1,0);
    glTranslatef(10,0,12);
    glPopMatrix();
    
     glPushMatrix();
    // glTranslatef(0,0,10);
    glRotatef(90,0,1,0);
    glTranslatef(-11,0,-1);


    drawChair();

    glRotatef(-90,0,1,0);
    glTranslatef(-11,0,-1);
    glPopMatrix();

    glRotatef(-90,0,1,0);
    glTranslatef(2,0,-11);


    drawChair();

    glRotatef(90,0,1,0);
    glTranslatef(2,0,-11);
    glPopMatrix();

}



void drawFanStand(float fan_height)
{
    drawCircle(0.2,fan_height,0.2);
}



void drawPreFanBlade()
{
     glPushMatrix();
        glTranslatef(0,7,0);
    glTranslatef(0,0,0.8);

        glRotatef(30+theta,0,0,1);
        drawCube(3,0.5,0.2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,0.8);
    

        glTranslatef(0,7,0);
        glRotatef(150+theta,0,0,1);
        drawCube(3,0.5,0.2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,0.8);
    

        glTranslatef(0,7,0);
        glRotatef(270+theta,0,0,1);
        drawCube(3,0.5,0.2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,0.8);
    

        glTranslatef(0,7,0);
        glRotatef(90,1,0,0);
        drawCircle(0.5,0.2,0.2);
        glTranslatef(0,-1,0);
        drawCircle(0.1,0.8,0.2);

    glPopMatrix();
}

void drawFanBlade()
{   

    glPushMatrix();
    // glRotatef(90,0,0,0);
    // glRotatef(45, 0,0,1);
    glRotatef(alpha, 0, yaxis, 0);
    drawPreFanBlade();
    glPopMatrix();
}



void drawPreFan(float fan_height)
{
    // glTranslatef
    drawFanStand(fan_height);
    glPushMatrix();
    // glTranslatef(0,0,1);
    glTranslatef(0,fan_height-7.5,0);
    drawFanBlade();
    // glTranslatef(0,0,-1);
    glPopMatrix();
}

void drawFan(float fan_height)
{
    glTranslatef(0,0,-4);
   drawPreFan(fan_height);
    glTranslatef(0,0,4);

}





void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glFrustum(-5+lpan, 5+rpan, -4, 5, fdist+5, 60.0);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    // gluLookAt(5,3, ex, 2,0,0, 0,1,uZ); // camera , ,
    // gluLookAt(2,3,Tzval, 1.5,0,0, 0,1,uZ); // camera , ,
    gluLookAt(eyex,eyey,eyez, x+dx,y+dy,z+dz, xaxis,yaxis,zaxis); // camera , ,


    GLfloat ambientColor[] = {0.8f, 0.8f, 0.8f, 5.0f}; //Color (0.2, 0.2, 0.2) and intensity //can be greater than 1 so not like color
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {2.0f, 2.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)

	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

   

    glViewport(0, 0, windowHeight, windowWidth);

    //glRotatef(30, 0, 0, 1 );
    //glScalef(1.5,1.5,1.5);


    // glRotatef( alpha,axis_x, axis_y, 0.0 );
    // glRotatef( theta, axis_x, axis_y, 0.0 );
  
    // glTranslatef(0,-10,0);
    
    glPushMatrix();

    drawRoom();

    glPopMatrix();
    
    float x,y,z;
    x = -4.5;
    y = -4.5;
    z = -8;

    glPushMatrix();
    glTranslatef(x,y,z);

    glTranslatef(-2,0,0);
    drawMulSofa();
    glTranslatef(2,0,0);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(x,y,z);

    drawDoor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x,y,z);

    glTranslatef(-1,0,0);
     drawDinningTable();

    glTranslatef(-1,0,0);

    glPopMatrix();

    

    glPushMatrix();
    glTranslatef(x,y,z);

    glTranslatef(-2,0,0);

     drawTable();
    glTranslatef(-2,0,0);

    glPopMatrix();    

    glPushMatrix();
    glTranslatef(x,y,z);

    drawSetChair();
    glPopMatrix();


    glPushMatrix();
        glTranslatef(x,y,z);
        drawFan(fan_height);
    glPopMatrix();



    glFlush();
    glutSwapBuffers();
}


void myKeyboardFunc( unsigned char key, int x, int y )
{

    cout << key << endl;
    switch ( key )
    {

    case 'f':
        if(!bRotate)
        {
            fan_angle = 2;
            bRotate = !bRotate;
        }
        else{
            bRotate = !bRotate;
            uRotate = false;
        }
        // bRotate = !bRotate;
        // uRotate = false;
        axis_x=0.0;
        axis_y=1.0;
        break;
    case '1':
        if(bRotate)
        {
            fan_angle = 5;
        }
        break;
    case '2':
        if(bRotate)
        {
            fan_angle = 9;
        }
        break;
    case '3':
        if(bRotate)
        {
            fan_angle = 13;
        }
        break;

    case 'g':
    case 'G':
        uRotate = !uRotate;
        // bRotate = false;
        axis_x=1.0;
        axis_y=0.0;
        break;

    case '=':
        eyez--;
        break;
    case '-':
        eyez++;
        break;

    //panning
    case 'P':
        lpan-=1;
        rpan-=1;

        break;

    case 'p':
        lpan+=1;
        rpan +=1;
        break;

    case 'h':
        eyey++;
        break;

    case 'n':
        eyey--;
        break;

    case 'b':
        eyex++;
        break;
    
    case 'm':
        eyex--;
        break;
    case 'y':
        fan_height+=0.1;
        break;
    case 'Y':
        fan_height-=0.1;
        break;

    // case 'f':
    case '6':
        bRotate = !bRotate;
        uRotate = false;
        axis_x=0.0;
        axis_y=1.0;
        break;

    // case 'g':
    case '7':
        uRotate = !uRotate;
        bRotate = false;
        axis_x=1.0;
        axis_y=0.0;
        break;


//yaw
    case 'd':

        // yaw+=1;

        // if( yaw==90 || yaw ==0)
        // {
        //     yaw=0;
        //     dx=0;
        //     break;
        // }
        // dx =  abs(eyez-z)*tan(yaw*PI/180);

        y=y;

        dx += 0.1;

        //cout<<yaw<<endl;
        //cout<<"x :"<<x <<"y:"<<y<<"z:"<<z<<endl;

        break;
    case 'a':

        // yaw-=1;

        // if(yaw==-90 || yaw==0)
        // {
        //     yaw = 0;
        //     dx=0;
        //     break;
        // }

        // dx = abs(eyez-z)*tan(yaw*PI/180);

        y=y;

        dx -= 0.1;

        //cout<<"x :"<<x <<"y:"<<y<<"z:"<<z<<endl;

        break;
//pitch

    case 'w':

        // pitch+=1;

        // if( pitch==90 || pitch ==0)
        // {
        //     pitch=0;
        //     dy=0;
        //     break;
        // }
        // dy =  abs(eyez-z)*tan(pitch*PI/180);

        x=x;

        dy += 0.2;

        //cout< <pitch<<endl;
        //cout<<"x :"<<x <<"y:"<<y<<"z:"<<z<<endl;

        break;
    case 's':

        // pitch-=1;

        // if(pitch==-90 || pitch==0)
        // {
        //     pitch = 0;
        //     dy=0;
        //     break;
        // }
        // //cout<<pitch<<endl;


        // dy = abs(eyez-z)*tan(pitch*PI/180);

        x=x;

        dy -= 0.2;

        //cout<<"x :"<<x <<"y:"<<y<<"z:"<<z<<endl;

        break;

//roll
    case 'r':
        // roll+=0.5;
        // xaxis = cos(roll);
        // yaxis= sin(roll);
        
        zaxis+=0.2;

        break;
    case 'R':
        // roll-=0.5;

        // xaxis = cos(roll);
        // yaxis= sin(roll);

        zaxis-=0.2; 


        break;



    case 27:	// Escape key
        exit(1);
    }
}

float k = 0.5;

bool pos = true;
bool neg = false;

void animate()
{
    if (bRotate == true)
    {
        theta += fan_angle;
        if(theta > 360.0)
            theta -= 360.0*floor(theta/360.0);
    }

    if (uRotate == true)
    {
        if(alpha < 90 && pos)
        {
            alpha += k;
        }
        else{
            pos = false;
            neg = true;
        }
        if(alpha > -90 && neg)
        {
            alpha -= k;
        }
        else{
            pos = true;
            neg = false;
        }
        // if(alpha < -90)
            // k = -1*0.5;
        // if(alpha > 360.0)
        //     alpha -= 360.0*floor(alpha/360.0);
    }
    glutPostRedisplay();

}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(1000,1000);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("Assignment-1707119");
    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glutKeyboardFunc(myKeyboardFunc);
	initRendering();

    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();


    /////////////////////////////////////////




    return 0;
}

