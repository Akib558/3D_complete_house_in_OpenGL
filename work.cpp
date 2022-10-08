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
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0, angle_x = 0.0, angle_y = 0.0;
GLboolean bRotate = false, uRotate = false, xRotate = false, yRotate = false;
// GLdouble eX = 5,eY = 3, eZ = 10, cX = 2, cY = 0, cZ = 0, uX = 0, uY = 0, uZ = 0;

double lpan = 0, rpan = 0, fdist = 0;
double dx = 0, dy = 0, dz = 0;
double yaw =0, pitch= 0, roll = 0;
double PI = 3.14;



float fan_height = 7.5;
float fan_angle = 1;



 GLfloat mat_diffuse[][4] = {
        { 0.4, 0.4, 0.4, 1.0 },
        { 0.7, 0.7, 0.7, 1.0 },
        { 0.1, 0.2, 0.4, 1.0 },
        { 0.8, 0.1, 0.2, 1.0 },
        { 1.0, 0.64, 0.0, 1.0 },
        { 0.59, 0.44, 0.2, 1.0 },
        { 0.23, 0.37, 0.04, 1.0 },
        { 0.44, 0.33, 0.22, 1.0 },
        { 0.1, 0.1, 0.1, 1.0 }
    };




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
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[0]);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[0]);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    //////glcolor3f(0.1,0.1,0.1);
    drawFloor();
    //////glcolor3f(0.3,0.3,0.3);
    drawRight();
    drawBack();
    drawLeft();

}




void drawSofa()
{
    //////glcolor3f(0.9, 0.9, 0.9);
    glTranslatef(-4,0,8);
    drawCube(0.3,2.5,5);
    glTranslatef(4,0,-8);
    
    //////glcolor3f(0.1, 0.1, 0.1);
    glTranslatef(-3.7,0,8.1);
    drawCube(1.5,2,0.3);
    glTranslatef(3.7,0,-8.1);

    glTranslatef(-3.7,0,3);
    drawCube(1.5,2,0.3);
    glTranslatef(3.7,0,-3);

    //////glcolor3f(0.7, 0.7, 0.7);

    glTranslatef(-3.7,0.5,8);
    drawCube(1.2,0.2,5);
    glTranslatef(3.7,-0.5,-8);

}

void drawSofa2()
{
    //////glcolor3f(0.9, 0.9, 0.9);
    glTranslatef(-4,0,8);
    drawCube(0.3,2.5,3);
    glTranslatef(4,0,-8);
    
    //////glcolor3f(0.1, 0.1, 0.1);
    glTranslatef(-3.7,0,8.1);
    drawCube(1.5,2,0.3);
    glTranslatef(3.7,0,-8.1);

    glTranslatef(-3.7,0,5);
    drawCube(1.5,2,0.3);
    glTranslatef(3.7,0,-5);

    //////glcolor3f(0.7, 0.7, 0.7);

    glTranslatef(-3.7,0.5,8);
    drawCube(1.2,0.2,3);
    glTranslatef(3.7,-0.5,-8);

}


void drawMulSofa()
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[1]);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[1]);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
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
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[2]);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[2]);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    ////glcolor3f(0.8, 0.8, 0.8);
    glTranslatef(-10,0,5);
    drawCube(0.2,7,2.5);
    glTranslatef(10,0,-5);

    glTranslatef(-10,0,2.45);
    drawCube(0.2,7,2.5);
    glTranslatef(10,0,-2.45);

    ////glcolor3f(0.0, 0.0, 0.0);

    glTranslatef(-9.8,3,2.40);
    drawCube(0.1,1,0.3);
    glTranslatef(9.8,-3,-2.40);

    // ////glcolor3f(0.0, 0.0, 1);

    glTranslatef(-9.8,3,3.0);
    drawCube(0.1,1,0.3);
    glTranslatef(9.8,3,-3.0);

}



void drawTable()
{   
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[3]);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[3]);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    ////glcolor3f(0.1,0.2,0.3);

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
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[4]);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[4]);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    ////glcolor3f(0.3,0,1);
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

        // ////glcolor3f(1,0,1);

        glTranslatef(1.9,0,6.2);

        drawCube(0.2,1,0.2);

        glTranslatef(-1.9,0,-6.2);

        // ////glcolor3f(1,1,1);


        glTranslatef(2.0,0,6.1);

        drawCircle(0.4,0.1,0.2);
        
        glTranslatef(-2.0,0,-6.1);


        


    glPopMatrix();
}



void drawSetChair()
{   
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[5]);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[5]);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
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
        drawCube(2,0.5,0.2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,0.8);
    

        glTranslatef(0,7,0);
        glRotatef(150+theta,0,0,1);
        drawCube(2,0.5,0.2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,0.8);
    

        glTranslatef(0,7,0);
        glRotatef(270+theta,0,0,1);
        drawCube(2,0.5,0.2);
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

void drawFanCover2()
{
    for(int i = 0; i < 360; i+= 30)
    {
        glPushMatrix();
            glRotatef(i, 0, 0, 1);
            drawCube(2.3, 0.1,0.1);
            glTranslatef(2.3,0,0);
            glRotatef(103,0,0,1);
            drawCube(1.2, 0.1,1);

        glPopMatrix();
    }

    

    
}

void drawFanCover2_2()
{
    for(int i = 0; i < 360; i+= 30)
    {
        glPushMatrix();
            glRotatef(i, 0, 0, 1);
            drawCube(2.3, 0.1,0.1);
            // glTranslatef(2.3,0,0);
            // drawCube(0.1, 0.1,0.9);

        glPopMatrix();
    }

    

    
}

void drawFanCover1()
{
    glPushMatrix();
    glTranslatef(0,fan_height-0.5,1.2);
    drawFanCover2();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,fan_height-0.5,0.3);
    drawFanCover2_2();
    glPopMatrix();
}


void drawFanCover()
{
    
    glPushMatrix();
    glRotatef(alpha, 0, yaxis, 0);

        drawFanCover1();
        // drawCube(7.5, 0.2,0.2);
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
    drawFanCover();
    // glTranslatef(0,0,-1);
    glPopMatrix();
}

void drawFan(float fan_height)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[6]);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[6]);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
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
    gluLookAt(eyex,eyey,eyez, x+dx,y+dy,z+dz, xaxis,yaxis,zaxis); // camera , ,


    // GLfloat ambientColor[] = {0.8f, 0.8f, 0.8f, 5.0f}; //Color (0.2, 0.2, 0.2) and intensity //can be greater than 1 so not like color
	// glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	// GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
	// GLfloat lightPos0[] = {2.0f, 2.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
	// glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	// glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	// GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)

	// GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
	// glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	// glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

   

    glViewport(0, 0, windowHeight, windowWidth);

    //glRotatef(30, 0, 0, 1 );
    //glScalef(1.5,1.5,1.5);


    glRotatef( angle_x,axis_x, axis_y, 0.0 );
    glRotatef( angle_y, axis_x, axis_y, 0.0 );
  
    // glTranslatef(0,-10,0);
    
    glPushMatrix();

    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[1]);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[1]);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

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
    // case 'G':
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
        xRotate = !xRotate;
        yRotate = false;
        axis_x=0.0;
        axis_y=1.0;
        break;

    // case 'g':
    case '7':
        yRotate = !yRotate;
        xRotate = false;
        axis_x=1.0;
        axis_y=0.0;
        break;


//yaw
    case 'd':
        y=y;
        dx += 0.1;
        break;

    case 'a':

        y=y;
        dx -= 0.1;
        break;
//pitch

    case 'w':
        x=x;
        dy += 0.2;
        break;

    case 's':
        x=x;
        dy -= 0.2;

        break;

//roll
    case 'r':
        zaxis+=0.2;
        break;

    case 'R':
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
    }

    if (xRotate == true)
    {
        angle_x += 0.2;
        if(angle_x > 360.0)
            angle_x -= 360.0*floor(angle_x/360.0);
    }

    if (yRotate == true)
    {
        angle_y += 0.2;
        if(angle_y > 360.0)
            angle_y -= 360.0*floor(angle_y/360.0);
    }
    glutPostRedisplay();

}


void light()
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };

    GLfloat light1_ambient[]  = {1.0, 1.0, 1.0, 1.0};
    GLfloat light1_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light1_position[] = { 0.0, 40.0, -1.0, 1.0 };

    glEnable( GL_LIGHT0);
    glLightfv( GL_LIGHT0, GL_AMBIENT, light1_ambient);
    glLightfv( GL_LIGHT0, GL_DIFFUSE, light1_diffuse);
    glLightfv( GL_LIGHT0, GL_SPECULAR, light1_specular);
    glLightfv( GL_LIGHT0, GL_POSITION, light1_position);

    GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 10.0);

    GLfloat light2_ambient[]  = {0.8, 0.05, 0.05, 1.0};
    GLfloat light2_diffuse[] =  {0.8, 0.05, 0.05, 1.0};
    GLfloat light2_specular[] = { 1.0, 0.1, 0.1, 1.0 };
    GLfloat light2_position[] = { -4.0, 0.0, -1.0, 1.0 };

    glEnable( GL_LIGHT1);
    glLightfv( GL_LIGHT1, GL_AMBIENT, light2_ambient);
    glLightfv( GL_LIGHT1, GL_DIFFUSE, light2_diffuse);
    glLightfv( GL_LIGHT1, GL_SPECULAR, light2_specular);
    glLightfv( GL_LIGHT1, GL_POSITION, light2_position);
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
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    light();
    

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}

