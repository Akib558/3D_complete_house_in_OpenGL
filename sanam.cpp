#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
// #include <window.h>
#include <math.h>

double Txval=0,Tyval=0,Tzval=17;
double windowHeight=1200, windowWidth=800;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0;
GLboolean bRotate = false, uRotate = false;
GLdouble eX = 5,eY = 3, eZ = 10, cX = 2, cY = 0, cZ = 0, uX = 0, uY = 0, uZ = 0;
double dx = 0, dy = 0, dz = 0;
double yaw =0, pitch= 0, roll = 0;

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


void drawStairs()
{
    int cnt = 0;
    glBegin(GL_QUADS);
    float ss = 0.0f;
    for(; ss < 2.5; ss += 0.5)
    {
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f+ss, 0.0f, 0.0f);
        glVertex3f(0.5f+ss, 0.0f, 0.0f);
        glVertex3f(0.5f+ss, 0.4f+ss, 0.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, 0.0f);

        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.5f+ss, 0.0f, 0.0f);
        glVertex3f(0.5f+ss, 0.0f, -3.0f);
        glVertex3f(0.5f+ss, 0.4f+ss, -3.0f);
        glVertex3f(0.5f+ss, 0.4f+ss, 0.0f);

        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(0.5f+ss, 0.0f, -3.0f);
        glVertex3f(0.0f+ss, 0.0f, -3.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, -3.0f);
        glVertex3f(0.5f+ss, 0.4f+ss, -3.0f);

        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f+ss, 0.0f, -3.0f);
        glVertex3f(0.0f+ss, 0.0f, 0.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, 0.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, -3.0f);


        // top
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, 0.0f);
        glVertex3f(0.5f+ss, 0.4f+ss, 0.0f);
        glVertex3f(0.5f+ss, 0.4f+ss, -3.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, -3.0f);
        //bottom
        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(0.0f+ss, 0.0f, 0.0f);
        glVertex3f(0.5f+ss, 0.0f, 0.0f);
        glVertex3f(0.5f+ss, 0.0f, -3.0f);
        glVertex3f(0.0f+ss, 0.0f, -3.0f);
        // if(cnt%2 == 0){
        // glColor3f(1, 0, 1);
            
        // }
        // else{
        //     glColor3f(1,1,0);
        // }
        // cnt++;




        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f+ss, 0.0f, 0.0f);
        glVertex3f(3.0f+ss, 0.0f, 0.0f);
        glVertex3f(3.0f+ss, 0.4f+ss, 0.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, 0.0f);

        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(3.0f+ss, 0.0f, 0.0f);
        glVertex3f(3.0f+ss, 0.0f, -3.0f);
        glVertex3f(3.0f+ss, 0.4f+ss, -3.0f);
        glVertex3f(3.0f+ss, 0.4f+ss, 0.0f);

        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(3.0f+ss, 0.0f, -3.0f);
        glVertex3f(0.0f+ss, 0.0f, -3.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, -3.0f);
        glVertex3f(3.0f+ss, 0.4f+ss, -3.0f);

        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f+ss, 0.0f, -3.0f);
        glVertex3f(0.0f+ss, 0.0f, 0.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, 0.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, -3.0f);


        // top
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, 0.0f);
        glVertex3f(3.0f+ss, 0.4f+ss, 0.0f);
        glVertex3f(3.0f+ss, 0.4f+ss, -3.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, -3.0f);
        //bottom
        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(0.0f+ss, 0.0f, 0.0f);
        glVertex3f(3.0f+ss, 0.0f, 0.0f);
        glVertex3f(3.0f+ss, 0.0f, -3.0f);
        glVertex3f(0.0f+ss, 0.0f, -3.0f);
        
    }
    glEnd();
}



void drawStairs2()
{
    int cnt = 0;
    glBegin(GL_QUADS);
    float ss = 0.5f;
    int pp = 1;
    while(ss < 2.5)
    {
        ss += 0.5;
    }

            // glColor3f(1,1,0);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f+ss, 0.0f, 0.0f);
    glVertex3f(0.5f+ss, 0.0f, 0.0f);
    glVertex3f(0.5f+ss, 0.4f+ss, 0.0f);
    glVertex3f(0.0f+ss, 0.4f+ss, 0.0f);

    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.5f+ss, 0.0f, 0.0f);
    glVertex3f(0.5f+ss, 0.0f, -3.0f);
    glVertex3f(0.5f+ss, 0.4f+ss, -3.0f);
    glVertex3f(0.5f+ss, 0.4f+ss, 0.0f);

    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(0.5f+ss, 0.0f, -3.0f);
    glVertex3f(0.0f+ss, 0.0f, -3.0f);
    glVertex3f(0.0f+ss, 0.4f+ss, -3.0f);
    glVertex3f(0.5f+ss, 0.4f+ss, -3.0f);

    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f+ss, 0.0f, -3.0f);
    glVertex3f(0.0f+ss, 0.0f, 0.0f);
    glVertex3f(0.0f+ss, 0.4f+ss, 0.0f);
    glVertex3f(0.0f+ss, 0.4f+ss, -3.0f);


    // top
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f+ss, 0.4f+ss, 0.0f);
    glVertex3f(0.5f+ss, 0.4f+ss, 0.0f);
    glVertex3f(0.5f+ss, 0.4f+ss, -3.0f);
    glVertex3f(0.0f+ss, 0.4f+ss, -3.0f);
    //bottom
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(0.0f+ss, 0.0f, 0.0f);
    glVertex3f(0.5f+ss, 0.0f, 0.0f);
    glVertex3f(0.5f+ss, 0.0f, -3.0f);
    glVertex3f(0.0f+ss, 0.0f, -3.0f);



    for(; ss < 5; ss += 0.5)
    {
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f+ss, 0.0f, 0.0f);
        glVertex3f(0.5f+ss, 0.0f, 0.0f);
        glVertex3f(0.5f+ss, 0.4f+ss, 0.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, 0.0f);

        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.5f+ss, 0.0f, 0.0f);
        glVertex3f(0.5f+ss, 0.0f, -3.0f);
        glVertex3f(0.5f+ss, 0.4f+ss, -3.0f);
        glVertex3f(0.5f+ss, 0.4f+ss, 0.0f);

        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(0.5f+ss, 0.0f, -3.0f);
        glVertex3f(0.0f+ss, 0.0f, -3.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, -3.0f);
        glVertex3f(0.5f+ss, 0.4f+ss, -3.0f);

        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f+ss, 0.0f, -3.0f);
        glVertex3f(0.0f+ss, 0.0f, 0.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, 0.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, -3.0f);


        // top
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, 0.0f);
        glVertex3f(0.5f+ss, 0.4f+ss, 0.0f);
        glVertex3f(0.5f+ss, 0.4f+ss, -3.0f);
        glVertex3f(0.0f+ss, 0.4f+ss, -3.0f);
        //bottom
        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(0.0f+ss, 0.0f, 0.0f);
        glVertex3f(0.5f+ss, 0.0f, 0.0f);
        glVertex3f(0.5f+ss, 0.0f, -3.0f);
        glVertex3f(0.0f+ss, 0.0f, -3.0f);
        // if(cnt%2 == 0){
        // glColor3f(1, 0, 1);
            
        // }
        // else{
        //     glColor3f(1,1,0);
        // }
        // cnt++;
        
    }
    glEnd();
}


void drawWall_left()
{
    glBegin(GL_QUADS);
    glColor3f(0,1,1);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-10.0f, 0.0f, 10.0f);
    glVertex3f(-10.0f, 0.0f, -3.0f);
    glVertex3f(-10.0f, 10.0f, -3.0f);
    glVertex3f(-10.0f, 10.0f, 10.0f);
    glEnd();
}

void drawWall_back()
{
    glBegin(GL_QUADS);
    glColor3f(0,1,1);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(10.0f, 0.0f, -3.0f);
    glVertex3f(-10.0f, 0.0f, -3.0f);
    glVertex3f(-10.0f, 10.0f, -3.0f);
    glVertex3f(10.0f, 10.0f, -3.0f);
    glEnd();
}

void drawWall_right()
{
    glBegin(GL_QUADS);
    glColor3f(0,1,1);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(10.0f, 0.0f, 10.0f);
    glVertex3f(10.0f, 0.0f, -3.0f);
    glVertex3f(10.0f, 10.0f, -3.0f);
    glVertex3f(10.0f, 10.0f, 10.0f);
    glEnd();
}

void drawFloor()
{
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-10.0f, -0.5f, 10.0f);
        glVertex3f(10.0f, -0.5f, 10.0f);
        glVertex3f(10.0f, 0.0f, 10.0f);
        glVertex3f(-10.0f, 0.0f, 10.0f);


        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(10.0f, -0.5f, 10.0f);
        glVertex3f(10.0f, -0.5f, -3.0f);
        glVertex3f(10.0f, 0.0f, -3.0f);
        glVertex3f(10.0f, 0.0f, 10.0f);

        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(10.0f, -0.5f, -3.0f);
        glVertex3f(-10.0f, -0.5f, -3.0f);
        glVertex3f(-10.0f, 0.0f, -3.0f);
        glVertex3f(10.0f, 0.0f, -3.0f);

        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(-10.0f, -0.5f, -3.0f);
        glVertex3f(-10.0f, -0.5f, 10.0f);
        glVertex3f(-10.0f, 0.0f, 10.0f);
        glVertex3f(-10.0f, 0.0f, -3.0f);

        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-10.0f, 0.0f, 10.0f);
        glVertex3f(10.0f, 0.0f, 10.0f);
        glVertex3f(10.0f, 0.0f, -3.0f);
        glVertex3f(-10.0f, 0.0f, -3.0f);

        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(-10.0f, -0.5f, 10.0f);
        glVertex3f(10.0f, -0.5f, 10.0f);
        glVertex3f(10.0f, -0.5f, -3.0f);
        glVertex3f(-10.0f, -0.5f, -3.0f);


    glEnd();
}

void drawCube(float x, float y, float z)
{
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f+x, 0.0f, 0.0f);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f);
        glVertex3f(0.0f, 0.0f+y, 0.0f);



        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f+x, 0.0f, 0.0f);
        glVertex3f(0.0f+x, 0.0f, 0.0f-z);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f);
        

        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(0.0f+x, 0.0f, 0.0f-z);
        glVertex3f(0.0f, 0.0f, 0.0f-z);
        glVertex3f(0.0f, 0.0f+y, 0.0f-z);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);
        

        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f-z);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f+y, 0.0f);
        glVertex3f(0.0f, 0.0f+y, 0.0f-z);
        

        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, 0.0f+y, 0.0f);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);
        glVertex3f(0.0f, 0.0f+y, 0.0f-z);


        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f+x, 0.0f, 0.0f);
        glVertex3f(0.0f+x, 0.0f, 0.0f-z);
        glVertex3f(0.0f, 0.0f, 0.0f-z);
        


    glEnd();
}


void drawSofa()
{
    glColor3f(0.3, 0.3, 0.3);
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
    glColor3f(0.3, 0.3, 0.3);
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

void drawFanStand(float fan_height)
{
    glPushMatrix();
    drawCircle(0.2,fan_height,0.2);
    glPopMatrix();
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
    glRotatef(alpha, 0, 5, 0);
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
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[6]);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[6]);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glTranslatef(3,0,3);
   drawPreFan(fan_height);
    glTranslatef(-3,0,-3);

}




void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glFrustum(-5, 5, -4, 5, 5, 40.0);
     //gluPerspective(60,1,5,100);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    // gluLookAt(5,3, Tzval, 2,0,0, 0,1,uZ); // camera , ,
    gluLookAt(2,3,Tzval, 1.5+dx,0+dy,0+dz, 0,1,uZ); // camera , ,

   

    glViewport(0, 0, windowHeight, windowWidth);

    //glRotatef(30, 0, 0, 1 );
    //glScalef(1.5,1.5,1.5);


     glRotatef( alpha,axis_x, axis_y, 0.0 );
    //  glRotatef( theta, axis_x, axis_y, 0.0 );
  
    //   glRotatef(-90, 1, 0, 0 );

    glPushMatrix();
    drawFan(5);
    glPopMatrix();

    glPushMatrix();

    drawWall_left();
    drawWall_back();
    drawWall_right();

    glColor3f(0.5, 0, 0);
    drawFloor();

    glTranslatef(0,10.5f,0);
    drawFloor();
    glTranslatef(0,-10.5f,0);



    // glRotatef(10, 0, 1, 0 );
    
    glColor3f(0.5, 0.5, 0.5);

    glTranslatef(5,0,0);
    drawStairs();
    glTranslatef(-5,0,0);


    glColor3f(0.5, 0.5, 0.5);
    
    glRotatef(-90, 0, 1, 0 );
    glTranslatef(-2.5,0,-7.5);  
    drawStairs2();
    glTranslatef(2.5,0,7.5);
    glRotatef(90, 0, 1, 0 );

    drawMulSofa();
    glPopMatrix();

    glPushMatrix();
    drawDoor();
    glPopMatrix();


    

    //   drawFenceComp();
    //   glTranslatef(-25,0,-13);
    //   glScalef(10,10,10);
    //   glRotatef(-90, 1, 0, 0 );
    //   drawRoof();
    //   drawCube(0.7, 1.3, 1.8);

    //   // draw door
    //   glBegin(GL_QUADS);
      glColor3f(1, 1.0, 0);
    //   glVertex3f(0.5, 0, 0);
    //   glVertex3f(1, 0, 0);
    //   glVertex3f(1, 0, 1);
    //   glVertex3f(0.5, 0, 1);
    //   glEnd();
    glFlush();
    glutSwapBuffers();
}


void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case '8':
    // case 'S':
        bRotate = !bRotate;
        uRotate = false;
        axis_x=0.0;
        axis_y=1.0;
        break;

    case '7':
    // case 'R':
        uRotate = !uRotate;
        bRotate = false;
        axis_x=1.0;
        axis_y=0.0;
        break;
    case '+':
        Tzval-=0.2;
        break;

    case '-':
        Tzval+=0.2;
        break;
    case '2':
        uZ += 0.2;
        break;
    case '3':
        uZ -= 0.2;
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
        uZ+=0.2;
        break;

    case 'R':
        uZ-=0.2; 
        break;


    case 27:	// Escape key
        exit(1);
    }
}



void animate()
{
    if (bRotate == true)
    {
        theta += 0.2;
        if(theta > 360.0)
            theta -= 360.0*floor(theta/360.0);
    }

    if (uRotate == true)
    {
        alpha += 0.2;
        if(alpha > 360.0)
            alpha -= 360.0*floor(alpha/360.0);
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

    glutInitWindowPosition(0,0);
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
