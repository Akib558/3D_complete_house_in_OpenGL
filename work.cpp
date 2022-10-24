#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include "modules.h"

#include<iostream>


#define te(x) glEnable(GL_TEXTURE_2D),glBindTexture(GL_TEXTURE_2D, x)
#define td() glDisable(GL_TEXTURE_2D)

using namespace std;

GLuint texture, texture_2;



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





bool GetImageSize(const char *fn, int *x,int *y)
{ FILE *f=fopen(fn,"rb"); if (f==0) return false;
  fseek(f,0,SEEK_END); long len=ftell(f); fseek(f,0,SEEK_SET); 
  if (len<24) {fclose(f); return false;}

  // Strategy:
  // reading GIF dimensions requires the first 10 bytes of the file
  // reading PNG dimensions requires the first 24 bytes of the file
  // reading JPEG dimensions requires scanning through jpeg chunks
  // In all formats, the file is at least 24 bytes big, so we'll read that always
  unsigned char buf[24]; fread(buf,1,24,f);

  // For JPEGs, we need to read the first 12 bytes of each chunk.
  // We'll read those 12 bytes at buf+2...buf+14, i.e. overwriting the existing buf.
  if (buf[0]==0xFF && buf[1]==0xD8 && buf[2]==0xFF && buf[3]==0xE0 && buf[6]=='J' && buf[7]=='F' && buf[8]=='I' && buf[9]=='F')
  { long pos=2;
    while (buf[2]==0xFF)
    { if (buf[3]==0xC0 || buf[3]==0xC1 || buf[3]==0xC2 || buf[3]==0xC3 || buf[3]==0xC9 || buf[3]==0xCA || buf[3]==0xCB) break;
      pos += 2+(buf[4]<<8)+buf[5];
      if (pos+12>len) break;
      fseek(f,pos,SEEK_SET); fread(buf+2,1,12,f);    
    }
  }

  fclose(f);

  // JPEG: (first two bytes of buf are first two bytes of the jpeg file; rest of buf is the DCT frame
  if (buf[0]==0xFF && buf[1]==0xD8 && buf[2]==0xFF)
  { *y = (buf[7]<<8) + buf[8];
    *x = (buf[9]<<8) + buf[10];
    return true;
  }

  // GIF: first three bytes say "GIF", next three give version number. Then dimensions
  if (buf[0]=='G' && buf[1]=='I' && buf[2]=='F')
  { *x = buf[6] + (buf[7]<<8);
    *y = buf[8] + (buf[9]<<8);
    return true;
  }

  // PNG: the first frame is by definition an IHDR frame, which gives dimensions
  if ( buf[0]==0x89 && buf[1]=='P' && buf[2]=='N' && buf[3]=='G' && buf[4]==0x0D && buf[5]==0x0A && buf[6]==0x1A && buf[7]==0x0A
    && buf[12]=='I' && buf[13]=='H' && buf[14]=='D' && buf[15]=='R')
  { *x = (buf[16]<<24) + (buf[17]<<16) + (buf[18]<<8) + (buf[19]<<0);
    *y = (buf[20]<<24) + (buf[21]<<16) + (buf[22]<<8) + (buf[23]<<0);
    return true;
  }

  return false;
}
















// GLuint LoadTexture( const char * filename, int x, int y )
// {
//   GLuint texture;
//   int width, height;
//   unsigned char * data;

//   FILE * file;
//   file = fopen( filename, "rb" );

//   if ( file == NULL ) return 0;
//   width = x;
//   height = y;
//   data = (unsigned char *)malloc( width * height * 3 );
//   //int size = fseek(file,);
//   fread( data, width * height * 3, 1, file );
//   fclose( file );

//   for(int i = 0; i < width * height ; ++i)
//   {
//     int index = i*3;
//     unsigned char B,R;
//     B = data[index];
//     R = data[index+2];

//     data[index] = R;
//     data[index+2] = B;
//   }

//   glGenTextures( 1, &texture );
//   glBindTexture( GL_TEXTURE_2D, texture );
// //   glBindTexture (GL_TEXTURE_2D, texture);
//   glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
//   glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );

//   glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
//   glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
//   glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
//   gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
//   free( data );

//   return texture;
// }




// void drawCube(float x, float y, float z)
// {
//     glBegin(GL_QUADS);
//         glNormal3f(0.0f, 0.0f, 1.0f);
//         glVertex3f(0.0f, 0.0f, 0.0f);       glTexCoord2f(1,1);
//         glVertex3f(0.0f+x, 0.0f, 0.0f);glTexCoord2f(1,0);
//         glVertex3f(0.0f+x, 0.0f+y, 0.0f);glTexCoord2f(0,0);
//         glVertex3f(0.0f, 0.0f+y, 0.0f);glTexCoord2f(0,1);



//         glNormal3f(1.0f, 0.0f, 0.0f);
//         glVertex3f(0.0f+x, 0.0f, 0.0f);glTexCoord2f(1,1);
//         glVertex3f(0.0f+x, 0.0f, 0.0f-z);glTexCoord2f(1,0);
//         glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);glTexCoord2f(0,0);
//         glVertex3f(0.0f+x, 0.0f+y, 0.0f);   glTexCoord2f(0,1);
        

//         glNormal3f(0.0f, 0.0f, -1.0f);
//         glVertex3f(0.0f+x, 0.0f, 0.0f-z); glTexCoord2f(1,1);
//         glVertex3f(0.0f, 0.0f, 0.0f-z);glTexCoord2f(1,0);
//         glVertex3f(0.0f, 0.0f+y, 0.0f-z);glTexCoord2f(0,0);
//         glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);  glTexCoord2f(0,1);
        

//         glNormal3f(-1.0f, 0.0f, 0.0f);
//         glVertex3f(0.0f, 0.0f, 0.0f-z);glTexCoord2f(1,1);
//         glVertex3f(0.0f, 0.0f, 0.0f);glTexCoord2f(1,0);
//         glVertex3f(0.0f, 0.0f+y, 0.0f);glTexCoord2f(0,0);
//         glVertex3f(0.0f, 0.0f+y, 0.0f-z);glTexCoord2f(0,1);
        

//         glNormal3f(0.0f, 1.0f, 0.0f);
//         glVertex3f(0.0f, 0.0f+y, 0.0f);glTexCoord2f(1,1);
//         glVertex3f(0.0f+x, 0.0f+y, 0.0f);glTexCoord2f(1,0);
//         glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);glTexCoord2f(0,0);
//         glVertex3f(0.0f, 0.0f+y, 0.0f-z);glTexCoord2f(0,1);


//         glNormal3f(0.0f, -1.0f, 0.0f);
//         glVertex3f(0.0f, 0.0f, 0.0f);glTexCoord2f(1,1);
//         glVertex3f(0.0f+x, 0.0f, 0.0f);glTexCoord2f(1,0);
//         glVertex3f(0.0f+x, 0.0f, 0.0f-z);glTexCoord2f(0,0);
//         glVertex3f(0.0f, 0.0f, 0.0f-z);glTexCoord2f(0,1);
        


//     glEnd();
// }


void drawFloor()
{
    

    te(texture);
    glPushMatrix();

       glTranslatef(-15,-5,5);
        glScalef(30,0.5,30);
        // drawCube(30,0.5,30);
        drawCube(1,1,1);

    glPopMatrix();
    td();
    // glDisable(GL_TEXTURE_2D);

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
    te(texture_2);
    drawRight();
    drawBack();
    drawLeft();
    td();

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
    GLfloat mat_shininess[] = {1000};

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
            // drawCube(1.2, 0.1,1);
            glScalef(1.2,0.1,1);

            drawCube(1,1,1);

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
    // GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    // GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};
    // GLfloat mat_emission[] = {0.1,0,0,1};
    GLfloat m_no[] = {0, 0, 0, 1.0};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[6]);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[6]);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, m_no);
    glTranslatef(0,0,-4);
   drawPreFan(fan_height);
    glTranslatef(0,0,4);

}

void drawStairs()
{
        for(float i = 0; i < 5; i+=0.5)
        {
            glPushMatrix();
            glTranslatef(i,0,0);
            // glScalef(1,1,3);
            drawCube(1,1+i,4);
            glPopMatrix();

        }
}



void drawGrass()
{
    GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();

        glTranslatef(-20,-10,10);
        drawCube(50,0.2,50);

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}






GLfloat zz = 0,xx = 4, cc = 0;

float l_height = 15;
float spt_cutoff = 30;

float rot = 0;

bool l_on = true;

bool am_on = true;
bool dif_on = true;
bool spec_on = true;


bool l_1 = 0;
bool l_2 = 1;
bool l_3 = 0;


float l_z = 0.2;
float l_y = 0.2;
float l_x = 0.2;
 

void light()
{
    if(l_1)
    {
        GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_diffuse[] = { 0.0, 0.0, 0.0, 1.0 };
        GLfloat light_specular[] = { 0.0, 0.0, 0.0, 1.0 };
        GLfloat light_position[] = { zz, xx, cc, 0.0 };
        // GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };

      

        // glEnable(GL_LIGHT0);


        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);

        glEnable(GL_LIGHT0);
        // glDisable(GL_LIGHT1);
        // glDisable(GL_LIGHT2);


        // glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
        // glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 60.0);
    }
    else
    {
        glDisable(GL_LIGHT0);
    }        
    if(l_2)
    {

        // glEnable(GL_LIGHT0);

        GLfloat light_ambient_1[] = { 0.0, 0.0, 0.0, 1.0 };
        GLfloat light_diffuse_1[] = { 1, 1,1, 1.0 };
        GLfloat light_specular_1[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_position_1[] = { zz, xx, cc, 0.0 };
        // GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };

      

        // glEnable(GL_LIGHT0);


        glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient_1);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse_1);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular_1);
        glLightfv(GL_LIGHT1, GL_POSITION, light_position_1);



        glEnable(GL_LIGHT1);
        // glDisable(GL_LIGHT0);
        // glDisable(GL_LIGHT2);



    }
    else{
        glDisable(GL_LIGHT1);

    }
    if(l_3)
    {


        GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1 };
        GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_position[] = { zz, xx, cc, 1.0 };
        GLfloat spot_direction[] = {0, -1.0, 0};
        float globAmb[] = { 0.05, 0.05, 0.05, 1.0 };



        glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.
        glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // Enable local viewpoint.

        glLightfv(GL_LIGHT2, GL_POSITION, light_position);
        glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
        glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, spt_cutoff);

 

        glEnable(GL_LIGHT2);
        // glDisable(GL_LIGHT0);
        // glDisable(GL_LIGHT1);



    }
    else{
        glDisable(GL_LIGHT2);

    }
    
}


float p = 1;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // glMatrixMode( GL_PROJECTION );
    // glLoadIdentity();
    // glFrustum(-5+lpan, 5+rpan, -4, 5, fdist+5, 60.0);

    // glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyex,eyey,eyez, x+dx,y+dy,z+dz, xaxis,yaxis,zaxis); // camera , ,
    glViewport(0, 0, windowHeight, windowWidth);

    //glRotatef(30, 0, 0, 1 );
    //glScalef(1.5,1.5,1.5);

    glScalef(p,p,p);

    glRotatef( angle_x,axis_x, axis_y, 0.0 );
    glRotatef( angle_y, axis_x, axis_y, 0.0 );
  
    light();
    
    // glTranslatef(0,-10,0);

    glPushMatrix();

    drawRoom();

    glPopMatrix();
    
    glPushMatrix();
        glColor3f(1,1,1);
        glTranslatef(zz,xx,cc);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,-5,-18);
    drawStairs();
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


    glPushMatrix();
    glTranslatef(7,-1,3);
   glutSolidSphere (1.0, 20, 16);

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

    case '!':
        l_1 = 1-l_1;
        break;

    case '@':
        l_2 = 1-l_2;
        break;

    case '#':
        l_3 = 1-l_3;
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
        dy++;
        break;

    case 'n':
        eyey--;
        dy--;
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
    case 'l':
        l_on = l_on-1;
        break;
    // case 'f':
    case '6':
        xRotate = !xRotate;
        yRotate = false;
        axis_x=0.0;
        axis_y=1.0;
        break;

    case '4':
        p+=0.2;
        break;
    case '$':
        p-=0.2;
    case '5':
        fdist +=0.5;
        break;
    case '%':
        fdist -= 0.5;
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

    case 'z':
        zz+=1.2;
        break;
    case 'Z':
        zz-=1.2;
        break;
    case 'x':
        xx+=1.2;
        break;
    case 'X':
        xx-=1.2;
        break;
    case 'c':
        cc+=1.2;
        break;
    case 'C':
        cc-=1.2;
        break;

    case 27:	// Escape key
        exit(1);
    }
}



void specialKeyInput(int key, int x, int y)
{
    if (key == GLUT_KEY_PAGE_DOWN)
    {
        xx-=0.5;
    }
    if( key == GLUT_KEY_PAGE_UP)
    {
        
        xx+=0.5;
    }
    if (key == GLUT_KEY_UP)
    {
        cc-=0.5;
    
    }
    if (key == GLUT_KEY_DOWN)
    {
        cc+=0.5;
    }
    if (key == GLUT_KEY_LEFT)
    {
        zz-=0.5;
    }
    if (key == GLUT_KEY_RIGHT)
    {
        zz+=0.5;
    }
    glutPostRedisplay();
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

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping area to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset the projection matrix
   if (width >= height) {
     // aspect >= 1, set the height from -1 to 1, with larger width
      gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
   } else {
      // aspect < 1, set the width to -1 to 1, with larger height
     gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
   }
}

void resize (int w, int h)
{
   glViewport (0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(100.0, (float)w/(float)h, 1.0, 1000.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
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
    // light();

    //  GLuint texture;s
    // texture= LoadTexture(1,"brick.bmp",316,316);
    texture = LoadTexture("images/p1.bmp", 2000, 1338);
    texture_2 = LoadTexture("images/wall3.bmp", 1000, 1000);

    
    glutSpecialFunc(specialKeyInput);

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    
    glutIdleFunc(animate);
    // glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}

