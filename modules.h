#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include<iostream>



void drawCube(float x, float y, float z)
{
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);       glTexCoord2f(1,1);
        glVertex3f(0.0f+x, 0.0f, 0.0f);glTexCoord2f(1,0);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f);glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f+y, 0.0f);glTexCoord2f(0,1);



        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f+x, 0.0f, 0.0f);glTexCoord2f(1,1);
        glVertex3f(0.0f+x, 0.0f, 0.0f-z);glTexCoord2f(1,0);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);glTexCoord2f(0,0);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f);   glTexCoord2f(0,1);
        

        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(0.0f+x, 0.0f, 0.0f-z); glTexCoord2f(1,1);
        glVertex3f(0.0f, 0.0f, 0.0f-z);glTexCoord2f(1,0);
        glVertex3f(0.0f, 0.0f+y, 0.0f-z);glTexCoord2f(0,0);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);  glTexCoord2f(0,1);
        

        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f-z);glTexCoord2f(1,1);
        glVertex3f(0.0f, 0.0f, 0.0f);glTexCoord2f(1,0);
        glVertex3f(0.0f, 0.0f+y, 0.0f);glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f+y, 0.0f-z);glTexCoord2f(0,1);
        

        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, 0.0f+y, 0.0f);glTexCoord2f(1,1);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f);glTexCoord2f(1,0);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f+y, 0.0f-z);glTexCoord2f(0,1);


        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);glTexCoord2f(1,1);
        glVertex3f(0.0f+x, 0.0f, 0.0f);glTexCoord2f(1,0);
        glVertex3f(0.0f+x, 0.0f, 0.0f-z);glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f-z);glTexCoord2f(0,1);
        


    glEnd();
}



// void drawCube(float x, float y, float z)
// {
//     glBegin(GL_QUADS);
//         glNormal3f(0.0f, 0.0f, 1.0f);
//         glVertex3f(0.0f, 0.0f, 0.0f);
//         glVertex3f(0.0f+x, 0.0f, 0.0f);
//         glVertex3f(0.0f+x, 0.0f+y, 0.0f);
//         glVertex3f(0.0f, 0.0f+y, 0.0f);



//         glNormal3f(1.0f, 0.0f, 0.0f);
//         glVertex3f(0.0f+x, 0.0f, 0.0f);
//         glVertex3f(0.0f+x, 0.0f, 0.0f-z);
//         glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);
//         glVertex3f(0.0f+x, 0.0f+y, 0.0f);
        

//         glNormal3f(0.0f, 0.0f, -1.0f);
//         glVertex3f(0.0f+x, 0.0f, 0.0f-z);
//         glVertex3f(0.0f, 0.0f, 0.0f-z);
//         glVertex3f(0.0f, 0.0f+y, 0.0f-z);
//         glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);
        

//         glNormal3f(-1.0f, 0.0f, 0.0f);
//         glVertex3f(0.0f, 0.0f, 0.0f-z);
//         glVertex3f(0.0f, 0.0f, 0.0f);
//         glVertex3f(0.0f, 0.0f+y, 0.0f);
//         glVertex3f(0.0f, 0.0f+y, 0.0f-z);
        

//         glNormal3f(0.0f, 1.0f, 0.0f);
//         glVertex3f(0.0f, 0.0f+y, 0.0f);
//         glVertex3f(0.0f+x, 0.0f+y, 0.0f);
//         glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);
//         glVertex3f(0.0f, 0.0f+y, 0.0f-z);


//         glNormal3f(0.0f, -1.0f, 0.0f);
//         glVertex3f(0.0f, 0.0f, 0.0f);
//         glVertex3f(0.0f+x, 0.0f, 0.0f);
//         glVertex3f(0.0f+x, 0.0f, 0.0f-z);
//         glVertex3f(0.0f, 0.0f, 0.0f-z);
        


//     glEnd();
// }



// void drawTriangle(float x, float y, float z){

//         glBegin(GL_QUADS);

//         glNormal3f(0.0f, 0.0f, 1.0f);
//         glVertex3f(0,0,0);
//         glVertex3f(x,0,0);
//         glVertex3f(x,y,0);
//         glVertex3f(0,y,0);

//         glNormal3f(1.0f, 0.0f, 0.0f);
//         glVertex3f(x,0,0);
//         glVertex3f(x,0,-z);
//         glVertex3f(x,y,-z);
//         glVertex3f(x,y,0);

//         glNormal3f(0.0f, 1.0f, 1.0f);
//         glVertex3f(x,0,-z);
//         glVertex3f(0,0,0);
//         glVertex3f(0,y,0);
//         glVertex3f(x,y,-z);

//         glEnd();

//         glBegin(GL_TRIANGLES);

//         glNormal3f(0.0f, 1.0f, 0.0f);
//         glVertex3f(0,y,0);
//         glVertex3f(x,y,0);
//         glVertex3f(x,y,-z);

//         glNormal3f(0.0f, -1.0f, 0.0f);

//         glVertex3f(0,0,0);
//         glVertex3f(x,0,0);
//         glVertex3f(x,0,-z);

//         glEnd();
    

// }

// void drawCircle(float x, float y, float z)
// {
//     glPushMatrix();
//     for(int i = 0; i < 100; i++)
//     {
//         glRotatef(3.6,0,1,0);
//         drawTriangle(x,y,z);
//     }
    
//     glPopMatrix();
// }