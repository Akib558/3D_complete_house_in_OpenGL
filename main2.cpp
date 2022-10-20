//////////////////////////////////////////////////////////////////////////////////////        
// spotlight.cpp
//
// This program draws an array of spheres lit by a spotlight whose cone angle can be
// changed and which can be moved as well. The spotlight cone is shown by a wireframe.
// The spheres are colored using color material mode.
//
// Interaction:
// Press the page up/down keys to increase/decrease the spotlight cone angle.
// Press the arrow keys to move the spotlight.
// Press 't/T' to decrease/increase the spotlight's attenuation.
//
// Sumanta Guha.
//////////////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "modules.h"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define PI 3.14159265

using namespace std;

// Globals.
static float spotAngle = 10.0; // Spotlight cone half-angle.
static float xMove = 0.0, zMove = 0.0; // Movement components.
static float spotExponent = 2.0; // Spotlight exponent = attenuation.
static char theStringBuffer[10]; // String buffer.
static long font = (long)GLUT_BITMAP_8_BY_13; // Font selection.



void drawScene()
{

   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glLoadIdentity();

   gluLookAt (0.0, 4.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


    drawCube(2,2,2);

   
   glutSwapBuffers();
}

// OpenGL window reshape routine.
void resize (int w, int h)
{
   glViewport (0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(150.0, (float)w/(float)h, 1.0, 100.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
   switch (key) 
   {
      case 27:
         exit(0);
         break;
	  case 't':
 		 if (spotExponent > 0.0) spotExponent -= 0.1;
         glutPostRedisplay();
		 break;
	  case 'T':
 		 spotExponent += 0.1;
         glutPostRedisplay();
		 break;
      default:
         break;
   }
}

// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
   if (key == GLUT_KEY_PAGE_DOWN)
   {
      if (spotAngle > 0.0) spotAngle -= 1.0;
   }
   if( key == GLUT_KEY_PAGE_UP)
   {
      if (spotAngle < 90.0) spotAngle += 1.0;
   }
   if (key == GLUT_KEY_UP)
   {
      if (zMove > -4.0) zMove -= 0.1;
   }
   if (key == GLUT_KEY_DOWN)
   {
      if (zMove < 4.0) zMove += 0.1;
   }
   if (key == GLUT_KEY_LEFT)
   {
      if (xMove > -4.0) xMove -= 0.1;
   }
   if (key == GLUT_KEY_RIGHT)
   {
      if (xMove < 4.0) xMove += 0.1;
   }
   glutPostRedisplay();
}



// Main routine.
int main(int argc, char **argv) 
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
   glutInitWindowSize (1000, 700);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("spotlight.cpp");

   glutDisplayFunc(drawScene);
   glutReshapeFunc(resize);
   glutKeyboardFunc(keyInput);
   glutSpecialFunc(specialKeyInput);
   glutMainLoop();
   
   return 0;
}
