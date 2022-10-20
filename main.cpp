#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include "modules.h"

using namespace std;

int windowHeight = 800;
int windowWidth = 800;


double eyex = 0, eyey = 4, eyez = 15;
double x = 0, y = 0, z = 0;
double dx = 0, dy = 0, dz = 0;
double xaxis = 0, yaxis = 1, zaxis = 0;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0, angle_x = 0.0, angle_y = 0.0;
GLboolean bRotate = false, uRotate = false, xRotate = false, yRotate = false;


float fan_height = 7.5;
float fan_angle = 1;

#define PI 3.14159265


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





void resize (int w, int h)
{
   glViewport (0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(100.0, (float)w/(float)h, 1.0, 1000.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}







void drawFloor()
{




    glEnable(GL_TEXTURE_2D);
    glPushMatrix();

            GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    // glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[0]);
    // glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[0]);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

       glTranslatef(-15,-5,5);
        glScalef(30,0.5,30);
        // drawCube(30,0.5,30);
        drawCube(1,1,1);

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}


void drawFloor2()
{
    //          GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    // GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    // //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    // GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    // GLfloat mat_shininess[] = {1000};

    // // glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[0]);
    // // glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[0]);
    // glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    // glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    for(float i = 0; i < 50; i+=0.5)
    {
        for(float j = 0; j < 50; j+=0.5)
        {
            glPushMatrix();
            glTranslatef(i,0,j);
            drawCube(0.5,0.5,0.5);
            glPopMatrix();
        }
    }
}


void drawFloor3()
{
    //          GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    // GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    // //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    // GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    // GLfloat mat_shininess[] = {60};

    // // glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[0]);
    // // glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[0]);
    // glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    // glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    for(float i = 0; i < 50; i+=0.5)
    {
        for(float j = 0; j < 50; j+=0.5)
        {
            glPushMatrix();
            glTranslatef(i,j,0);
            drawCube(0.5,0.5,0.5);
            glPopMatrix();
        }
    }
}



void drawRoom()
{
    // GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    // GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    // //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    // GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    // GLfloat mat_shininess[] = {60};

    // // glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[0]);
    // // glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[0]);
    // glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    // glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    //////glcolor3f(0.1,0.1,0.1);
    // glEnable(GL_TEXTURE_2D);
    // drawFloor2();
    // glDisable(GL_TEXTURE_2D);
    // drawFloor3();
    drawFloor();

    //////glcolor3f(0.3,0.3,0.3);
    // drawRight();
    // drawBack();
    // drawLeft();

}





////////////////// Objects drawings



GLfloat zz = 21,xx = 16, cc = 34;

float l_height = 15;
float spt_cutoff = 30;

float rot = 0;

bool l_on = true;

bool am_on = true;
bool dif_on = true;
bool spec_on = true;

float l_z = 0.2;
float l_y = 0.2;
float l_x = 0.2;
 
void light()
{
    if(l_on)
    {
        GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
        GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_position[] = { zz, xx, cc, 0.0 };
        // GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };

      

        // glEnable(GL_LIGHT0);


        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);

        // glEnable(GL_LIGHT1);

        // glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
        // glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 60.0);
    }
    else{

        // glEnable(GL_LIGHT0);

        GLfloat light_ambient_1[] = { 0.0, 0.0, 0.0, 1.0 };
        GLfloat light_diffuse_1[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_specular_1[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_position_1[] = { zz, xx, cc, 0.0 };
        // GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };

      

        // glEnable(GL_LIGHT0);


        glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient_1);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse_1);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular_1);
        glLightfv(GL_LIGHT1, GL_POSITION, light_position_1);



        glEnable(GL_LIGHT1);




        GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1 };
        GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_position[] = { zz, xx, cc, 1.0 };
        GLfloat spot_direction[] = {-1.0-l_x, -1.0-l_y, -1.0-l_z };
        float globAmb[] = { 0.05, 0.05, 0.05, 1.0 };



        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.
        glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // Enable local viewpoint.

        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
        glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, spt_cutoff);

 

        glEnable(GL_LIGHT0);

    }
    


    // GLfloat light1_ambient[] = { 0.0, 0.0, 0., 0.0 };
    // GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    // GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    // GLfloat light1_position[] = { 0.0, 7.0, 0.0, 1.0 };
    // GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };

    // glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
    // glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    // glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
    // glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    // glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);
    // glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5);
    // glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2); 

    // glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
    // glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
    // glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 5.0);

    // glEnable(GL_LIGHT1);
}










void display(){


    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt (eyex, eyey, eyez, x+dx, y+dy, z+dz, xaxis, yaxis, zaxis);

    light();
    
    // glTranslatef(0,-10,0);

    glPushMatrix();

    drawRoom();

    glPopMatrix();

    glPushMatrix();

    glutSolidSphere(1,100,100);

    glPopMatrix();


    glPushMatrix();
    glDisable(GL_LIGHTING);
    glTranslatef(zz,xx,cc);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCone(3.0 * tan( spt_cutoff/180.0 * PI ), xx+3, 20, 20);
    glEnable(GL_LIGHTING);
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

    case 't':
        l_y-=0.2;
        break;
    case 'T':
        l_y+=0.2;
        break;
    case 'g':
    // case 'G':
        l_z-=0.2;
        break;
    case 'G':
        l_z+=0.2;
        break;


    case '=':
        eyez--;
        break;
    case '-':
        eyez++;
        break;

    // //panning
    case 'P':
        cout << "zz : " << zz << endl;
        cout << "xx : " << xx << endl;
        cout << "cc : " << cc << endl;

        break;

    // case 'p':
    //     lpan+=1;
    //     rpan +=1;
    //     break;

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
        l_x-=0.2;
        break;
    case 'Y':
        l_x+=0.2;
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
        spt_cutoff+=0.2;
        break;
    case '$':
        spt_cutoff-=0.2;
        break;
    // case '5':
        // fdist +=0.5;
        // break;
    // case '%':
        // fdist -= 0.5;
        // break;
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




int main (int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize (1000, 700);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("1707119");

        glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    // light();

    GLuint texture;
    // texture= LoadTexture(1,"brick.bmp",316,316);
    texture= LoadTexture("images/p1.bmp", 2000, 1338);
    


    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(myKeyboardFunc);
    glutIdleFunc(animate);

    // glutSpecialFunc(specialKeyInput);
    glutMainLoop();







    // glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    // glutInitWindowPosition(1000,1000);
    // glutInitWindowSize(windowHeight, windowWidth);
    // glutCreateWindow("Assignment-1707119");

    // glShadeModel( GL_SMOOTH );
    // glEnable( GL_DEPTH_TEST );
    // glEnable(GL_NORMALIZE);
    // glEnable(GL_LIGHTING);


    // glutKeyboardFunc(myKeyboardFunc);
    // glutDisplayFunc(display);
    // glutReshapeFunc(resize);
    // glutMainLoop();


}