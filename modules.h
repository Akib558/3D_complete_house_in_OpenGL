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