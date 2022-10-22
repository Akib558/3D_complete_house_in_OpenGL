#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include<iostream>

using namespace std;


// double Txval=0,Tyval=0,Tzval=17;
double eyex = 0, eyey = 1, eyez = 20;
double x = 0, y = 0, z = 0;
double xaxis = 0, yaxis = 1, zaxis = 0;
double windowHeight=1200, windowWidth=800;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0, angle_x = 0.0, angle_y = 0.0;
GLboolean bRotate = false, uRotate = false, xRotate = false, yRotate = false;

double lpan = 0, rpan = 0, fdist = 0;
double dx = 0, dy = 0, dz = 0;






GLuint LoadTexture( const char * filename, int x, int y )
{
  GLuint texture;
  int width, height;
  unsigned char * data;

  FILE * file;
  file = fopen( filename, "rb" );

  if ( file == NULL ) return 0;
  width = x;
  height = y;
  data = (unsigned char *)malloc( width * height * 3 );
  //int size = fseek(file,);
  fread( data, width * height * 3, 1, file );
  fclose( file );

  for(int i = 0; i < width * height ; ++i)
  {
    int index = i*3;
    unsigned char B,R;
    B = data[index];
    R = data[index+2];

    data[index] = R;
    data[index+2] = B;
  }

  glGenTextures( 1, &texture );
  glBindTexture( GL_TEXTURE_2D, texture );
//   glBindTexture (GL_TEXTURE_2D, texture);
  glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );

  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
  gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
  free( data );

  return texture;
}

void drawCube(float x, float y, float z)
{
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
       
        glTexCoord2f(0,0);
            glVertex3f(0.0f, 0.0f, 0.0f);  
        glTexCoord2f(1,0);     
            glVertex3f(0.0f+x, 0.0f, 0.0f);
        glTexCoord2f(1,1);
            glVertex3f(0.0f+x, 0.0f+y, 0.0f);
        glTexCoord2f(0,1);
            glVertex3f(0.0f, 0.0f+y, 0.0f);



    glEnd();
}

void drawWall()
{
    glPushMatrix();
        drawCube(10,10,1);       
    glPopMatrix();

}

void drawWall2()
{
    glPushMatrix();
        glTranslatef(-10,0,1);
        drawCube(10,10,1);       
    glPopMatrix();

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
    glViewport(0, 0, windowHeight, windowWidth);

    glRotatef( angle_x,axis_x, axis_y, 0.0 );
    glRotatef( angle_y, axis_x, axis_y, 0.0 );


    ///////////////// draw from here

    GLuint texture;
    texture= LoadTexture("im1.bmp", 640, 640);

    glEnable(GL_TEXTURE_2D);
    drawWall();
    glDisable(GL_TEXTURE_2D);

    texture= LoadTexture("im4.bmp", 300, 300);

    glEnable(GL_TEXTURE_2D);
    drawWall2();
    glDisable(GL_TEXTURE_2D);


    //////////////// draw above this line


    glFlush();
    glutSwapBuffers();
}




void myKeyboardFunc( unsigned char key, int x, int y )
{

    cout << key << endl;
    switch ( key )
    {

    

    case '=':
        eyez--;
        break;
    case '-':
        eyez++;
        break;
    case '6':
        xRotate = !xRotate;
        yRotate = false;
        axis_x=0.0;
        axis_y=1.0;
        break;
    case '7':
        yRotate = !yRotate;
        xRotate = false;
        axis_x=1.0;
        axis_y=0.0;
        break;

    case 27:	// Escape key
        exit(1);
    }
}



void animate()
{
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







int main (int argc, char **argv)
{




    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(1000,1000);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("Assignment-1707119");


 
    

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}